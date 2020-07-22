#include<iostream>
#include"InsertTemplate.cpp"
using namespace std;

Node* Reverse(Node *);

int main(int argc, char const *argv[])
{
    Node *head = nullptr;
    Insert(&head, 10);
    Insert(&head, -1);
    Insert(&head, 2);
    Insert(&head, 4);
    Insert(&head, -10);
    cout << "Before reversing : "<< endl;
    Print(head);
    cout<< endl << head <<endl;
    head = Reverse(head);
    cout << "After reversing : "<< endl;
    cout << endl << head << endl;
    Print(head);
    return 0;
}

Node* Reverse(Node *headPtr) {
    if(headPtr == nullptr){
        return headPtr;
    }
    Node* temp = headPtr;
    if(temp->next == nullptr) {
       return temp;
    }
    headPtr =  Reverse(temp->next);
    temp->next->next = temp;
    temp->next = nullptr;
    return headPtr;
}


