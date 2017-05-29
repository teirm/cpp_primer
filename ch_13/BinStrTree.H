/* Binary Str Tree */

#include "TreeNode.H"

class BinStrTree {
public:
    BinStrTree(std::string s): root(new TreeNode(s)), use(new int(1)) {}
    BinStrTree(BinStrTree &rhs): root(rhs.root) {++*use; };
    ~BinStrTree();
    BinStrTree& operator=(const BinStrTree&);
private:
    TreeNode *root;
    int      *use;
};
