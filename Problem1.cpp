#include <iostream>
using namespace std;

void geserHapus(int arr[], int &ukuran, int idx) {
    for (int i = idx; i < ukuran - 1; i++) {
        arr[i] = arr[i + 1];
    }
    ukuran--;
}

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    const int MAX = 1000;
    int lingkaran[MAX];
    int urutanEliminasi[MAX];
    int jumlahEliminasi = 0;

    for (int i = 0; i < N; i++) {
        lingkaran[i] = i + 1;
    }
    int ukuran = N;
    int posisi = 0;

    while (ukuran > 1) {
        int idx = (posisi + K - 1) % ukuran;
        int astronot = lingkaran[idx];

        urutanEliminasi[jumlahEliminasi] = astronot;
        jumlahEliminasi++;

        geserHapus(lingkaran, ukuran, idx);

        if (astronot % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }

        if (ukuran > 0) {
            posisi = idx % ukuran;
        }
    }

    cout << "\nUrutan astronot yang tereliminasi: ";
    for (int i = 0; i < jumlahEliminasi; i++) {
        cout << urutanEliminasi[i];
        if (i != jumlahEliminasi - 1) cout << ", ";
    }
    cout << endl;

    cout << "Astronot yang bertahan: " << lingkaran[0] << endl;

    return 0;
}
