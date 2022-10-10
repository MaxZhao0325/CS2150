#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
string AVLTree::findsecondlargest(AVLNode* n){
    if (n->right->right==NULL){
        return n->value;
    }
    return findsecondlargest(n->right);
}
string AVLTree::findsecondlargest(){
    return findsecondlargest(root);
}
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    if (root == NULL){
        root = new AVLNode();
        root->value = x;
    }
    else{
        insert(root, x);
    }
}
//Helper method for insert
void AVLTree::insert(AVLNode*& current, const string& x) {
    if (current->value > x){
        if (current->left != NULL){
            insert(current->left, x);
        }
        else{
            AVLNode* newNode = new AVLNode();
            newNode->value = x;
            current->left = newNode;
        }
    }
    if (current->value < x){
        if (current->right != NULL){
            insert(current->right, x);
        }
        else{
            AVLNode* newNode = new AVLNode();
            newNode->value = x;
            current->right = newNode;
        }
    }
    current->height =  1 + max(height(current->left), height(current->right));
    balance(current);
}


// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) {
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
void AVLTree::pathTo(const string& x, AVLNode* current, vector<string>& arr){
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
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    if (root != NULL){
        return find(x, root);
    }
    else{
        return false;
    }
}

// helper method for find
bool AVLTree::find(const string& x, AVLNode* current)const{
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
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    if (root != NULL){
        return numNodes(root);
    }
    else{
        return 0;
    }
}

// helper method for numNodes
int AVLTree::numNodes(AVLNode* current)const{
    if (current == NULL){
        return 0;
    }
    return 1 + numNodes(current->left) + numNodes(current->right);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    if(n->right != NULL){
        if (n->right->height == 1 && n->left == NULL){
            if (n->right->right == NULL && n->right->left != NULL){
                n->right = rotateRight(n->right);
            }
            if (n->right->right != NULL && n->right->left != NULL){
                if (height(n->right->right) - height(n->right->left) < 0){
                    n->right = rotateRight(n->right);
                }
            }
            n = rotateLeft(n);
        }
    }
    
    if(n->left != NULL){
        if(n->left->height == 1 && n->right == NULL){
            if (n->left->left == NULL && n->left->right != NULL){
                n->left = rotateLeft(n->left);
            }
            if (n->left->left != NULL && n->left->right != NULL){
                if (height(n->left->left) - height(n->left->right) < 0){
                    n->left = rotateLeft(n->left);
                }
            }
            n = rotateRight(n);
        }
    }

    if(n->right != NULL && n->left != NULL){
        if (n->right->height - n->left->height == 2){
            if (height(n->right->right) - height(n->right->left) < 0){
                n->right = rotateRight(n->right);
            }
            n = rotateLeft(n);
        }
        if (n->right->height - n->left->height == -2){
            if (height(n->left->right) - height(n->left->left) > 0){
                n->left = rotateLeft(n->left);
            }
            n = rotateRight(n);
        }
    }
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* y = n->right;
    AVLNode* temp2 = y->left;
    y->left = n;
    n->right = temp2;
    n->height = 1 + max(height(n->left), height(n->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* y = n->left;
    AVLNode* temp2 = y->right;
    y->right = n;
    n->left = temp2;
    n->height = 1 + max(height(n->left), height(n->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
