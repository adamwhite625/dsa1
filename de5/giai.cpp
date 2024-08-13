#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// H�m th�m node m?i v�o cu?i danh s�ch li�n k?t
void append(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// H�m xu?t danh s�ch li�n k?t ra m�n h�nh
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << "-";
        temp = temp->next;
    }
    cout << endl;
}

// H�m chuy?n c�c ph?n t? ch?n v�o danh s�ch A v� c�c ph?n t? l? v�o danh s�ch B
void separateLists(Node*& listA, Node*& listB) {
    Node* evenA = nullptr;
    Node* oddB = nullptr;

    Node* currentA = listA;
    while (currentA != nullptr) {
        if (currentA->data % 2 == 0) {
            append(evenA, currentA->data);
        } else {
            append(oddB, currentA->data);
        }
        currentA = currentA->next;
    }

    Node* currentB = listB;
    while (currentB != nullptr) {
        if (currentB->data % 2 == 0) {
            append(evenA, currentB->data);
        } else {
            append(oddB, currentB->data);
        }
        currentB = currentB->next;
    }

    listA = evenA;
    listB = oddB;
}

int main() {
    Node* listA = nullptr;
    Node* listB = nullptr;

    int value;

    // Nh?p danh s�ch A
    cout << "Nhap danh sach A (ket thuc bang -1): ";
    while (cin >> value && value != -1) {
        append(listA, value);
    }

    // Nh?p danh s�ch B
    cout << "Nhap danh sach B (ket thuc bang -1): ";
    while (cin >> value && value != -1) {
        append(listB, value);
    }

    // Ho�n d?i ph?n t? ch?n v� l? gi?a hai danh s�ch
    separateLists(listA, listB);

    // Xu?t danh s�ch A
    cout << "Danh sach A: ";
    printList(listA);

    // Xu?t danh s�ch B
    cout << "Danh sach B: ";
    printList(listB);

    return 0;
}


