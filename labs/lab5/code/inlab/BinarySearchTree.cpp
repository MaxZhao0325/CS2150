// Hanzhang Zhao hz9xs BinarySearchTree.cpp 10.4
#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    if (root == NULL){
        root = new BinaryNode();
        root->value = x;
    }
    else{
        insert(root, x);
    }
}

// private helper for insert method
void BinarySearchTree::insert(BinaryNode*& current, const string& x) {
    if (current->value > x){
        if (current->left != NULL){
            insert(current->left, x);
        }
        else{
            BinaryNode* newNode = new BinaryNode();
            newNode->value = x;
            current->left = newNode;
        }
    }
    if (current->value < x){
        if (current->right != NULL){
            insert(current->right, x);
        }
        else{
            BinaryNode* newNode = new BinaryNode();
            newNode->value = x;
            current->right = newNode;
        }
    }
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    if (find(x)){
        vector<string> arr;
        pathTo(x, root, arr);
        string x = "";
        for (int i = 0; i < arr.size(); i++){
            x += arr[i] + " ";
        }
        return x;
    }
    else{
        return "";
    }
}
// helper method for pathTo
void BinarySearchTree::pathTo(const string& x, BinaryNode* current, vector<string>& arr){
    arr.push_back(current->value);
    if (current->value > x){
        if (current->left != NULL){
            pathTo(x, current->left, arr);
        }
    }
    else if (current->value < x){
        if (current->right != NULL){
            pathTo(x, current->right, arr);
        }
    }
}

// find determines whether or not x exists in the tree.
bool BinarySearchTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    if (root != NULL){
        return find(x, root);
    }
    else{
        return false;
    }
}

bool BinarySearchTree::find(const string& x, BinaryNode* current)const{
    if (current->value == x){
        return true;
    }
    if (current->value > x){
        if (current->left != NULL){
            return find(x, current->left);
        }
    }
    if (current->value < x){
        if (current->right != NULL){
            return find(x, current->right);
        }
    }
    return false;
}

// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes()const {
    // YOUR IMPLEMENTATION GOES HERE
    if (root != NULL){
        return numNodes(root);
    }
    else{
        return 0;
    }
}
    
// helper method for numNodes
int BinarySearchTree::numNodes(BinaryNode* current)const{
    if (current == NULL){
        return 0;
    }
    return 1 + numNodes(current->left) + numNodes(current->right);
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
