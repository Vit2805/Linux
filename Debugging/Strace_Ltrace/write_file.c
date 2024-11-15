#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Starting program\n");

    int num;
    FILE *file_ptr;
    
    file_ptr = fopen("my_output.txt", "w");

    if(file_ptr == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    fprintf(file_ptr, "Hello world!\n");
    fclose(file_ptr);

    printf("Done! \n");
    return 0;
}