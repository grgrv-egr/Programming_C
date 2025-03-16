#include <stdio.h>

void selectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[k]) {
                k = j;
            }
        }
        if (k != i) {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}

int main() {
    int arr[] = {4, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    return 0;
}

#комментарий
# еще комментарий
