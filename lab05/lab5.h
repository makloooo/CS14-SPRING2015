#ifndef LAB5_H
#define LAB5_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <queue>
#include <map>

using namespace std;

#define nil 0
//#define Value int // restore for testing.

template <typename Value>
class BST {
    class Node { // binary tree node
        
        public:
            bool visited = false;
            bool selected = false;
            
            Value value;
            Node* left;
            Node* right;
            
            Node(const Value v = Value()) : value(v), left(nil), right(nil) {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() { // Hardest function
            
                // assert(this != nil);
                if (this == nil) {
                    cout << "Node is nonexistent. Exiting..." << endl;
                    exit(-1);
                }
                
                if (isLeaf()) return 0;
                
                int leftHeight = 0;
                int rightHeight = 0;
                
                if (hasLeft()) leftHeight = left->height() + 1;
                if (hasRight()) rightHeight = right->height() + 1;
                
                if (leftHeight > rightHeight) return leftHeight;
                else if (rightHeight > leftHeight) return rightHeight;
                return leftHeight;
            }
            int size() {
                if (this == nil) return 0;
                if (isLeaf()) return 1;
                if (isInternal()) {
                    return right->size() + left->size() + 1;
                }
                else if (onlyRight()) {
                    return right->size() + 1;
                }
                else if (onlyLeft()) { 
                    return left->size() + 1;
                }
                return 0;
            }
            
            bool onlyRight() { return left == nil && right != nil; }
            bool onlyLeft() { return left != nil && right == nil; }
            bool hasRight() { return right != nil; }
            bool hasLeft() { return left != nil; }
    }; // Node
    
    private:
    // const Node* nil;
    int count;
    Node* root;
    
    void pre(Node* currNode) const {
        cout << currNode->content() << ' ';
        if(currNode->isLeaf()) return;
        if(currNode->hasLeft()) { pre(currNode->left); }
        if(currNode->hasRight()) { pre(currNode->right); }
        return;
    }
    void post(Node* currNode) const {
        if(currNode->hasLeft()) { post(currNode->left); }
        if(currNode->hasRight()) { post(currNode->right); }
        if(currNode->selected) cout << currNode->content() << ' ';
        if(currNode->isLeaf()) return;
    }
    void order(Node* currNode) const {
        if(currNode->hasLeft()) { order(currNode->left); }
        if(currNode->selected) cout << currNode->content() << ' ';
        if(currNode->isLeaf()) return;
        if(currNode->hasRight()) { order(currNode->right); }
    }
    
    int leftBranch(Node* currNode) const {
        if (currNode->left == nil) {
            // cout << "DEBUG: Left Branch nonexistent." << endl;
            return 0;
        }
        else {
            return currNode->left->size();
        }

        return 0;
    }
    int size() const {
        return count;
    }
    
    public:
        BST() : count(0), root(nil) {} // Constructor
    
