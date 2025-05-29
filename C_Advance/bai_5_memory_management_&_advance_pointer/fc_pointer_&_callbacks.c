#include <stdio.h>
// Callback function for comparison
int compare(int a, int b) {
return a - b;}
 // A function that takes a callback
void sort(int *arr, int size, int (*cmp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (cmp(arr[i], arr[j]) > 0) { // Use the callback function
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
        } 
        } 
    }
}
int main() {
    int numbers[] = {4, 2, 3, 1};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    sort(numbers, size, compare);
    for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]); // Output: 1 2 3 4 
    }
return 0;}