#include<iostream>
#include"BST.cpp"
#include<climits>
using namespace std;

bool isBST(Node *, int , int);
 
int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 0);
    root = Insert(root, -4);
    root = Insert(root, 12);
    root = Insert(root, 14);
    isBST(root, INT_MAX, INT_MIN) ? cout << "Tree is BST " : cout << "Tree not BST";
    return 0;
}

bool isBST(Node *rootPtr, int maxValue, int minValue) {
    if(rootPtr == nullptr) {
        return true;
    }
    else if(rootPtr->data >= minValue && rootPtr->data < maxValue && isBST(rootPtr->left, rootPtr->data, minValue) && isBST(rootPtr->right, maxValue, rootPtr->data)) {
        return true;
    }
    else {
        return false;
    }
}
