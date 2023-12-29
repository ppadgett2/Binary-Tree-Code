// Binary Tree Code 2
// Parker Padgett
// 10-12-23

#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    // Initializing an empty binary tree
    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void inorderTreeWalk(struct TreeNode* node)
{
    if (node != NULL)
    {
        inorderTreeWalk(node->left);
        cout << node->data << ", ";
        inorderTreeWalk(node->right);
    }
}

int height(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
}

int main()
{
    struct TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    cout << "Inorder Traversal: ";
    inorderTreeWalk(root);

    cout << endl;

    cout << "height of the tree: " << height(root);

    return 0;
}