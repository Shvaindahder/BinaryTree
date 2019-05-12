#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
struct Node {
    int value;
    Node* son = nullptr;
    Node* brother = nullptr;
};


class BinaryTree {
    void deleteTree(Node*);
public:
    Node* root;
    explicit BinaryTree(int value) {
        root = new Node();
        root->value = value;
    }
    void addElement(int value, Node* current=nullptr);
    ~BinaryTree();
};

#endif /* BinaryTree_hpp */
