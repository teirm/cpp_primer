/* Tree Node Class */

#include "TreeNode.H"

TreeNode::~TreeNode()
{
    if (left) {
        delete left;
    }

    if (right) {
        delete right;
    }
}

TreeNode::TreeNode(TreeNode &rhs) 
{
    this->value = rhs.value;
    this->count = rhs.count;
    this->left = nullptr;
    this->right = nullptr;

    if (rhs.left) { 
        this->left = new TreeNode(*rhs.left);
    }

    if (rhs.right) {
        this->right = new TreeNode(*rhs.right);
    }
}


TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
    this->value = rhs.value;
    this->count = rhs.count;

    TreeNode  *newLeft = nullptr;
    TreeNode  *newRight = nullptr;
    
    if (rhs.left) {
        newLeft = new TreeNode(*rhs.left);
    }
    
    if (rhs.right) { 
        newRight = new TreeNode(*rhs.right);
    }
    
    delete this->right;
    delete this->left;

    this->left = newLeft;
    this->right = newRight;

    return *this;
}
