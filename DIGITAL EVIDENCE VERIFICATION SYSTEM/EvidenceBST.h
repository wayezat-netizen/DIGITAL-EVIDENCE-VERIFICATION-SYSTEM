#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "TreeNode.h"
#include "Evidence.h"

using namespace std;

// Binary Search Tree for storing Evidence objects sorted by timestamp
class EvidenceBST {
private:
    // Root of the BST
    TreeNode* root;

    // Recursive BST insertion helper
    TreeNode* insertHelper(TreeNode* node, Evidence e);

    // Recursive in-order traversal helper
    void inOrderHelper(TreeNode* node, vector<Evidence>& result);

    // Recursive range search helper
    void searchRangeHelper(TreeNode* node, string startDate, string endDate, vector<Evidence>& result);

    // Recursive height calculation helper
    int getHeightHelper(TreeNode* node);

    // Recursive post-order deletion helper
    void destroyTree(TreeNode* node);

public:
    // Constructor
    EvidenceBST();

    // Destructor
    ~EvidenceBST();

    // Insert evidence into BST - O(log n) average
    void insert(Evidence e);

    // Get all evidence in chronological order - O(n)
    vector<Evidence> inOrderTraversal();

    // Search evidence by date range - O(n)
    vector<Evidence> searchByDateRange(string startDate, string endDate);

    // Get height of tree - O(n)
    int getHeight();

    // Get total number of nodes - O(n)
    int getTotalNodes();

    // Display all evidence in chronological order - O(n)
    void displayInOrder();
};