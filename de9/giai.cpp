#include <iostream>
#include <cmath>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Hàm chèn một nút vào cây nhị phân tìm kiếm
TreeNode* insert(TreeNode* root, int data) {
    if (!root) {
        return new TreeNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Hàm tìm giá trị nhỏ nhất của cây con
TreeNode* findMin(TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Hàm xóa một nút khỏi cây nhị phân tìm kiếm
TreeNode* deleteNode(TreeNode* root, int data) {
    if (!root) return root;
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
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

// Hàm kiểm tra một số có phải là số chính phương không
bool isPerfectSquare(int n) {
    int sqrtN = static_cast<int>(sqrt(n));
    return (sqrtN * sqrtN == n);
}

// Hàm xóa tất cả các nút là số chính phương
TreeNode* deletePerfectSquares(TreeNode* root) {
    if (!root) return nullptr;
    root->left = deletePerfectSquares(root->left);
    root->right = deletePerfectSquares(root->right);
    if (isPerfectSquare(root->data)) {
        root = deleteNode(root, root->data);
    }
    return root;
}

// Hàm tính tổng các nút con của một cây
int sumNodes(TreeNode* root) {
    if (!root) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

// Hàm tìm các nút có tổng giá trị của các nút con bên trái bằng tổng giá trị của các nút con bên phải
void findNodesWithEqualChildSum(TreeNode* root) {
    if (!root) return;
    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);
    if (leftSum == rightSum) {
        std::cout << root->data << " ";
    }
    findNodesWithEqualChildSum(root->left);
    findNodesWithEqualChildSum(root->right);
}

// Hàm duyệt cây theo thứ tự trung (Inorder)
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Hàm chính
int main() {
    TreeNode* root = nullptr;
    int data;

    std::cout << "Nhập các số nguyên dương để chèn vào cây BST (<= 0 để dừng):" << std::endl;
    while (true) {
        std::cin >> data;
        if (data <= 0) break;
        root = insert(root, data);
    }

    std::cout << "Cây nhị phân tìm kiếm sau khi chèn các phần tử: ";
    inorderTraversal(root);
    std::cout << std::endl;

    root = deletePerfectSquares(root);
    std::cout << "Cây sau khi xóa các nút là số chính phương: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Các nút có tổng giá trị của các nút con bên trái bằng tổng giá trị của các nút con bên phải: ";
    findNodesWithEqualChildSum(root);
    std::cout << std::endl;

    // Giải phóng bộ nhớ
    while (root) {
        root = deleteNode(root, root->data);
    }

    return 0;
}
