#include <iostream>
using namespace std;

// Fungsi untuk menukar dua nilai
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indeksMin = i;

        // Cari nilai terkecil di sisa array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[indeksMin]) {
                indeksMin = j;
            }
        }

        // Kalau ditemukan nilai yang lebih kecil, tukar posisinya
        if (indeksMin != i) {
            swap(arr[i], arr[indeksMin]);
        }
    }
}

// Fungsi untuk menampilkan array
void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Program utama
int main() {
    int data[] = {29, 10, 14, 37, 4};
    int ukuran = sizeof(data) / sizeof(data[0]);

    cout << "Sebelum diurutkan: ";
    tampilkanArray(data, ukuran);

    selectionSort(data, ukuran);

    cout << "Setelah diurutkan: ";
    tampilkanArray(data, ukuran);

    return 0;
}
