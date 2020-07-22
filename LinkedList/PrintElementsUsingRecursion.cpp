#include<iostream>
#include"InsertTemplate.cpp"
using namespace std;

void PrintInNormalOrder(Node*);

int main(int argc, char const *argv[])
{
    Node* head = nullptr;
    Insert(&head, 10);
    Insert(&head, 51);
    Insert(&head, 5);
    Insert(&head, 77);
    Insert(&head, 2);
    Print(head);
    return 0;
}

void PrintInNormalOrder(Node* headPtr) {
    if(headPtr!=nullptr) {
        cout<<headPtr->data<< "\t";
        Print(headPtr->next);
    }
    return;
}