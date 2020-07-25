#include"BST.cpp"
#include<algorithm>
int Height(Node*);

int main(int argc, char const *argv[])
{
    
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 0);
    root = Insert(root, -4);
    cout << "Height of the tree is : "<< Height(root);
    return 0;
}

int Height(Node *rootPtr) {
    if(rootPtr == nullptr) {
        return -1;
    }
    return max(Height(rootPtr->left), Height(rootPtr->right))+1;
}


