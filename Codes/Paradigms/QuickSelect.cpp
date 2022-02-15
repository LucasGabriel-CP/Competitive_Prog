#include <bits/stdc++.h>

using namespace std;

int Partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++){
        if (arr[j] >= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int RandPartition(int arr[], int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return Partition(arr, low, high);
}

int QuickSelect(int A[], int k, int l, int r){
    if (l == r) return A[l];
    int id = RandPartition(A, l, r);

    if (id + 1 == k) return A[id];
    if (id + 1 > k) return QuickSelect(A, k, l, id - 1);
    else return QuickSelect(A, k, id + 1, r);

    return id;
}
