#include <iostream>
using namespace std;

const int MAX = 5;
int queueArr[MAX];
int frontIdx = 0;   
int rearIdx = -1;   

bool isEmpty() { return rearIdx < frontIdx; }
bool isFull()  { return rearIdx == MAX - 1; }

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow! Queue penuh.\n";
        return;
    }
    queueArr[++rearIdx] = value;
    cout << value << " inserted successfully.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Queue kosong.\n";
        return;
    }
    cout << queueArr[frontIdx] << " removed successfully.\n";
    frontIdx++;
    if (isEmpty()) {
        frontIdx = 0;
        rearIdx = -1;
    }
}

void front() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "Front element: " << queueArr[frontIdx] << endl;
}

void display() {
    cout << "Queue: ";
    if (isEmpty()) {
        cout << "(kosong)\n";
        return;
    }
    for (int i = frontIdx; i <= rearIdx; i++) cout << queueArr[i] << " ";
    cout << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue  2. Dequeue\n";
        cout << "3. Front  4. Display  5. Exit\n";
        display();
        cout << "Choose operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: front(); break;
            case 4: display(); break;
            case 5: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 5);
    return 0;
}