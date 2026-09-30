//without ADT

#include <iostream>
using namespace std;

int main(){
    string name[45];
    string nim[45];
    float percentage[45];

    int jum;
    cin >> jum;
    for (int i = 0; i < jum; i++) {
        cout << "Nama = ";
        cin >> name[i];

        cout << "NIM = ";
        cin >> nim[i];

        cout << "Persentase Kehadiran = ";
        cin >> percentage[i];

        cout << endl;
    }

    for (int i = 0; i < jum; i++) {
        cout << "MAHASISWA " << i+1 << " = " << endl;
        cout << name[i] << " | " << nim[i] << " | " << percentage[i] << "%" << endl;
        cout << endl;
    }
    return 0;
};