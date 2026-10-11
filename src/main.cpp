#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    
    Node(string val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void append(string val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void traverseForward() {
        cout << "--- Forward Traversal ---" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void traverseBackward() {
        cout << "--- Backward Traversal ---" << endl;
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }

    void insertAfter(string targetVal, string newVal) {
        Node* current = head;
        while (current != nullptr && current->data != targetVal) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Target " << targetVal << " tidak ditemukan!" << endl;
            return;
        }

        Node* newNode = new Node(newVal);
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
        cout << "Berhasil menyisipkan " << newVal << " setelah " << targetVal << endl;
    }

    void deleteNode(string targetVal) {
        Node* current = head;
        while (current != nullptr && current->data != targetVal) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node " << targetVal << " tidak ditemukan!" << endl;
            return;
        }

        if (current == head) {
            head = current->next;
            if (head != nullptr) head->prev = nullptr;
            else tail = nullptr;
        } else if (current == tail) {
            tail = current->prev;
            if (tail != nullptr) tail->next = nullptr;
            else head = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Berhasil menghapus node: " << targetVal << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append("Stasiun Bogor");
    dll.append("Stasiun Cilebut");
    dll.append("Stasiun Bojonggede");
    dll.append("Stasiun Citayam");
    dll.append("Stasiun Depok");

    cout << ">>> INITIAL LIST " << endl;
    dll.traverseForward();
    
    cout << "\n>>> TRAVERSAL TEST " << endl;
    dll.traverseForward();
    dll.traverseBackward();

    cout << "\n>>> INSERTION TEST " << endl;
    dll.insertAfter("Stasiun Bogor", "Stasiun Kedung Badak");
    dll.traverseForward();

    cout << "\n>>> DELETION TEST " << endl;
    dll.deleteNode("Stasiun Bojonggede");
    dll.traverseForward();
    dll.traverseBackward();

    return 0;
}
