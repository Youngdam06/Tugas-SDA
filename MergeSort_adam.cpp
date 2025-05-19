#include <iostream>
using namespace std;

// Fungsi buat ngegabungin dua array yang udah diurutkan
void merge(int arr[], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    // Bikin array sementara
    int L[n1], R[n2];

    // Isi array sementara dari arr utama
    for (int i = 0; i < n1; i++)
        L[i] = arr[kiri + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[tengah + 1 + j];

    // Gabungin kedua array sementara ke arr utama
    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen (kalau ada) dari L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen (kalau ada) dari R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi Merge Sort
void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        // Urutin bagian kiri dan kanan dulu
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);

        // Gabungin hasilnya
        merge(arr, kiri, tengah, kanan);
    }
}

// Fungsi buat nampilin array
void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Program utama
int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int ukuran = sizeof(data) / sizeof(data[0]);

    cout << "Sebelum diurutkan: ";
    tampilkanArray(data, ukuran);

    mergeSort(data, 0, ukuran - 1);

    cout << "Setelah diurutkan: ";
    tampilkanArray(data, ukuran);

    return 0;
}
