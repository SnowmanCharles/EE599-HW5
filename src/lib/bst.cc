#include "bst.h"
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

BST::BST() {//O(1)
    root_ = nullptr;
}

BST::BST(vector<int> initial_values) {//O(n)
    root_ = nullptr;
    for (int i : initial_values) {
        push(i);
    }
}

BST::~BST() {//O(n)
    recursively_remove(root_);
    root_ = nullptr;
}

void BST::recursively_remove(TreeNode *curNode) {//O(1)
    if (curNode == nullptr) {
        return;
    }
    recursively_remove(curNode->left);
    recursively_remove(curNode->right);
    delete curNode;
}

void BST::push(int key) {//O(log(n))
    push_helper(root_, key);
}

void BST::push_helper(TreeNode *&curNode, int key) {
    if (curNode == nullptr) {
        curNode = new TreeNode(key);
    } else if (curNode->val < key) {
        push_helper(curNode->right, key);
    } else if (curNode->val > key) {
        push_helper(curNode->left, key);
    }
}

bool BST::find(int key) {//O(log(n))
    return find_helper(root_, key);
}

bool BST::find_helper(TreeNode *&curNode, int key) {
    if (curNode == nullptr) return false;
    if (curNode->val == key) return true;
    if (curNode->val > key) return find_helper(curNode->left, key);
    return find_helper(curNode->right, key);
}

bool BST::erase(int key) {//O(log(n))
    TreeNode *p = root_, *p_parent = p;
    while (p != nullptr && p->val != key) {
        p_parent = p;
        if (p->val > key) p = p->left;
        else p = p->right;
    }
    if (p == nullptr) return false;
    if (p->left == nullptr) {
        if (p == root_) {
            root_ = p->right;
        } else {
            if (p_parent->right == p) p_parent->right = p->right;
            else p_parent->left = p->right;
        } 
        delete p;
    } else if (p->right == nullptr) {
        if (p == root_) {
            root_ = p->left;
        } else {
            if (p_parent->right == p) p_parent->right = p->left;
            else p_parent->left = p->left;
        }
        delete p;
    } else {
        TreeNode *pre = p->left, *pre_parent = p;
        while (pre->right != nullptr) {
            pre_parent = pre;
            pre = pre->right;
        }
        p->val = pre->val;
        if (pre_parent == p) pre_parent->left = pre->left;
        else pre_parent->right = pre->left;
        delete pre;
    }
    return true;
}

vector<int> BST::levelTraversal() {//O(n)
    vector<int> res;
    if (root_ == nullptr) return res;
    queue<TreeNode*> q;
    q.push(root_);
    while (!q.empty()) {
        TreeNode *temp = q.front();
        q.pop();
        res.push_back(temp->val);
        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }
    return res;
}

int BST::getHeight() {//O(n)
    return getHeightHelper(root_);
}

int BST::getHeightHelper(TreeNode *curNode) {
    if (curNode == nullptr) return 0;
    return max(getHeightHelper(curNode->left), getHeightHelper(curNode->right)) + 1;
}

vector<int> BST::inorderTraversalRecursively() {//O(n)
    vector<int> res;
    inorderTraversalRecursivelyHelper(root_, res);
    return res;
}

void BST::inorderTraversalRecursivelyHelper(TreeNode *curNode, vector<int> &res) {
    if (curNode == nullptr) return;
    inorderTraversalRecursivelyHelper(curNode->left, res);
    res.push_back(curNode->val);
    inorderTraversalRecursivelyHelper(curNode->right, res);
}

vector<int> BST::inorderTraversalIteratively() {//O(n)
    vector<int> res;
    if (root_ == nullptr) return res;
    stack<TreeNode*> st;
    TreeNode *p = root_;
    while (p != nullptr || !st.empty()) {
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }
        if (!st.empty()) {
            p = st.top();
            res.push_back(p->val);
            st.pop();
            p = p->right;
        }
    }
    return res;
}