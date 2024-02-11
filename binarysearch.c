#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target is present at the middle
        if (arr[mid] == target)
            return mid;

        // If the target is greater, search in the right half
        if (arr[mid] < target)
            return binarySearch(arr, mid + 1, right, target);

        // If the target is smaller, search in the left half
        return binarySearch(arr, left, mid - 1, target);
    }

    // If the target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 18, 20};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = binarySearch(arr, 0, arr_size - 1, target);

    if (result != -1)
        printf("Element %d is present at index %d\n", target, result);
    else
        printf("Element %d is not present in the array\n", target);

    return 0;
}
