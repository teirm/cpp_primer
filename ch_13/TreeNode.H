#include <string>

class TreeNode {
public:
    TreeNode(std::string v): value(v), count(0),
                             left(nullptr), right(nullptr) {}
    ~TreeNode();
    TreeNode(TreeNode &rhs); 
    TreeNode& operator=(const TreeNode &rhs);
private:
    std::string value;
    int         count;
    TreeNode    *left;
    TreeNode    *right;
};
