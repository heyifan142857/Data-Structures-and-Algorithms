#include <iostream>

void merge(int arr[], int left, int mid, int right, int temp[], long long& count) {
    int i = left, j = mid + 1, k = left;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid - i + 1);
        }
    }
  
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    
    for (int p = left; p <= right; ++p) {
        arr[p] = temp[p];
    }
}


void mergeSort(int arr[], int left, int right, int temp[], long long& count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, temp, count);
        mergeSort(arr, mid + 1, right, temp, count);
        merge(arr, left, mid, right, temp, count);
    }
}


long long countInversions(int arr[], int arr_size) {
    int temp[arr_size];
    long long count = 0;
    mergeSort(arr, 0, arr_size - 1, temp, count);
    return count;
}

int main() {
    int N;
    std::cin >> N;
    int arr[N];

    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    long long num = countInversions(arr,N);
    std::cout << num << std::endl;

    return 0;
}