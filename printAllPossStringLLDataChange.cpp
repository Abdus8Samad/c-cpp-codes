#include <iostream>
#include <string>

using namespace std;

class Node{
public:
    char data;
    Node* next = NULL;
    Node(){
        data = '\0';
        next = NULL;
    }
    Node(char c){
        next = NULL;
        data = c;
    }
};

Node* createLLFromString(string s){
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        Node* toAdd = new Node(c);
        if(!head){
            head = toAdd;
            tail = toAdd;
        }
        else{
            tail->next = toAdd;
            tail = toAdd;
        }
    }
    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << "";
        temp = temp->next;
    }
    cout << "\n";
}

void swap(Node* head, Node* b){
    int t = b->data;
    b->data = head->data;
    head->data = t;
}

void jumble(Node* head, Node* temp){
    if(!head || !temp) return;
    Node* sp = temp->next;
    while(sp){
        printList(head);
        swap(temp, sp);
        sp = sp->next;
    }
    jumble(head, temp->next);
}


void printAllPoss(Node* head){
    Node* pos = head->next;
    jumble(head, head->next);
    while(pos){
        Node* t = pos->next;
        swap(head, pos);
        jumble(head, head->next);
        pos = t;
    }
}

int main(){
    string s;
    cin >> s;
    Node* head = createLLFromString(s);
    printAllPoss(head);
}