#include <iostream>
#include <string>

using namespace std;

struct ElmList {
    string nim;
    string nama;
    float persentase;
    ElmList* next;
};

struct List {
    ElmList* first;
};

void createlist(List &L) {
    L.first = nullptr;
}

ElmList* createnewelement(string nim, string nama, float persentase) {
    ElmList* P = new ElmList;
    P->nim = nim;
    P->nama = nama;
    P->persentase = persentase;
    P->next = nullptr;
    return P;
}

void printlist(List L) {
    if (L.first == nullptr) {
        cout << "\nList is empty" << endl;
        return;
    }
    
    ElmList* P = L.first;
    int nomor = 1;
    cout << "\n=== DAFTAR MAHASISWA ===" << endl;
    while (P != nullptr) {
        cout << nomor << " | " << P->nim << " | " << P->nama << " | " << P->persentase << "%" << endl;
        P = P->next;
        nomor++;
    }
}

void insertFirst(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void insertlast(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        ElmList* Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void insertAfter(ElmList* Prec, ElmList* P) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

ElmList* search(List L, string keyNim) {
    ElmList* P = L.first;
    while (P != nullptr) {
        if (P->nim == keyNim) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void deleteFirst(List &L) {
    if (L.first == nullptr) {
        cout << "\nList kosong, tidak ada yang bisa dihapus!" << endl;
        return;
    }
    
    ElmList* P = L.first;
    if (P->next == nullptr) {
        L.first = nullptr;
    } else {
        L.first = P->next;
        P->next = nullptr;
    }
    delete P;
    cout << "\nData mahasiswa berhasil dihapus." << endl;
}

int main() {
    List L;
    createlist(L);

    for (int i = 1; i <= 10; i++) {
        string nim, nama;
        float persentase;

        cout << "\nMahasiswa ke-" << i << endl;
        cout << "NIM                  : ";
        cin >> nim;
        
        cout << "Nama                 : ";
        cin >> nama;
        
        cout << "Persentase Kehadiran : ";
        cin >> persentase;

        insertlast(L, createnewelement(nim, nama, persentase));
    }

    printlist(L);

    string cariNim;
    cout << "\nMasukkan NIM yang ingin dicari: ";
    cin >> cariNim;

    ElmList* hasilCari = search(L, cariNim);
    if (hasilCari != nullptr) {
        cout << "-> Data Ditemukan!\n";
        cout << "   NIM   : " << hasilCari->nim << endl;
        cout << "   Nama  : " << hasilCari->nama << endl;
        cout << "   Hadir : " << hasilCari->persentase << "%" << endl;
    } else {
        cout << "-> Maaf, data mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }

    cout << "\n--- Menguji Penghapusan Data Pertama ---" << endl;
    deleteFirst(L); 

    printlist(L);

    return 0;
}