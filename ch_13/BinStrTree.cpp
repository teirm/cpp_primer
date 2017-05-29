/* Binary StrTree */

#include "BinStrTree.H"

BinStrTree::~BinStrTree()
{
    if (--*use == 0) {
        delete root;
        delete use;
    }
}

BinStrTree& BinStrTree::operator=(const BinStrTree &rhs)
{
    ++*rhs.use;
    if (--*use == 0) {
        delete root;
        delete use;
    }
    root = rhs.root;
    use = rhs.use;
    return *this;
}
