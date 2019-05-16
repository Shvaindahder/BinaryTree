#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <vector>

using namespace std;

struct Node {
    int value = NULL;
    Node* son = nullptr;
    Node* brother = nullptr;
};


class BinaryTree {
    void deleteTree(Node*);
    void preOrderSearch(Node*);
public:
    Node* root;
    explicit BinaryTree(int value) {
        root = new Node();
        root->value = value;
    }
    void preOrderCombine(BinaryTree&);
    void preOrder(Node*) const;  // Прямой обход
    void inOrder(Node*) const;   // Симметричный обход
    void postOrder(Node*) const; // Обход в обратном порядке
    BinaryTree(const vector<int>);
    void addElement(int value, Node* current=nullptr);
    ~BinaryTree();
};

#endif /* BinaryTree_hpp */
