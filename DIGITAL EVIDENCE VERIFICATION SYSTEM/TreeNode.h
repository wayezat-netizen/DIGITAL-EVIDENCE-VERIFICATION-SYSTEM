#pragma once
#include "Evidence.h"

// Binary Search Tree Node structure
struct TreeNode {
    // Public members
    Evidence data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(Evidence e);
}; 