#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(int, Node**, Node**);
void dequeue(Node**, Node**);
void print(Node*);

int main(int argc, char const *argv[])
{
    Node *front = nullptr;
    Node *rear = nullptr;
    enqueue(10, &front, &rear);
    enqueue(5, &front, &rear);
    enqueue(4, &front, &rear);
    enqueue(3, &front, &rear);
    print(front);
    cout<< endl;
    dequeue(&front, &rear);
    print(front);
    cout<< endl;
    dequeue(&front, &rear);
    print(front);
    cout<< endl;
    dequeue(&front, &rear);
    print(front);
    cout<< endl;
    dequeue(&front, &rear);
    print(front);
    dequeue(&front, &rear);
    print(front);
    return 0;
}

void enqueue(int data, Node** frontPtr, Node** rearPtr) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if(*frontPtr == nullptr && *rearPtr==nullptr) {
        *frontPtr = temp;
        *rearPtr = temp;
        return;
    }
    (*rearPtr)->next = temp;
    *rearPtr = temp;
}

void dequeue(Node **frontPtr, Node **rearPtr) {
    Node *temp = *frontPtr;
    if(*frontPtr == nullptr){
        cout << "Queue is empty";
        return;
    }
    if(*frontPtr == *rearPtr) {
        *frontPtr = nullptr;
        *rearPtr = nullptr;
    }
    else {
        *frontPtr = (*frontPtr)->next;
    }
    delete temp;
}

void print(Node *front) {
    if(front!=nullptr) {
        cout<< front->data << "\t";
        print(front->next); 
    }
    return;
}
