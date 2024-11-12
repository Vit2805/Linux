#include <stdio.h>

int main(int argc, char const *argv[]){
	if(1 >= argc){
		printf("usage: hello name\n ");
		return 0;
	}
	printf("hello, Vit %s\n", argv[1]);
	return 0;
}