        int size() {
            return count;
        }
        bool empty() { return size() == 0; }
        void print_node(const Node* n) {
            // assert(n != nil);
            if (n == nil) {
                cout << "Node is nonexistent. Exiting..." << endl;
                exit(-1);
            }
            cout << n->content();
            return;
        }
        bool search(Value x) {
            Node* currNode = root;
            while(!currNode == nil) {
                if (currNode->content() == x) return true;
                else if (currNode->isLeaf()) return false;
                // cout << currNode->height() << endl;
                currNode = (currNode->content() < x) ? currNode->left : currNode->right;
            }
            return false;
        }
        void preorder() const {
            // assert(size() != 0);
            if (size() == 0) return;
            Node* temp = root;
            pre(temp);
            cout << endl;
            return;
        }
        void postorder() const {
            // assert(size() != 0);
            if (size() == 0) return;
            Node* temp = root;
            post(temp);
            cout << endl;
        }
        void inorder() const {
            // assert(size() != 0);
            if (size() == 0) return;
            Node* temp = root;
            order(temp);
            cout << endl;
        }
        Value& operator[] (int n) {
            
            assert(n >= 0 && n < size());
            
            bool leftOnly = true;
            Node* currNode = root;
            int leftBranchCount = 0; // Left branch of root
            int oldBranchCount = 0;
            
            while (n != -1) { // Meant to create an infinite loop.
                // cout << "DEBUG: Current Node: " << currNode->content() << endl;
                // cout << "DEBUG: Height: " << currNode->height() << endl;
                leftBranchCount = leftBranch(currNode);
                // cout << "DEBUG: Left branch counted: " << leftBranchCount << endl;
                
                if (n == leftBranchCount + oldBranchCount) break;
                
                if (n > leftBranchCount + oldBranchCount) { // If SegFault, the following is wrong.
                    // cout << "DEBUG: Traversing down right branch." << endl;
                    leftOnly = false;
                    currNode = currNode->right;
                    leftBranchCount += 1;   
                    oldBranchCount += leftBranchCount;
                }
                
                else {
                    // cout << "DEBUG: Traversing down left branch." << endl;
                    currNode = currNode->left;
                    if (leftOnly) leftBranchCount = 0;
                    else --leftBranchCount;
                }
            }
            
            return currNode->content();
        }
        void insert(Value X) { root = insert(X, root); }    
        Node* insert (Value X, Node* T) {
            // The normal binary-tree insertion precedure...
            if (T == nil) {
                T = new Node(X); // the only place that T gets updated.
                ++count;
            } else if (X < T->value) {
                T->left = insert(X, T->left);
            } else if (X > T->value) {
                T->right = insert(X, T->right);
            } else {
                T->value = X;
            }
            
            // later, rebalancing code will be installed here
            
            return T;
        }
        void remove(Value X) { root = remove(X, root); }
        Node* remove(Value X, Node*& T) {
            // The normal binary-tree removal procedure...
            if (T != nil) {
                if (X > T->value) T->right = remove(X, T->right);
                else if (X < T->value) T->left = remove(X, T->left);
                else {
                    if (T->right != nil) {
                        Node* x = T->right;
                        while (x->left != nil) x = x->left;
                        T->value = x->value;
                        T->right = remove(T->value, T->right);
                    }
                    else if (T->left != nil) {
                        Node* x = T->left;
                        while (x->right != nil) x = x->right;
                        T->value = x->value;
                        T->left = remove(T->value, T->left);
                    }
                    else {
                        delete T;
                        T = nil;
                        --count;
                    }
                }
            }
            // later, rebalancing code will be installed here
            return T;
        }
        void okay() { okay(root); }
        void okay(Node* T) {
            // diagnostic code can be installed here
            return;
        }
        
        int DFS(Node* currNode);
        int minCover();
        void displayMinCover();
        
