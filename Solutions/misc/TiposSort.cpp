#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void BubbleSort(std::vector<int> &Vet, int N){
    for (int i = N - 1; i >= 0; --i){
        int Count = 0;
        for (int j = 0; j < i; ++j){
            if (Vet[j] > Vet[j + 1]){
                std::swap(Vet[j + 1], Vet[j]);
                ++Count;
            }
        }
        if (!Count) return;
    }
}

void BubbleSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet = VetRand;
    auto t1 = clock();
    BubbleSort(Vet, tam);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    BubbleSort(Vet, tam);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    BubbleSort(Vet, tam);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Bubble Sort  " << std::setw(15) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

void InsertionSort(std::vector<int> &Vet, int N){
    for (int i = 1; i < N; ++i){
        int pivot = Vet[i];
        int j = i - 1;
        while(j >= 0 && Vet[j] > pivot){
            Vet[j + 1] = Vet[j];
            --j;
        }
        Vet[j + 1] = pivot;
    }
}

void InsertionSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet = VetRand;
    auto t1 = clock();
    InsertionSort(Vet, tam);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    InsertionSort(Vet, tam);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    InsertionSort(Vet, tam);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Insertion Sort" << std::setw(14) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

void SelectionSort(std::vector<int> &Vet, int N){
    for (int i = N - 1; i >= 0; --i){
        int pivot = i;
        for (int j = i - 1; j >= 0; --j)
            if (Vet[pivot] < Vet[j])
                pivot = j;
        std::swap(Vet[pivot], Vet[i]);
    }
}

void SelectionSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet = VetRand;
    auto t1 = clock();
    SelectionSort(Vet, tam);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    SelectionSort(Vet, tam);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    SelectionSort(Vet, tam);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Selection Sort" << std::setw(14) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

void Merge(std::vector<int> &Vet, int l, int m, int r){
    int left = m - l + 1, right = r - m;
    int VetL[left], VetR[right], i, j, k;
    for (i = 0; i < left; ++i)
        VetL[i] = Vet[l + i];
    for (j = 0; j < right; ++j)
        VetR[j] = Vet[m + j + 1];
    i = j = 0;
    k = l;
    while(i < left && j < right){
        if (VetL[i] <= VetR[j])
            Vet[k++] = VetL[i++];
        else
            Vet[k++] = VetR[j++];
    }
    while(i < left)
        Vet[k++] = VetL[i++];
    while(j < right)
        Vet[k++] = VetR[j++];
}

void MergeSort(std::vector<int> &Vet, int l, int r){
    if (l >= r) return;
    int Mid = l + (r - l) / 2;
    MergeSort(Vet, l, Mid);
    MergeSort(Vet, Mid + 1, r);
    Merge(Vet, l, Mid, r);
}

void MergeSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet = VetRand;
    auto t1 = clock();
    MergeSort(Vet, 0, tam - 1);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    MergeSort(Vet, 0, tam - 1);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    MergeSort(Vet, 0, tam - 1);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Merge Sort   " << std::setw(15) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

int Partition(std::vector<int> &Vet, int l, int r){
    int pivot = Vet[r];
    int i = l - 1;

    for (int j = l; j < r; ++j){
        if (Vet[j] < pivot){
            ++i;
            std::swap(Vet[i], Vet[j]);
        }
    }

    std::swap(Vet[i + 1], Vet[r]);
    return i + 1;
}

int RandPartition(std::vector<int> &Vet, int l, int r){
    std::srand(time(NULL));
    int random = l + rand() % (r - l);
    std::swap(Vet[random], Vet[r]);
    return Partition(Vet, l, r);
}

void QuickSort(std::vector<int> &Vet, int l, int r){
    if (l >= r) return;
    int pi = RandPartition(Vet, l, r);
    QuickSort(Vet, l, pi - 1);
    QuickSort(Vet, pi + 1, r);
}

void QuickSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet = VetRand;
    auto t1 = clock();
    QuickSort(Vet, 0, tam - 1);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    QuickSort(Vet, 0, tam - 1);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    QuickSort(Vet, 0, tam - 1);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Quick Sort   " << std::setw(15) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

void Heapify(std::vector<int> &Vet, int N, int id = 0){
    int l = 2 * id + 1, highest = id;
    int r = l + 1;
    if (l >= N) return;
    if (Vet[l] > Vet[highest]) highest = l;
    if (r < N && Vet[r] > Vet[highest]) highest = r;
    if (highest != id){
        std::swap(Vet[id], Vet[highest]);
        Heapify(Vet, N, highest);
    }
}

