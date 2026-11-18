#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;   
int rearIdx = -1;   
int count = 0;      

bool isEmpty() { return count == 0; }
bool isFull()  { return count == MAX; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Tidak bisa memasukkan " << value << ".\n";
        return;
    }
    rearIdx = (rearIdx + 1) % MAX;   
    queueArr[rearIdx] = value;
    count++;
    cout << value << " inserted successfully.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong.\n";
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully.\n";
    frontIdx = (frontIdx + 1) % MAX; 
    count--;
}

void display() {
    cout << "Queue: ";
    if (isEmpty()) {
        cout << "(kosong)\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << queueArr[(frontIdx + i) % MAX] << " ";
    }
    cout << endl;
}

void mandatoryTest() {
    cout << "=== MANDATORY TEST ===\n";
    int vals[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) enqueue(vals[i]);  
    dequeue();                                      
    dequeue();                                      
    enqueue(60);                                    
    enqueue(70);                                    
    display();                                      
    cout << "======================\n";
}

int main() {
    mandatoryTest();

    int choice, value;
    do {
        cout << "\n===== CIRCULAR QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue  3. Display  4. Exit\n";
        cout << "Choose operation: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 4);
    return 0;
}