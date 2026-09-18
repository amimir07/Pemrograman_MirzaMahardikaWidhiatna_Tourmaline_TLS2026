#include <iostream>
using namespace std;

const int MAX = 1000;


int hitungPanjang(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

// (A=1, ..., Z=26)
int hurufKePosisi(char huruf) {
    return (huruf - 'A' + 1);
}

char posisiKeHuruf(int posisi) {
    return (char)('A' + posisi - 1);
}

void enkripsi(char pesan[], char hasil[]) {
    int n = hitungPanjang(pesan);
    int posisiAsli[MAX];
    int posisiBaru[MAX];

    for (int i = 0; i < n; i++) {
        posisiAsli[i] = hurufKePosisi(pesan[i]);
    }

    posisiBaru[0] = posisiAsli[0];

    for (int i = 1; i < n; i++) {
        int nilai = posisiAsli[i] + posisiAsli[i - 1];
        if (nilai > 26) {
            nilai = nilai - 26;
        }
        posisiBaru[i] = nilai;
    }

    for (int i = 0; i < n; i++) {
        hasil[i] = posisiKeHuruf(posisiBaru[i]);
    }
    hasil[n] = '\0';
}

void dekripsi(char pesan[], char hasil[]) {
    int n = hitungPanjang(pesan);
    int posisiSandi[MAX];
    int posisiAsli[MAX];

    for (int i = 0; i < n; i++) {
        posisiSandi[i] = hurufKePosisi(pesan[i]);
    }

    posisiAsli[0] = posisiSandi[0];

    for (int i = 1; i < n; i++) {
        int nilai = posisiSandi[i] - posisiAsli[i - 1];
        if (nilai <= 0) {
            nilai = nilai + 26;
        }
        posisiAsli[i] = nilai;
    }

    for (int i = 0; i < n; i++) {
        hasil[i] = posisiKeHuruf(posisiAsli[i]);
    }
    hasil[n] = '\0';
}

int main() {
    char pesan[MAX];
    char sandi[MAX];
    char pesanAsli[MAX];

    cout << "Masukkan pesan asli (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    enkripsi(pesan, sandi);
    cout << "Pesan tersandi: " << sandi << endl;

    dekripsi(sandi, pesanAsli);
    cout << "Pesan asli: " << pesanAsli << endl;

    return 0;
}
