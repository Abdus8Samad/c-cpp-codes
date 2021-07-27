#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList(int size)
{
    int val;
    cin >> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout << "\n";
}

Node* reverseLL(Node* a){
    Node* prev = NULL;
    while(a){
        Node* tmp = a->next;
        a->next = prev;
        prev = a;
        a = tmp;
    }
    return prev;
}
Node* addTwoLists(Node* first, Node* second){
    Node* a = first;
    Node* b = second;
    Node* head = NULL;
    Node* tail = NULL;
    a = reverseLL(first);
    b = reverseLL(second);
    int carry = 0;
    while(a || b){
        int x = a ? a->data : 0;
        int y = b ? b->data : 0;
        Node* toAdd = new Node((x + y + carry) % 10);
        if(!head) head = toAdd;
        else tail->next = toAdd;
        carry = (x + y + carry > 9) ? 1 : 0;
        tail = toAdd;
        if(a) a = a->next;
        if(b) b = b->next;
    }
    if(carry == 1) tail->next = new Node(1);
    return reverseLL(head);
}

bool func(Node* head){
    if(!head) return false;
    if(!head->next) return true;
    Node* fastPtr = head;
    Node* slowPtr = head;
    Node* prev = NULL;
    while(fastPtr && fastPtr->next){
        fastPtr = fastPtr->next->next;
        Node* tmp = slowPtr->next;
        slowPtr->next = prev;
        prev = slowPtr;
        slowPtr = tmp;
    }
    cout << slowPtr->data << "\n";
    if(fastPtr && !fastPtr->next) slowPtr = slowPtr->next;
    cout << slowPtr->data << "\n";
    while(prev && slowPtr){
        if(prev->data != slowPtr->data) return false;
        slowPtr = slowPtr->next;
        prev = prev->next;
    }
    return true;
}

int main(){
    // int n, m;
    // cin >> n >> m;
    // Node* first = buildList(n);    
    // Node* second = buildList(m);
    // printList(addTwoLists(first, second));
    int n;
    cin >> n;
    cout << func(buildList(n)) << "\n";
}