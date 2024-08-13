#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm thêm một nút vào cây nhị phân tìm kiếm
TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return new TreeNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Hàm xuất cây nhị phân tìm kiếm theo thứ tự giữa (in-order traversal)
void inOrder(TreeNode* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// Hàm xóa một nút khỏi cây nhị phân tìm kiếm
TreeNode* deleteNode(TreeNode* root, int data) {
    if (root == nullptr) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Hàm xóa tất cả các nút là số nguyên tố khỏi cây nhị phân tìm kiếm
TreeNode* deletePrimes(TreeNode* root) {
    if (root == nullptr) return root;
    root->left = deletePrimes(root->left);
    root->right = deletePrimes(root->right);
    if (isPrime(root->data)) {
        root = deleteNode(root, root->data);
    }
    return root;
}

// Hàm đếm số nút con của một nút
int countNodes(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Hàm tìm tất cả các nút có số nút con bên trái bằng số nút con bên phải
void findBalancedNodes(TreeNode* root, vector<int>& balancedNodes) {
    if (root == nullptr) return;
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    if (leftCount == rightCount) {
        balancedNodes.push_back(root->data);
    }
    findBalancedNodes(root->left, balancedNodes);
    findBalancedNodes(root->right, balancedNodes);
}

int main() {
    TreeNode* root = nullptr;
    int data;

    cout << "Nhap cac phan tu cua cay (nhap -1 de ket thuc): ";
    while (cin >> data && data != -1) {
        root = insert(root, data);
    }

    cout << "Cay nhi phan tim kiem: ";
    inOrder(root);
    cout << endl;

    root = deletePrimes(root);

    cout << "Cay sau khi xoa cac nut la so nguyen to: ";
    inOrder(root);
    cout << endl;

    vector<int> balancedNodes;
    findBalancedNodes(root, balancedNodes);

    cout << "Cac nut co so nut con ben trai bang so nut con ben phai: ";
    for (int val : balancedNodes) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
