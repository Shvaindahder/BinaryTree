#include "BinaryTree.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
    BinaryTree tree(10);
    tree.addElement(3);
    tree.addElement(10);
    tree.addElement(31);
    tree.addElement(1);
    tree.addElement(13);
    tree.addElement(5);
    tree.addElement(7);
    vector<int> v = {5, 7, 3, 9, 4, 1, 8, 11, 0, 4, 10};
    BinaryTree tree2(v);
    tree.preOrder(tree.root);
    cout<<"\npreOrder   ";
    tree2.preOrder(tree2.root);
    std::cout<<std::endl;
    cout<<"inOrder    ";
    tree2.inOrder(tree2.root);
    std::cout<<std::endl;
    cout<<"postOrder  ";
    tree2.postOrder(tree2.root);
    std::cout<<std::endl;
    tree.preOrderCombine(tree2);
    std::cout<<std::endl;
    return 0;
}
