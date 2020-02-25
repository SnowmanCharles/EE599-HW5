#ifndef BST_H
#define BST_H

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();

    // Inserts elements of initial_values 
    // one by one into the Tree
    BST(vector<int> initial_values);
    ~BST();

    void push(int key);  //**GT** Inserts a key inside Tree
    bool find(int key);  //**GT** Returns true of key is in the tree
    bool erase(int key);  //**GT** Removes the key from the tree. If not successful, returns false.

    int getHeight();
    vector<int> inorderTraversalRecursively();
    vector<int> inorderTraversalIteratively();

    vector<int> levelTraversal();
private:
    TreeNode *root_;

    void push_helper(TreeNode *&curNode, int key);
    bool find_helper(TreeNode *&curNode, int key);
    void recursively_remove(TreeNode *curNode);
    int getHeightHelper(TreeNode *curNode);
    void inorderTraversalRecursivelyHelper(TreeNode *curNode, vector<int> &res);
};

#endif