// Aim: To implement Merge Sort, Quick Sort, Bubble Sort, Selection Sort and Heap Sort using array as a data structure and analyse their time complexity.

#include <stdio.h>

void merge(int arr[], int l, int r, int m) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for(j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, r, m);
    }
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for(int j = low; j < high; j++) {
            if(arr[j] <= pivot) {
                i++;

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pivotIndex = i + 1;

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void selectionSort(int arr[], int len) {
    for(int i = 0; i < len - 1; i++) {
        int min = i;

        for(int j = i+1; j < len; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubbleSort(int arr[], int len) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void heapify(int arr[], int len, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < len && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < len && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, len, largest);
    }
}

void heapSort(int arr[], int len) {
    for(int i = len / 2 - 1; i >= 0; i--) {
        heapify(arr, len, i);
    }

    for(int i = len - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArr(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int arr1[] = {12, 4267, 4242, 44, 88, 12321, 899, 424, 4224, 1221, 1, 1, 1, 2};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);

    printf("----- Merge Sort -----\n");
    printf("Original Array - ");
    printArr(arr1, len1);

    mergeSort(arr1, 0, len1 - 1);

    printf("Sorted Array - ");
    printArr(arr1, len1);



    int arr2[] = {1223, 2, 42, 123, 1, 0, 99, 88, 34, 43, 122, 12};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    printf("\n----- Quick Sort -----\n");
    printf("Original Array - ");
    printArr(arr2, len2);

    quickSort(arr2, 0, len2 - 1);

    printf("Sorted Array - ");
    printArr(arr2, len2);



    int arr3[] = {123, 442, 42, 55, 1, 65, 99};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);

    printf("\n----- Selection Sort -----\n");
    printf("Original Array - ");
    printArr(arr3, len3);

    selectionSort(arr3, len3);

    printf("Sorted Array - ");
    printArr(arr3, len3);



    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int len4 = sizeof(arr4) / sizeof(arr4[0]);

    printf("\n----- Bubble Sort -----\n");
    printf("Original Array - ");
    printArr(arr4, len4);

    bubbleSort(arr4, len4);

    printf("Sorted Array - ");
    printArr(arr4, len4);



    int arr5[] = {12, 11, 13, 5, 6, 7};
    int len5 = sizeof(arr5) / sizeof(arr5[0]);

    printf("\n----- Heap Sort -----\n");
    printf("Original Array - ");
    printArr(arr5, len5);

    heapSort(arr5, len5);

    printf("Sorted Array - ");
    printArr(arr5, len5);

    return 0;
}
