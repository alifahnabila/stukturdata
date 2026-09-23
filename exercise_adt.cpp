#include <iostream>
#include <string>

using namespace std;

struct nilaiSTD
{
    double clo1;
    double clo2;
    double clo3;
    double clo4;
    double nilaiAkhir;
    string indeks;
};

double hitungNilaiAkhir(double c1, double c2, double c3, double c4) {
    double hasil = (0.30*c1)+(0.30*c2)+(0.20*c3)+(0.20*c4);
    return hasil;
}

string tentukanIndeks(double nilai){
    if (nilai > 80) {
        return "A";
    } else if (nilai > 70) {
        return "AB";
    } else if (nilai > 65) {
        return "B";
    } else if (nilai > 60) {
        return "BC";
    } else if (nilai > 50) {
        return "C";
    } else if (nilai > 40) {
        return "D";
    } else {
        return "E";
    }
}

int main(){
    nilaiSTD mahasiswa[3];

    cout << "=== STUDENT GRADE SYSTEM ===" << endl;
    
    for (int i = 0; i < 3; i++){
        cout << "\nMahasiswa " << i + 1 << endl;

        cout << "CLO 1: ";
        cin >> mahasiswa[i].clo1;
        
        cout << "CLO 2: ";
        cin >> mahasiswa[i].clo2;
        
        cout << "CLO 3: ";
        cin >> mahasiswa[i].clo3;
        
        cout << "CLO 4: ";
        cin >> mahasiswa[i].clo4;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].clo1, mahasiswa[i].clo2, mahasiswa[i].clo3,mahasiswa[i].clo4);
        mahasiswa[i].indeks = tentukanIndeks(mahasiswa[i].nilaiAkhir);
    }

    cout << "=== HASIL ===" << endl;
    for (int i = 0; i < 3; i++){
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiAkhir << endl;
        cout << "Indeks: " << mahasiswa[i].indeks << endl;
    }

    return 0;
}