        void displayPaths(vector<deque<Node*>> allPaths);
        void findSumPath(Node* n, int sum, int buffer[]);
        Node* getRoot() {
            return root;
        }
        void moveQueue(deque<Node*>& target, vector<deque<Node*>>& allPaths);
        void vertSum(Node* node, int hd, map<int, int>& m);
}; // BST


template<typename Value>
int BST<Value>::DFS(Node* currNode) { //Returns count -> is recursive fn of minCover
    currNode->visited = true;
    static int count = 0;
    
    if (currNode->isLeaf()) { // As long as the node has no children (a leaf)
        return 0;
    }
    if (currNode == root) {
        if(currNode->hasLeft()) DFS(currNode->left);
        if(currNode->hasRight()) DFS(currNode->right);
        
        int tempCount = count; //pseudo d'tor
        count = 0;
        return tempCount;
    }
    
    if(currNode->hasLeft()) DFS(currNode->left);
    if(currNode->hasRight()) DFS(currNode->right);
    
    if(currNode->onlyLeft()) {
        if(!currNode->left->selected) {
            currNode->selected = true;
            ++count;
        }
    }
    
    else if(currNode->onlyRight()) {
        if(!currNode->right->selected) {
            currNode->selected = true;
            ++count;
        }
    }
    
    else if(currNode->isInternal()) {
        //if(!currNode->left->visited || !currNode->right->visited) {
            if(!currNode->left->selected || !currNode->right->selected) {
                currNode->selected = true;
                ++count;
            }
        //}
    }
    
    return 0;
}

template<typename Value>
int BST<Value>::minCover() { //Returns count of min vertex cover
    return DFS(root);
}

template<typename Value>
void BST<Value>::displayMinCover() {
    if (root == 0) return;
    int count = minCover(); // to make selected
    inorder();
    cout << count << endl;
    return;
}

template<typename Value>
void BST<Value>::displayPaths(vector<deque<Node*>> allPaths) {
    for (int i = 0; i < allPaths.size(); ++i) {
        while(!allPaths.at(i).empty()) {
            cout << allPaths.at(i).front()->value << ' ';
            allPaths.at(i).pop_front();
        }
        cout << endl;
    }
    return;
}

template<typename Value>
void BST<Value>::moveQueue(deque<Node*>& target, vector<deque<Node*>>& allPaths) {
    deque<Node*> q;
    allPaths.push_back(q);
    while(!target.empty()) {
        allPaths.back().push_back(target.front());
        target.pop_front();
    }
}

template<typename Value>
void BST<Value>::findSumPath(Node* n, int sum, int buffer[]) {
    
    if (root == 0) {
        cout << 0 << endl;
        return;
    }
    
    static bool hasPath = false;
    static vector<deque<Node*>> allPaths;
    vector<deque<Node*>> leftPaths;
    static deque<Node*> sumPath;
    static Node* subRoot = 0;
    if (n == root) {
        sum -= root->value;
        if (sum == 0) {
            cout << root->value;
            return;
        }
        // cout << sum << endl;
        if (root->hasLeft()) findSumPath(n->left, sum, buffer);
        if (hasPath) moveQueue(sumPath, allPaths); // Move final path onto vector
        
        leftPaths = allPaths;
        allPaths.clear();
        
        if (root->hasRight()) findSumPath(n->right, sum, buffer);
        if (hasPath) moveQueue(sumPath, allPaths);
        
        for (int i = 0; i < leftPaths.size(); ++i) {
            moveQueue(leftPaths.at(i), allPaths);
        }
        
        for (int i = 0; i < allPaths.size(); ++i) { // Final update of stored vectors
            allPaths.at(i).push_back(root); // If there are one or no paths, then nothing happens
        }
        
        if (allPaths.empty()) { // If nothing was found
            cout << 0 << endl;
        }
        else {
            displayPaths(allPaths);
        }
        
        //Pseudo destructor
        hasPath = false;
        allPaths.clear();
        while (!sumPath.empty()) sumPath.pop_front();
        subRoot = 0;
        return;
    }
    
    sum -= n->value;
    if (n->isLeaf() && sum != 0) {
        // cout << "DEBUG: Void ending met at " << n->value << endl;
        return;
    }
    if (n->isLeaf() && sum == 0) {
        // cout << "DEBUG: Path has been found at " << n-> value << endl;
        hasPath = true;
        if (!sumPath.empty()) {
            subRoot = sumPath.back();
            sumPath.pop_back(); // Hard-fixing deque offset
            moveQueue(sumPath, allPaths); // If the case that there is more than one path, backup & kill recent path
        }
        sumPath.push_back(n);
        return;
    }
    
    // cout << sum << endl;
    if (n->hasLeft()) {
        hasPath = false;
        findSumPath(n->left, sum, buffer);
        if (hasPath) {
            sumPath.push_back(n); // Update most recent path
            subRoot = sumPath.back();
        }
    }
    
    if (n->hasRight()) {
        hasPath = false;
        findSumPath(n->right, sum, buffer);
        if (hasPath) {
            sumPath.push_back(n); // This is a new recent path
        }
    }
    
    if (!sumPath.empty() && (n->value == subRoot->value)) {
        for (int i = 0; i < allPaths.size(); ++i) { // Update stored vectors
            allPaths.at(i).push_back(n); // If there are one or no paths, then nothing happens
        }
        hasPath = true;
    }
    
    return;
}

template<typename Value>
void BST<Value>::vertSum(Node* node, int hd, map<int, int>& m) {
    if (root == 0) return;
    static int lowBound = 0;
    static int upBound = 0;
    if (node == root) {
        hd = 0; // Screw the user if they use anything else!
        m[0] = root->value; // Value, Key
        if (root->hasLeft()) {
            vertSum(node->left, -1, m);
        }
        if (root->hasRight()) {
            vertSum(node->right, 1, m);
        }
        
        for (int i = lowBound; i <= upBound; ++i) {
            cout << m[i] << ' ';
        }
        cout << endl;
        lowBound = 0;
        upBound = 0;
        return;
    }
    
    if (hd < lowBound) lowBound = hd;
    else if (hd > upBound) upBound = hd;
    
    m[hd] += node->value;
    
    if (node->isLeaf()) return;
    
    if (node->hasLeft()) {
        vertSum(node->left, hd - 1, m);
    }
    if (node->hasRight()) {
        vertSum(node->right, hd + 1, m);
    }
    return;
}
#endif