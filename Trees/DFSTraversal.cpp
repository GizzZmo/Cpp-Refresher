#include<iostream>
#include"BST.cpp"
using namespace std;

void Preorder(Node*);
void Inorder(Node*);
void Postorder(Node*);

int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 0);
    root = Insert(root, -4);
    root = Insert(root, 12);
    root = Insert(root, 14);
    cout<< "Preorder traversal : "<<endl;
    Preorder(root);
    cout<< endl << "Inorder traversal : "<<endl;
    Inorder(root);
    cout<< endl << "Postoder traversal : "<<endl;
    Postorder(root);
    return 0;
}

void Preorder(Node* rootPtr) {
    if(rootPtr==nullptr)
        return;
    cout<< rootPtr->data << "\t";
    Preorder(rootPtr->left);
    Preorder(rootPtr->right);
}

void Inorder(Node* rootPtr) {
    if(rootPtr==nullptr)
        return;
    Inorder(rootPtr->left);
    cout<< rootPtr->data << "\t";
    Inorder(rootPtr->right);
}

void Postorder(Node* rootPtr) {
    if(rootPtr==nullptr)
        return;
    Postorder(rootPtr->left);
    Postorder(rootPtr->right);
    cout<< rootPtr->data << "\t";
}

