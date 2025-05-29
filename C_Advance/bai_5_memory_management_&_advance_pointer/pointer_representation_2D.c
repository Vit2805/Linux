#include <stdio.h>

int main(){
int arr[3][4] =
{{0,1,2,3 },{4,5,6,7},{8,9,10,11}}; // A 2D array with 3 rows and 4 columns
int (*ptr)[4]; //Pointer to an array of 4 integers

ptr = arr; //Point to the fist row of the array

for(int i = 0; i<3; i++){
    for(int j = 0; j < 4; j++){
        printf("%d ", *(*(ptr + i) + j)); //Access element at a[i][j]
    }
    printf("\n");
}
}

