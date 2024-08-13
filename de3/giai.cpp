#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// H�m th�m node v�o c�y nh? ph�n t�m ki?m
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// H�m duy?t c�y theo th? t? gi?m d?n
void inOrderDesc(Node* root) {
    if (root == nullptr) return;

    inOrderDesc(root->right);
    cout << root->data << " ";
    inOrderDesc(root->left);
}

// H�m ki?m tra s? nguy�n t?
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

// H�m t�m node c� gi� tr? nh? nh?t
Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// H�m x�a node c� gi� tr? l� s? nguy�n t?
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// H�m x�a t?t c? c�c node c� gi� tr? l� s? nguy�n t?
void deletePrimes(Node* &root) {
    if (root == nullptr) return;

    deletePrimes(root->left);
    deletePrimes(root->right);

    if (isPrime(root->data)) {
        root = deleteNode(root, root->data);
    }
}

// H�m d?m s? l�
int countLeaves(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    
    // Nh?p c�c gi� tr? v�o c�y
    while (cin >> n) {
        if (n == -1) break; // S? d?ng -1 d? k?t th�c nh?p
        root = insert(root, n);
    }

    // Duy?t c�y theo th? t? gi?m d?n
    cout << "Cay duyet theo thu tu giam dan: ";
    inOrderDesc(root);
    cout << endl;

    // X�a c�c node c� gi� tr? l� s? nguy�n t?
    deletePrimes(root);
    cout << "Cay sau khi xoa cac so nguyen to: ";
    inOrderDesc(root);
    cout << endl;

    // �?m s? l�
    int leafCount = countLeaves(root);
    cout << "So nut la tren cay: " << leafCount << endl;

    return 0;
}

