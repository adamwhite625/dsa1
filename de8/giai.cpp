#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Hàm thêm phần tử vào đầu danh sách
Node* insert(Node* head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    return newNode;
}

// Hàm hiển thị danh sách liên kết
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data;
        if (temp->next) {
            std::cout << "-";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Hàm sắp xếp danh sách liên kết theo thứ tự tăng dần
Node* sortList(Node* head) {
    if (!head || !head->next) return head;

    Node* sorted = nullptr;

    while (head) {
        Node* current = head;
        head = head->next;

        if (!sorted || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    return sorted;
}

// Function to find the middle of the linked list
Node* getMiddle(Node* head) {
    if (!head) return head;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to partition the linked list around a pivot
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot;

    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (!*newHead) *newHead = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (!*newHead) *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

// Function to perform the QuickSort recursively
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortRecur(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Function to get the tail of the linked list
Node* getTail(Node* head) {
    while (head && head->next) {
        head = head->next;
    }
    return head;
}

// Function to sort the linked list using QuickSort
void quickSort(Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

// Hàm xóa các phần tử trùng nhau trong danh sách đã sắp xếp
Node* removeDuplicates(Node* head) {
    if (!head) return nullptr;

    Node* current = head;
    while (current->next) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

// Hàm kiểm tra danh sách có lập thành một cấp số cộng hay không
bool isArithmeticSequence(Node* head) {
    if (!head || !head->next) return true;

    int diff = head->next->data - head->data;
    Node* current = head->next;
    while (current->next) {
        if (current->next->data - current->data != diff) {
            return false;
        }
        current = current->next;
    }
    return true;
}

int main() {
    Node* head = nullptr;
    int data;

    std::cout << "Nhập các số nguyên dương (<= 0 để dừng): " << std::endl;
    while (true) {
        std::cin >> data;
        if (data <= 0) break;
        head = insert(head, data);
    }

    std::cout << "Danh sách ban đầu: ";
    printList(head);

    head = sortList(head);
    head = removeDuplicates(head);

    std::cout << "Danh sách sau khi sắp xếp và xóa trùng: ";
    printList(head);

    if (isArithmeticSequence(head)) {
        std::cout << "Danh sách lập thành một cấp số cộng." << std::endl;
    } else {
        std::cout << "Danh sách không lập thành một cấp số cộng." << std::endl;
    }

    // Xóa danh sách để giải phóng bộ nhớ
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
