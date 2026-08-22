#include <stdio.h>

int sequentialSearch(int arr[], int len, int target) {
    for(int i = 0; i < len; i++) {
        if(arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int len, int target) {
    int left = 0;
    int right = len - 1;

    while(left <= right) {
        int middle = left + (right - left) / 2;

        if(arr[middle] == target) {
            return middle;
        }

        if(target < arr[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return -1;
}

void printArr(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr1[] = {42, 17, 89, 3, 55, 21, 76};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);

    int target1 = 55;

    printf("----- Sequential Search -----\n");

    printf("Array - ");
    printArr(arr1, len1);

    printf("Searching for %d...\n", target1);

    int result1 = sequentialSearch(arr1, len1, target1);

    if(result1 != -1) {
        printf("Element found at index %d\n", result1);
    } else {
        printf("Element not found\n");
    }


    int arr2[] = {3, 17, 21, 42, 55, 76, 89};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    int target2 = 55;

    printf("\n----- Binary Search -----\n");

    printf("Sorted Array - ");
    printArr(arr2, len2);

    printf("Searching for %d...\n", target2);

    int result2 = binarySearch(arr2, len2, target2);

    if(result2 != -1) {
        printf("Element found at index %d\n", result2);
    } else {
        printf("Element not found\n");
    }

    return 0;
}