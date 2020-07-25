#include"BST.cpp"

int Max(Node*);
int Min(Node*);

int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 0);
    root = Insert(root, -4);
    cout << "Max element in tree " << Max(root) <<endl;
    cout << "Min element in tree " << Min(root) <<endl;
    return 0;
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