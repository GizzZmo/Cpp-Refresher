#include<iostream>
#include"InsertTemplate.cpp"
using namespace std;

void Delete(Node **,int);

int main(int argc, char const *argv[])
{
    Node* head = nullptr;
    Insert(&head, 10);
    Insert(&head, 3);
    Insert(&head, 56);
    Insert(&head, 12);
    Insert(&head, 67);
    Print(head);
    cout<< "\n";
    Delete(&head, 3);
    Print(head);
    cout<< "\n";
    Delete(&head, 4);
    Print(head);
    cout<< "\n";
    Delete(&head,1);
    Print(head);
    return 0;
}

void Delete(Node **tempHead, int pos){
    Node *temp = *tempHead;

    if(pos==1) {
        *tempHead = (*tempHead)->next;
        delete temp;
        return;
    }

    for(int i=1;i<pos-1;i++) {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}
