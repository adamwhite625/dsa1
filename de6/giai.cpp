#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
    
    Node(char val) : data(val), next(nullptr) {}
};

// Hàm tạo node mới và thêm vào cuối danh sách liên kết
void append(Node*& head, char data) {
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

// Hàm xuất danh sách liên kết ra màn hình
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << "-";
        temp = temp->next;
    }
    cout << endl;
}

// Hàm nhập danh sách liên kết từ người dùng
void inputHexNumber(Node*& head, const string& prompt) {
    cout << prompt;
    char ch;
    while (cin >> ch && isxdigit(ch)) {
        ch = toupper(ch); // Chuyển ký tự thành chữ hoa để đảm bảo tính đồng nhất
        append(head, ch);
        if (cin.peek() == '\n') break;
    }
    cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Hàm tính chiều dài của danh sách liên kết
int length(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != nullptr) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Hàm so sánh hai danh sách liên kết biểu diễn số hex
int compareHexNumbers(Node* listA, Node* listB) {
    Node* nodeA = listA;
    Node* nodeB = listB;

    while (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA->data > nodeB->data) {
            return 1;  // A > B
        } else if (nodeA->data < nodeB->data) {
            return -1; // A < B
        }
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return 0;  // A == B
}

int main() {
    Node* listA = nullptr;
    Node* listB = nullptr;

    // Nhập danh sách A
    inputHexNumber(listA, "Nhap danh sach A (ket thuc bang ky tu khac hex): ");
    
    // Nhập danh sách B
    inputHexNumber(listB, "Nhap danh sach B (ket thuc bang ky tu khac hex): ");
    
    // Kiểm tra độ dài của hai danh sách
    int lenA = length(listA);
    int lenB = length(listB);

    if (lenA != lenB) {
        cout << "A va B phai co cung so phan tu." << endl;
        return 1;
    }

    // Xuất danh sách A
    cout << "Danh sach A: ";
    printList(listA);

    // Xuất danh sách B
    cout << "Danh sach B: ";
    printList(listB);

    // So sánh hai danh sách
    int result = compareHexNumbers(listA, listB);
    if (result > 0) {
        cout << "Ket qua: A > B" << endl;
    } else if (result < 0) {
        cout << "Ket qua: B > A" << endl;
    } else {
        cout << "Ket qua: A == B" << endl;
    }

    return 0;
}
