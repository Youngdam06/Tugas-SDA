#include <iostream>
using namespace std;

// Fungsi untuk menukar dua nilai
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk membagi array (partition)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot-nya ambil elemen paling kanan
    int i = low - 1; // posisi elemen yang lebih kecil dari pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Taruh pivot ke posisi yang benar
    swap(arr[i + 1], arr[high]);
    return i + 1; // kembalikan indeks pivot yang baru
}

// Fungsi Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Bagi array jadi dua bagian
        int pi = partition(arr, low, high);

        // Rekursif ke kiri dan kanan pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi buat nampilin array
void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Program utama
int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int ukuran = sizeof(data) / sizeof(data[0]);

    cout << "Sebelum diurutkan: ";
    tampilkanArray(data, ukuran);

    quickSort(data, 0, ukuran - 1);

    cout << "Setelah diurutkan: ";
    tampilkanArray(data, ukuran);

    return 0;
}
