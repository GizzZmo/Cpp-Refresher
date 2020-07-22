#include<iostream>
#include"InsertTemplate.cpp"
using namespace std;

void Reverse(Node*);

int main(int argc, char const *argv[])
{
    Node* head = nullptr;
    Insert(&head, 10);
    Insert(&head, 51);
    Insert(&head, 5);
    Insert(&head, 77);
    Insert(&head, 2);
    cout<< "Before reversing : \n";
    Print(head);
    cout<< endl<< "Printing in reverse order \n";
    Reverse(head);
    return 0;
}

void Reverse(Node* headPtr) {
    if(headPtr!=nullptr) {
        Reverse(headPtr->next);
        cout<<headPtr->data<< "\t";
    }
    return;
}