#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void reorderArray(int *dataArray, int arraySize) {
    qsort(dataArray, arraySize, sizeof(int), compare);
    int midIndex = (arraySize + 1) / 2 - 1;
    swap(&dataArray[midIndex], &dataArray[arraySize - 1]);
    int startIndex = midIndex + 1;
    int endIndex = arraySize - 2;
    while (startIndex <= endIndex) {
        swap(&dataArray[startIndex], &dataArray[endIndex]);
        startIndex = startIndex + 1;
        endIndex = endIndex - 1;
    }
    for (int i = 0; i < arraySize; i++) {
        printf("%d", dataArray[i]);
        if (i < arraySize - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int numberOfCases;
    scanf("%d", &numberOfCases);
    for (int i = 0; i < numberOfCases; i++) {
        int arraySize;
        scanf("%d", &arraySize);
        int *dataArray = (int *)malloc(arraySize * sizeof(int));
        for (int j = 0; j < arraySize; j++) {
            scanf("%d", &dataArray[j]);
        }
        reorderArray(dataArray, arraySize);
        free(dataArray);
    }
    return 0;
}
