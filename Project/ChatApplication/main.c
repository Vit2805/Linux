#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>   //Chức cấu trúc dữ liệu cần thiết cho Socket  
#include <netinet/in.h>   // Thư viện chứa các hằng số, cấu trúc khi sử dụng địa chỉ trên internet
#include <arpa/inet.h>
#include <unistd.h> 

#define LISTEN_BACKLOG 10  
#define BUFFER_SIZE 1024  
#define handle_error(msg) \ 
    do { perror(msg); exit(EXIT_FAILURE);} while(0)

typedef struct {  
    int socket_fd;  
    struct sockaddr_in address;  
} Connection;  

Connection connections[LISTEN_BACKLOG];  
int connection_count = 0;  

//Hàm Help()
void help(){
    printf("Available commands:\n");  
    printf("1. help - Display user interface options\n");  
    printf("2. myip - Display this process IP address\n");  
    printf("3. myport - Display this process listening port\n");  
    printf("4. connect <destination> <port no> - Establish connection\n");  
    printf("5. list - List all connections\n");  
    printf("6. terminate <connection id> - Terminate connection\n");  
    printf("7. send <connection id> <message> - Send message\n");  
    printf("8. exit - Exit the application\n");
}
//Hàm lấy địa chỉ IP 
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
    //Giá trị trả về là IP của người dùng 
    return ip;  
}

//Hàm tạo Socket và Bind 
int createSocket(int port) {  
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);  
    if (sock_fd == -1) {  
        handleError("Failed to create socket");  
    }  

    struct sockaddr_in serverAddress;  
    serverAddress.sin_family = AF_INET;  
    serverAddress.sin_addr.s_addr = INADDR_ANY;  
    serverAddress.sin_port = htons(port);  

    if (bind(sock_fd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {  
        handleError("Failed to bind socket");  
    }  

    if (listen(sock_fd, MAX_CONNECTIONS) == -1) {  
        handleError("Failed to listen on socket");  
    }  

    return sock_fd;  
}

//Hàm acceptConnection
Connection acceptConnection(int new_socket_fd) {  
    Connection conn;  
    socklen_t addrlen = sizeof(conn.address);  
    conn.socket_fd = accept(new_socket_fd, (struct sockaddr *)&conn.address, &addrlen);  
    if (conn.socket_fd == -1) {  
        handleError("Failed to accept connection");  
    }  
    return conn;  
}

//Hàm gửi tin nhắn 
void sendMessage(int new_socket_fd, const char *message) {
    Printf("Send a message to : ");  
    send(new_socket_fd, message, strlen(message), 0);  
}

//Hàm nhận tin nhắn
void receiveMessages(int new_socket_fd) {  
    char buffer[BUFFER_SIZE];  
    int bytesReceived;  

    while ((bytesReceived = recv(new_socket_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {  
        buffer[bytesReceived] = '\0';  
        printf("Message received: %s\n", buffer); // Handle this in the main function below  
    }  
}









