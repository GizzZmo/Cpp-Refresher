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
int Max(Node*);
int Min(Node*);

int main(int argc, char const *argv[])
{
    int searchEle=-4;
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 0);
    root = Insert(root, -4);
    cout<< "Searching for: " << searchEle << endl;
    string check = Search(root, searchEle) ? "yes" : "no";
    cout<< searchEle << " present : " << check << endl;
    cout << "Max element in tree " << Max(root) <<endl;
    cout << "Min element in tree " << Min(root) <<endl;
    return 0;
}

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

int Max(Node *root) {
    if(root->right==nullptr) {
        return root->data;
    }
    return Max(root->right);
}

int Min(Node *root) {
    if(root->left==nullptr) {
        return root->data;
    }
    return Min(root->left);
}