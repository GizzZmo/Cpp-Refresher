#include<iostream>
#include<string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int);
Node* Insert(Node*, int);
bool Search(Node*, int);
Node* SearchElement(Node*, int);

Node* Insert(Node *root, int data) {
    if(root == nullptr) {
        root = GetNewNode(data);
        return root;
    }
    else if(root->data>= data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

Node* GetNewNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

bool Search(Node* root, int data) {
    if(root==nullptr) {
        return false;
    }
    if(root->data == data) {
        return true;
    }
    if(root->data >= data ) {
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

Node* SearchElement(Node* root, int data) {
    if(root==nullptr) {
        return nullptr;
    }
    if(root->data == data) {
        return root;
    }
    if(root->data >= data ) {
        return SearchElement(root->left, data);
    }
    else {
        return SearchElement(root->right, data);
    }
}