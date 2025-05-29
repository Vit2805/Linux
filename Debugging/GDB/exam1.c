#include <stdio.h>

void print(int i){
	printf("Xin chao, Vit %d! \n", i);
}
int main(){
	for(int i = 1; i < 3; i++){
		print(i);
	}
}