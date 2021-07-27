#include <iostream>

using namespace std;

#include "linkedList.h";

Node *copyList(Node *head) {
    if(!head) return NULL;
    Node* Head = new Node(head->data);
    Node* tmp = Head;
    Node* temp = head->next;
    while(temp){
        Node* t = new Node(temp->data);
        tmp->next = t;
        tmp = t;
        temp = temp->next;
    }
    return Head;
}

int main(){
    LinkedList l1;
    l1.buildList(5);
    l1.printList(l1.head);
    l1.printList(copyList(l1.head));
}