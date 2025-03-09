void selectSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].total > arr[k].total) {
                k = j;
            }
        }
        if (k != i) {
            struct Student temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
    }
}
#комментарий
