#include "BinaryTree.hpp"
#include <iostream>

using namespace std;

void BinaryTree::addElement(int value, Node* current) {
    if(current==nullptr) {
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
