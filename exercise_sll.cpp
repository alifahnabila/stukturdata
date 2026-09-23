#include <iostream>

using namespace std;

struct ElmList {
    int info;
    ElmList* next;
};

ElmList* createNewElement(int value) {
    ElmList* P = new ElmList;
    P->info = value;
    P->next = nullptr;
    return P;
}

struct List{
    ElmList* first;
};

void createList(List &L){
    L.first = nullptr;
}

void insertFirst(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printList(List L) {
    ElmList* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertLast(List &L, ElmList* P) {
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
 P->next = Prec->next;
 Prec->next = P;
}

ElmList* searchElement(List L, int key) {
    ElmList* P = L.first;
    while (P != nullptr) {
        if (P->info == key) {
        return P;
    }
    P = P->next;
    }
    return nullptr;
}

void deleteFirst(List &L) {
    if (L.first == nullptr) {
        cout << "List is empty" << endl;
    return;
    }
    ElmList* P = L.first;
    L.first = P->next;
    P->next = nullptr;
    delete P;
}

int main(){
    List L;
    createList(L);

    insertLast(L, createNewElement(10));
    insertLast(L, createNewElement(20));
    insertLast(L, createNewElement(30));

    cout << "print -> ";
    printList(L);

    insertFirst(L, createNewElement(5));
    cout << "print -> ";
    printList(L);

    cout << "search 20 ->";
    ElmList* found = searchElement(L, 20);
    if (found != nullptr){
        cout << "FOUND" << endl;
    } else {
        cout << "NOT FOUNF" << endl;
    }

    deleteFirst(L);
    cout << "print -> ";
    printList(L);
    
    return 0; 
}