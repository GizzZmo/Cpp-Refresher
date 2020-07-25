#include<iostream>
#include"BST.cpp"
using namespace std;

Node *GetSuccessor(Node *, int);
Node *FindMin(Node*);

int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 16);
    root = Insert(root, 0);
    root = Insert(root, -4);
    root = Insert(root, 12);
    root = Insert(root, 14);
    root = Insert(root, 11);
    root = Insert(root, 17);
    root = Insert(root, 15);
    cout << "Inorder successor of 14 is " <<GetSuccessor(root, 14)->data;
    return 0;
}

Node* GetSuccessor(Node *root, int val) {
    Node *current = SearchElement(root, val);

    // Case 1 : Right subtree is present
    if(current->right!=nullptr) {
        return FindMin(current->right);
    }
    // Case 2
    else {
        Node* ancestor = root;
        Node* successor = nullptr;

        while(current!=ancestor) {
            if(ancestor->data > current->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    } 
}

Node *FindMin(Node* rootPtr) {
    if(rootPtr->left==nullptr)
        return rootPtr;
    return FindMin(rootPtr->left);
}
