#include "EvidenceBST.h"

using namespace std;

// Constructor - initialize empty BST
EvidenceBST::EvidenceBST() {
    root = nullptr;
}

// Destructor - free all nodes
EvidenceBST::~EvidenceBST() {
    destroyTree(root);
}

// Recursive post-order deletion to free memory
void EvidenceBST::destroyTree(TreeNode* node) {
    // Post-order deletion to free memory
    if (node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

// Recursive BST insertion by timestamp
TreeNode* EvidenceBST::insertHelper(TreeNode* node, Evidence e) {
    // BST insertion by timestamp - O(log n) average
    if (node == nullptr) {
        return new TreeNode(e);
    }

    if (e.timestamp < node->data.timestamp) {
        node->left = insertHelper(node->left, e);
    }
    else {
        node->right = insertHelper(node->right, e);
    }

    return node;
}

// Insert evidence into BST
void EvidenceBST::insert(Evidence e) {
    root = insertHelper(root, e);
}

// Recursive in-order traversal helper
void EvidenceBST::inOrderHelper(TreeNode* node, vector<Evidence>& result) {
    // In-order: left, root, right - gives chronological order
    if (node == nullptr) {
        return;
    }

    inOrderHelper(node->left, result);
    result.push_back(node->data);
    inOrderHelper(node->right, result);
}

// Get all evidence in chronological order
vector<Evidence> EvidenceBST::inOrderTraversal() {
    // O(n) - visits all nodes
    vector<Evidence> result;
    inOrderHelper(root, result);
    return result;
}

// Recursive range search helper
void EvidenceBST::searchRangeHelper(TreeNode* node, string startDate, string endDate, vector<Evidence>& result) {
    if (node == nullptr) {
        return;
    }

    searchRangeHelper(node->left, startDate, endDate, result);

    if (node->data.timestamp >= startDate && node->data.timestamp <= endDate) {
        result.push_back(node->data);
    }

    searchRangeHelper(node->right, startDate, endDate, result);
}

// Search evidence by date range
vector<Evidence> EvidenceBST::searchByDateRange(string startDate, string endDate) {
    vector<Evidence> result;
    searchRangeHelper(root, startDate, endDate, result);
    return result;
}

// Recursive height calculation helper
int EvidenceBST::getHeightHelper(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = getHeightHelper(node->left);
    int rightHeight = getHeightHelper(node->right);

    return 1 + max(leftHeight, rightHeight);
}

// Get height of tree
int EvidenceBST::getHeight() {
    return getHeightHelper(root);
}

// Get total number of nodes
int EvidenceBST::getTotalNodes() {
    return inOrderTraversal().size();
}

// Display all evidence in chronological order
void EvidenceBST::displayInOrder() {
    vector<Evidence> all = inOrderTraversal();

    if (all.empty()) {
        cout << "BST is empty" << endl;
        return;
    }

    cout << "========== Evidence in Chronological Order ==========" << endl;
    for (Evidence& e : all) {
        e.display();
        cout << "------------------------" << endl;
    }
}