void HeapSort(std::vector<int> &Vet, int N){
    for (int i = N/2 - 1; i >= 0; --i)
        Heapify(Vet, N, i);
    for (int i = N - 1; i > 0; --i){
        std::swap(Vet[0], Vet[i]);
        Heapify(Vet, i, 0);
    }
}

void HeapSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet.resize(tam);
    std::srand(unsigned(std::time(nullptr)));
    std::generate(Vet.begin(), Vet.end(), std::rand);
    auto t1 = clock();
    HeapSort(Vet, tam);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    HeapSort(Vet, tam);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    HeapSort(Vet, tam);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Heap Sort   " << std::setw(16) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

void CountingSort(std::vector<int> &Vet, int N){
    int Maior = -1;
    for (int i = 0; i < N; ++i)
        Maior = std::max(Vet[i], Maior);
    std::vector<int> Count(Maior + 1, 0), Temp(N);
    for (int i : Vet)
        ++Count[i];
    for (int i = 1; i <= Maior; ++i)
        Count[i] += Count[i - 1];
    for (int i = N - 1; i >= 0; --i)
        Temp[--Count[Vet[i]]] = Vet[i];
    Vet = Temp;
}

void CountingSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
	Vet = VetRand;
    auto t1 = clock();
    CountingSort(Vet, tam);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    CountingSort(Vet, tam);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    CountingSort(Vet, tam);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Counting Sort" << std::setw(15) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

void CountingSort(std::vector<int> &Vet, int N, int h){
    std::vector<int> Count(10, 0), Temp(N);
    for (int i : Vet)
        ++Count[(i / h) % 10];
    for (int i = 1; i <= 9; ++i)
        Count[i] += Count[i - 1];
    for (int i = N - 1; i >= 0; --i)
        Temp[--Count[(Vet[i] / h) % 10]] = Vet[i];
    Vet = Temp;
}

void RadixSort(std::vector<int> &Vet, int N){
    int Maior = -1;
    for (int i : Vet)
        Maior = std::max(i, Maior);
    for (int i = 1; Maior / i; i *= 10)
        CountingSort(Vet, N, i);
}

void RadixSortPrint(std::vector<int> &Vet, std::vector<int> &VetRand, int tam){
    Vet.resize(tam);
    Vet = VetRand;
    auto t1 = clock();
    RadixSort(Vet, tam);
    auto t2 = clock();
    auto tf1 = t2 - t1;

    Vet.resize(tam);
    for(int i = 0; i < tam; ++i) Vet[i] = i + 1;
    auto t3 = clock();
    RadixSort(Vet, tam);
    auto t4 = clock();
    auto tf2 = t4 - t3;

    Vet.resize(tam);
    for(int i = tam; i; --i) Vet[tam - i] = i;
    auto t5 = clock();
    RadixSort(Vet, tam);
    auto t6 = clock();
    auto tf3 = t6 - t5;

    std::cout << "Radix Sort   " << std::setw(15) << (double)tf1/CLOCKS_PER_SEC << std::setw(15) << (double)tf2/CLOCKS_PER_SEC << std::setw(15) << (double)tf3/CLOCKS_PER_SEC << '\n';
}

int main(){
    int tam;
	freopen("input.txt", "r", stdin);
	freopen("outputtrab.txt", "w", stdout);

    while(std::cin >> tam){
        std::cout << std::setw(25) << tam << " elementos\n";
        std::vector<int> Vet, VetRand(tam);
        std::srand(unsigned(std::time(nullptr)));
        for(int i = 0; i < tam; ++i) VetRand[i] = std::rand() % tam;
        std::cout << "Tipo de sort " << std::setw(15) << "rand" << std::setw(15) << "cres" << std::setw(15) << "decr\n";
        std::cout << std::fixed << std::setprecision(6);
        std::cout << std::right;
		if (tam <= 100000){
			BubbleSortPrint(Vet, VetRand, tam);
			InsertionSortPrint(Vet, VetRand, tam);
			SelectionSortPrint(Vet, VetRand, tam);
		}
        MergeSortPrint(Vet, VetRand, tam);
        QuickSortPrint(Vet, VetRand, tam);
        HeapSortPrint(Vet, VetRand, tam);
        CountingSortPrint(Vet, VetRand, tam);
        RadixSortPrint(Vet, VetRand, tam);

        std::cout << std::setfill('-') << std::setw(60) << "-\n";
        std::cout << std::setfill(' ');
    }

    return 0;
}
