#include "BinaryTree.hpp"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree(const vector<int> v) {
    auto begin = v.begin();
    if(begin == v.end()) {
        root = new Node();
    }
    else {
        root = new Node();
        root->value = *begin++;
        for(; begin!=v.end(); begin++)
            addElement(*begin);
    }
}

void BinaryTree::addElement(int value, Node* current) {
    if(current == nullptr) {
        current = root;
    }
    if(current->value > value) {
        if(current->son == nullptr) {
            current->son = new Node();
            current = current->son;
            current->value = value;
        }
        else {
            current = current->son;
            addElement(value, current);
        }

    }
    else {
        if(current->brother == nullptr) {
            current->brother = new Node();
            current = current->brother;
            current->value = value;
        }
        else {
            current = current->brother;
            addElement(value, current);
        }
    }
}

void BinaryTree::preOrderSearch(Node *current) {
    addElement(current->value, root);
    if(current->son)
        preOrderSearch(current->son);
    if(current->brother)
        preOrderSearch(current->brother);
}

void BinaryTree::preOrderCombine(BinaryTree& secondTree) {
    preOrderSearch(secondTree.root);
}

void BinaryTree::preOrder(Node *current) const{
    if(current->son)
        preOrder(current->son);
    if(current->brother)
        preOrder(current->brother);
}

void BinaryTree::inOrder(Node *current) const {
    if(current->son)
        inOrder(current->son);
    cout<<current->value<<'\t';
    if(current->brother)
        inOrder(current->brother);
}

void BinaryTree::postOrder(Node *current) const {
    if(current->son)
        postOrder(current->son);
    if(current->brother)
        postOrder(current->brother);
    cout<<current->value<<'\t';
}

void BinaryTree::deleteTree(Node* currentRoot) {
    if(currentRoot->son != nullptr) {
        deleteTree(currentRoot->son);
        currentRoot->son = nullptr;
    }
    if(currentRoot->brother != nullptr) {
        deleteTree(currentRoot->brother);
        currentRoot->brother = nullptr;
    }
    cout<<currentRoot->value<<"  ";
    delete currentRoot;
}

BinaryTree::~BinaryTree() {
    deleteTree(root);
    cout<<endl;
}
