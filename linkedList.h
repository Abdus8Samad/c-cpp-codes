class Node{
public:
    int data;
    Node* next;
    Node(){
        data = -1;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        next = NULL;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

class LinkedList{
public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    LinkedList(Node* head){
        this->head = head;
    }
    void buildList(int size){
        int val;
        cin >> val;
        Node* head = new Node(val);
        Node* tail = head;
        for(int i=0; i<size-1; i++){
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        this->head = head;
    }
    void printList(Node* n){
        while(n){
            cout << n->data << " ";
            n = n->next;
        }
        cout << "\n";
    }
};