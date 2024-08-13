#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Ð?nh nghia c?u trúc c?a m?t nút trong cây nh? phân tìm ki?m
struct Node {
    int data;
    int count; // Ð?m s? l?n xu?t hi?n c?a m?i ph?n t?
    Node* left;
    Node* right;
    Node(int val) : data(val), count(1), left(nullptr), right(nullptr) {}
};

// Hàm thêm m?t ph?n t? vào cây nh? phân tìm ki?m
Node* insert(Node* root, int data) {
    if (data == 0) return root; // K?t thúc khi g?p s? 0
    if (!root) return new Node(data);
    if (data == root->data) {
        root->count++;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Hàm xu?t cây nh? phân tìm ki?m theo th? t? tang d?n và cho bi?t s? l?n xu?t hi?n c?a t?ng ph?n t?
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " (count: " << root->count << "), ";
    inOrder(root->right);
}

// Hàm xu?t các nút lá có giá tr? là s? l?
void printOddLeaves(Node* root) {
    if (!root) return;
    if (!root->left && !root->right && root->data % 2 != 0) {
        cout << root->data << " ";
    }
    printOddLeaves(root->left);
    printOddLeaves(root->right);
}

// Hàm d?m s? nút con c?a m?t nút
int countChildren(Node* root) {
    if (!root) return 0;
    return countChildren(root->left) + countChildren(root->right) + 1;
}

// Hàm tìm t?t c? các nút trên cây có s? nút con bên trái b?ng s? nút con bên ph?i
void findNodesWithEqualChildren(Node* root) {
    if (!root) return;
    if (root->left && root->right && countChildren(root->left) == countChildren(root->right)) {
        cout << root->data << " ";
    }
    findNodesWithEqualChildren(root->left);
    findNodesWithEqualChildren(root->right);
}

// Hàm tính m?c có nhi?u nút lá nh?t
int maxLeavesLevel(Node* root) {
    if (!root) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    unordered_map<int, int> leafCount; // Dùng b?ng bam d? luu s? nút lá ? m?i m?c
    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();
        if (!node->left && !node->right) {
            leafCount[level]++;
        }
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    int maxCount = 0, maxLevel = 0;
    for (auto& [level, count] : leafCount) {
        if (count > maxCount) {
            maxCount = count;
            maxLevel = level;
        }
    }
    return maxLevel;
}

int main() {
    Node* root = nullptr;
    int num;
    cout << "Enter integers to build the binary search tree (enter 0 to stop):\n";
    while (true) {
        cin >> num;
        if (num == 0) break;
        root = insert(root, num);
    }

    cout << "\n1. In-order traversal of the binary search tree:\n";
    inOrder(root);

    cout << "\n\n2. Odd leaves in the binary search tree:\n";
    printOddLeaves(root);

    cout << "\n\n3. Nodes with equal number of children on left and right subtrees:\n";
    findNodesWithEqualChildren(root);

    cout << "\n\n4. Level with maximum number of leaves: " << maxLeavesLevel(root) << endl;

    return 0;
}

