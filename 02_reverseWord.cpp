#include <iostream>
using namespace std;

const int MAX = 50;     
char stackArr[MAX];     
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull()  { return top == MAX - 1; }

void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow!\n";
        return;
    }
    stackArr[++top] = c;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!\n";
        return '\0';
    }
    return stackArr[top--];
}

int main() {
    char word[MAX + 1];
    cout << "Enter a word: ";
    cin >> word;

    int len = 0;
    while (word[len] != '\0' && len < MAX) {
        push(word[len]);
        len++;
    }

    cout << "\nOriginal word: " << word << endl;

    cout << "Reversed word: ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;
    return 0;
}