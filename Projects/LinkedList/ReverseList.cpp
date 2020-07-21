#include<iostream>
#include"InsertTemplate.cpp"
using namespace std;

Node* Reverse(Node*);
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
    head = Reverse(head);
    cout << "\n After reversing \n";
    Print(head);
    return 0;
}

Node* Reverse(Node* headPtr) {
    Node *prev = nullptr;
    Node *curr = headPtr;
    while(curr!=nullptr) {
        Node *next = curr-> next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    headPtr = prev;
    return headPtr;
}
