#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head;

void Insert(int, int);
void Print(Node *);

int main(int argc, char const *argv[])
{
    head = nullptr;
    Insert(10, 1);
    Insert(34, 2);
    Insert(46,3);
    Insert(67,2);
    Insert(8, 1);
    Print(head);
    return 0;
}

void Insert(int data, int pos){

    Node * tempPos = head;

    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    if(pos==1) {
        temp-> next = head;
        head =temp;
        return;
    }

    for(int i=1;i<pos-1;i++){
        tempPos = tempPos->next;
    }

    temp->next = tempPos->next;
    tempPos->next = temp;

}

void Print(Node* headPtr) {

    while(headPtr != nullptr) {
        cout<< headPtr->data << "\t";
        headPtr = headPtr->next;
    }
}