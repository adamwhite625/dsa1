#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// �?nh nghia c?u tr�c c?a m?t n�t trong c�y nh? ph�n t�m ki?m
struct Node {
    int data;
    int count; // �?m s? l?n xu?t hi?n c?a m?i ph?n t?
    Node* left;
    Node* right;
    Node(int val) : data(val), count(1), left(nullptr), right(nullptr) {}
};

// H�m th�m m?t ph?n t? v�o c�y nh? ph�n t�m ki?m
Node* insert(Node* root, int data) {
    if (data == 0) return root; // K?t th�c khi g?p s? 0
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

// H�m xu?t c�y nh? ph�n t�m ki?m theo th? t? tang d?n v� cho bi?t s? l?n xu?t hi?n c?a t?ng ph?n t?
void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " (count: " << root->count << "), ";
    inOrder(root->right);
}

// H�m xu?t c�c n�t l� c� gi� tr? l� s? l?
void printOddLeaves(Node* root) {
    if (!root) return;
    if (!root->left && !root->right && root->data % 2 != 0) {
        cout << root->data << " ";
    }
    printOddLeaves(root->left);
    printOddLeaves(root->right);
}

// H�m d?m s? n�t con c?a m?t n�t
int countChildren(Node* root) {
    if (!root) return 0;
    return countChildren(root->left) + countChildren(root->right) + 1;
}

// H�m t�m t?t c? c�c n�t tr�n c�y c� s? n�t con b�n tr�i b?ng s? n�t con b�n ph?i
void findNodesWithEqualChildren(Node* root) {
    if (!root) return;
    if (root->left && root->right && countChildren(root->left) == countChildren(root->right)) {
        cout << root->data << " ";
    }
    findNodesWithEqualChildren(root->left);
    findNodesWithEqualChildren(root->right);
}

// H�m t�nh m?c c� nhi?u n�t l� nh?t
int maxLeavesLevel(Node* root) {
    if (!root) return 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    unordered_map<int, int> leafCount; // D�ng b?ng bam d? luu s? n�t l� ? m?i m?c
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

