#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
#include <ifaddrs.h>  

#define MAX_CONNECTIONS 10  
#define BUFFER_SIZE 1024  

typedef struct {  
    int socket_fd;  
    struct sockaddr_in address;  
} Connection;  

Connection connections[MAX_CONNECTIONS];  
int connection_count = 0;  

void handleError(const char *errorMessage) {  
    perror(errorMessage);  
    exit(EXIT_FAILURE);  
}  

// Get the actual IP address of the machine  
char* getMyIPAddress() {  
    struct ifaddrs *ifaddr, *ifa;  
    static char ip[INET_ADDRSTRLEN];  

    if (getifaddrs(&ifaddr) == -1) {  
        handleError("getifaddrs error");  
    }  

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {  
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {  
            if (strcmp(ifa->ifa_name, "lo") != 0) { // Ignore loopback  
                inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, ip, sizeof(ip));  
                break;  
            }  
        }  
    }  

    freeifaddrs(ifaddr);  
    return ip;  
}  

// Create socket and bind to specified port  
int createSocket(int port) {  
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);  
    if (sockfd == -1) {  
        handleError("Failed to create socket");  
    }  

    struct sockaddr_in serverAddress;  
    serverAddress.sin_family = AF_INET;  
    serverAddress.sin_addr.s_addr = INADDR_ANY;  
    serverAddress.sin_port = htons(port);  

    if (bind(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {  
        handleError("Failed to bind socket");  
    }  

    if (listen(sockfd, MAX_CONNECTIONS) == -1) {  
        handleError("Failed to listen on socket");  
    }  

    return sockfd;  
}  

// Accept a new connection  
Connection acceptConnection(int serverSocket) {  
    Connection conn;  
    socklen_t addrlen = sizeof(conn.address);  
    conn.socket_fd = accept(serverSocket, (struct sockaddr *)&conn.address, &addrlen);  
    if (conn.socket_fd == -1) {  
        handleError("Failed to accept connection");  
    }  
    return conn;  
}  

// Send a message  
void sendMessage(int socket, const char *message) {  
    send(socket, message, strlen(message), 0);  
}  

// Receive messages  
void receiveMessages(int socket) {  
    char buffer[BUFFER_SIZE];  
    int bytesReceived;  

    while ((bytesReceived = recv(socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {  
        buffer[bytesReceived] = '\0';  
        printf("Message received: %s\n", buffer); // Handle this in the main function below  
    }  
}  

// List all connections  
void listConnections() {  
    printf("Connections:\n");  
    for (int i = 0; i < connection_count; i++) {  
        printf("%d: %s:%d\n", i + 1,  
               inet_ntoa(connections[i].address.sin_addr),  
               ntohs(connections[i].address.sin_port));  
    }  
}  

// Validate IP address format  
int isValidIP(const char *ip) {  
    struct sockaddr_in sa;  
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;  
}  

// Handle commands  
void handleCommand(char *command, int serverSocket) {  
    char *token;  
    char *source = command;  
    token = strtok(source, " ");  
    
    if (strcmp(token, "help") == 0) {  
        printf("Available commands:\n");  
        printf("1. help - Display user interface options\n");  
        printf("2. myip - Display this process IP address\n");  
        printf("3. myport - Display this process listening port\n");  
        printf("4. connect <destination> <port no> - Establish connection\n");  
        printf("5. list - List all connections\n");  
        printf("6. terminate <connection id> - Terminate connection\n");  
        printf("7. send <connection id> <message> - Send message\n");  
        printf("8. exit - Exit the application\n");  
    } else if (strcmp(token, "myip") == 0) {  
        printf("My IP Address: %s\n", getMyIPAddress());  
    } else if (strcmp(token, "myport") == 0) {  
        // Print the port number (assuming default 8080)  
        printf("Listening on port: 8080\n");  
    } else if (strcmp(token, "connect") == 0) {  
        char *destination = strtok(NULL, " ");  
        char *portStr = strtok(NULL, " ");  
        if (destination && portStr) {  
            int port = atoi(portStr);  
            if (!isValidIP(destination)) {  
                printf("Invalid IP address\n");  
                return;  
            }  
            // Create a client socket to connect to destination  
            int clientSocket = socket(AF_INET, SOCK_STREAM, 0);  
            if (clientSocket == -1) {  
                handleError("Failed to create client socket");  
            }  

            struct sockaddr_in serverAddress;  
            serverAddress.sin_family = AF_INET;  
            inet_pton(AF_INET, destination, &serverAddress.sin_addr);  
            serverAddress.sin_port = htons(port);  

            if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {  
                printf("Failed to connect to %s:%d\n", destination, port);  
                return;  
            }  

            // Add the new connection to the list  
            if (connection_count < MAX_CONNECTIONS) {  
                connections[connection_count].socket_fd = clientSocket;  
                connections[connection_count].address = serverAddress;  
                connection_count++;  
                printf("Connected to %s:%d\n", destination, port);  
            } else {  
                printf("Max connections reached\n");  
                close(clientSocket);  
            }  
        }  
    } else if (strcmp(token, "list") == 0) {  
        listConnections();  
    } else if (strcmp(token, "terminate") == 0) {  
        char *idStr = strtok(NULL, " ");  
        if (idStr) {  
            int id = atoi(idStr) - 1;  
            if (id >= 0 && id < connection_count) {  
                close(connections[id].socket_fd);  
                printf("Connection terminated: %s:%d\n",   
                       inet_ntoa(connections[id].address.sin_addr),   
                       ntohs(connections[id].address.sin_port));  
                for (int i = id; i < connection_count - 1; i++) {  
                    connections[i] = connections[i + 1];  
                }  
                connection_count--;  
            } else {  
                printf("Invalid connection id\n");  
            }  
        }  
    } else if (strcmp(token, "send") == 0) {  
        char *idStr = strtok(NULL, " ");  
        char *message = strtok(NULL, "");  
        if (idStr && message) {  
            int id = atoi(idStr) - 1;  
            if (id >= 0 && id < connection_count) {  
                sendMessage(connections[id].socket_fd, message);  
                printf("Message sent to connection %d\n", id + 1);  
            } else {  
                printf("Invalid connection id\n");  
            }  
        }  
    } else if (strcmp(token, "exit") == 0) {  
        // Close all connections  
        for (int i = 0; i < connection_count; i++) {  
            close(connections[i].socket_fd);  
        }  
        exit(0);  
    } else {  
        printf("Unknown command: %s\n", token);  
    }  
}  

int main() {  
    int serverSocket = createSocket(8080);  
    printf("Server listening on port 8080\n");  

    while (1) {  
        // Check for new connections  
        Connection newConn = acceptConnection(serverSocket);  
        printf("Client connected: %s:%d\n",   
               inet_ntoa(newConn.address.sin_addr),   
               ntohs(newConn.address.sin_port));  
        
        // Add to the connections list  
        if (connection_count < MAX_CONNECTIONS) {  
            connections[connection_count++] = newConn;  
        }  

        // Start a new thread/process to handle the connection receiving messages  
        if (fork() == 0) {  
            close(serverSocket); // Close the server socket in the child process  
            
            // Start receiving messages  
            receiveMessages(newConn.socket_fd);  
            close(newConn.socket_fd);  
            exit(0);  
        }  
        
        // Handle commands from the main process  
        char command[BUFFER_SIZE];  
        printf("Enter command: ");  
        fgets(command, sizeof(command), stdin);  
        command[strcspn(command, "\n")] = 0; // Remove newline character  
        handleCommand(command, serverSocket);  
    }  

    // Clean up  
    close(serverSocket);  
    return 0;  
}