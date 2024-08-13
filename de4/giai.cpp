#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// H�m t?o node m?i v� th�m v�o cu?i danh s�ch li�n k?t
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

// H�m h?p nh?t hai danh s�ch li�n k?t tang d?n th�nh m?t danh s�ch tang d?n
Node* mergeLists(Node* listA, Node* listB) {
    Node* dummy = new Node(0);
    Node* current = dummy;

    while (listA != nullptr && listB != nullptr) {
        if (listA->data < listB->data) {
            current->next = listA;
            listA = listA->next;
        } else {
            current->next = listB;
            listB = listB->next;
        }
        current = current->next;
    }

    if (listA != nullptr) current->next = listA;
    if (listB != nullptr) current->next = listB;

    Node* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main() {
    Node* listA = nullptr;
    Node* listB = nullptr;

    // Nh?p danh s�ch 1A
    cout << "Nhap danh sach 1A (ket thuc bang ky tu khac so): ";
    int value;
    while (cin >> value) {
        append(listA, value);
        if (cin.peek() == '\n') break;
    }
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Nh?p danh s�ch 1B
    cout << "Nhap danh sach 1B (ket thuc bang ky tu khac so): ";
    while (cin >> value) {
        append(listB, value);
        if (cin.peek() == '\n') break;
    }
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Xu?t danh s�ch 1A
    cout << "Danh sach 1A: ";
    printList(listA);

    // Xu?t danh s�ch 1B
    cout << "Danh sach 1B: ";
    printList(listB);

    // H?p nh?t danh s�ch 1A v� 1B th�nh danh s�ch IC tang d?n
    Node* listC = mergeLists(listA, listB);

    // Xu?t danh s�ch IC
    cout << "Danh sach IC: ";
    printList(listC);

    return 0;
}

