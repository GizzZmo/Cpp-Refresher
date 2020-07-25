#include<iostream>
#include"BST.cpp"
using namespace std;

Node* Delete(Node*, int);
Node* FindMax(Node*);
void Inorder(Node *);

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
    cout << "Inorder traversal before deletion : "<<endl;
    Inorder(root);
    root = Delete(root, 16);
    cout << endl << "Inorder traversal after deletion : "<<endl;
    Inorder(root);
    return 0;
}

Node* Delete(Node *rootPtr, int val) {
    if(rootPtr==nullptr) {
        return nullptr;
    }
    else if(rootPtr->data > val) {
        rootPtr->left = Delete(rootPtr->left, val);
    }
    else if(rootPtr->data < val) {
        rootPtr->right = Delete(rootPtr->right, val);
    }
    else {
        /* Case 1 : Leaf node */
        if(rootPtr->left==nullptr && rootPtr->right==nullptr) {
            delete rootPtr;
            rootPtr = nullptr;
        }
        // Case 2 : One leaf node 
        else if(rootPtr->left == nullptr) {
           Node *temp =  rootPtr;
           rootPtr = rootPtr->right;
           delete temp;
        }
        else if(rootPtr->right == nullptr) {
           Node *temp =  rootPtr->left;
           rootPtr = rootPtr->left;
           delete temp;
        }
        // Case 3 : two children
        else {
            Node *maxLeft = FindMax(rootPtr->left);
            rootPtr->data = maxLeft->data;
            rootPtr->left = Delete(rootPtr->left, maxLeft->data);
        }
    }
    return rootPtr;
}

Node* FindMax(Node *rootPtr) {
    if(rootPtr->right==nullptr) {
        return rootPtr;
    }
    return FindMax(rootPtr->right);
}

void Inorder(Node* rootPtr) {
    if(rootPtr==nullptr)
        return;
    Inorder(rootPtr->left);
    cout<< rootPtr->data << "\t";
    Inorder(rootPtr->right);
}