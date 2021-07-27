#include <iostream>
#include <stack>

using namespace std;

// time -> O(n)
// space -> O(1)

class StackNode{
public:
    int data;
    StackNode* next;
    StackNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

class llStack{
public:
    StackNode* head;
    int size;
    llStack(){
        this->head = NULL;
        this->size = 0;
    }
    void push(int data){
        StackNode* add = new StackNode(data);
        add->next = head;
        head = add;
        size++;
    }
    int pop(){
        if(!head) return -1;
        int ret = head->data;
        StackNode* rem = head;
        head = head->next;
        delete rem;
        size--;
        return ret;
    }
    int top(){
        if(!head) return -1;
        return head->data;
    }
    bool empty(){
        return size == 0;
    }
};

void reverseStack(llStack& s){
    if(!s.head) return;
    StackNode* prev = NULL;
    StackNode* temp = s.head;
    while(temp){
        StackNode* tmp = temp->next;
        temp->next = prev;
        prev = temp;
        temp = tmp;
    }
    s.head = prev;
}

int main(){
    int n;
    cin >> n;
    llStack s;
    while(n--){
        int temp;
        cin >> temp;
        s.push(temp);
    }
    reverseStack(s);
    while(!s.empty()){
        cout << s.top() << ", ";
        s.pop();
    }
}