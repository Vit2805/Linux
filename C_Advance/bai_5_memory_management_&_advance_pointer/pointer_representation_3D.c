#include <stdio.h>

int arr3D[2][3][4]; // A 3D array
int (*ptr3D)[3][4] = arr3D; // Pointer to a 2D array of 3 rows and 4 columns
int value = *(*(*(ptr3D + 1) + 2) + 3); // Access arr3D[1][2][3]