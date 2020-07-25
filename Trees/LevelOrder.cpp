#include<iostream>
#include"BST.cpp"
#include<queue>

void LevelOrder(Node*);

int main(int argc, char const *argv[])
{
    Node* root = nullptr;
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 0);
    root = Insert(root, -4);
    root = Insert(root, 12);
    root = Insert(root, 14);
    cout<< "Level order traversal : "<<endl;
    LevelOrder(root);
    return 0;
}

void LevelOrder(Node *rootPtr) {
    if(rootPtr==nullptr) {
        cout<< "Tree is empty" ;
        return;
    }
    queue<Node*> levelOrderQ;
    levelOrderQ.push(rootPtr);
    while(!levelOrderQ.empty()) {
        Node* temp = levelOrderQ.front();
        cout << levelOrderQ.front()->data <<"\t";
        if(temp->left!=nullptr) {
            levelOrderQ.push(temp->left);
        }
        if(temp->right!=nullptr) {
            levelOrderQ.push(temp->right);
        }
        levelOrderQ.pop();
    }
}