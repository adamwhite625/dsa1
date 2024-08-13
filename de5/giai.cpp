#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Hàm thêm node m?i vào cu?i danh sách liên k?t
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

// Hàm xu?t danh sách liên k?t ra màn hình
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << "-";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm chuy?n các ph?n t? ch?n vào danh sách A và các ph?n t? l? vào danh sách B
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

    // Nh?p danh sách A
    cout << "Nhap danh sach A (ket thuc bang -1): ";
    while (cin >> value && value != -1) {
        append(listA, value);
    }

    // Nh?p danh sách B
    cout << "Nhap danh sach B (ket thuc bang -1): ";
    while (cin >> value && value != -1) {
        append(listB, value);
    }

    // Hoán d?i ph?n t? ch?n và l? gi?a hai danh sách
    separateLists(listA, listB);

    // Xu?t danh sách A
    cout << "Danh sach A: ";
    printList(listA);

    // Xu?t danh sách B
    cout << "Danh sach B: ";
    printList(listB);

    return 0;
}


