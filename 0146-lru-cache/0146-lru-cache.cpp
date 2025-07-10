
class LRUCache {
    public:
    struct Node{
    int key;
    int value;
    Node* prev ;
    Node* next;
    Node(int key1 , int val1){
        key=key1;
        value=val1;
    }
};
    map<int,Node*>mpp;
    int capacity;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
public:
    LRUCache(int capacity1) {
        capacity=capacity1;
        head->next=tail;
        tail->prev=head;
    }
    void insertnode(Node * temp){
        Node * after= head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=after;
        after->prev=temp;
    }
    void deletenode(Node* temp){
        Node* before = temp->prev;
        Node* after= temp->next;
        before->next=after;
        after->prev=before;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
            Node* temp = mpp[key];
            int val= temp->value;
            deletenode(temp);
            insertnode(temp);
            mpp[key]=head->next;
            return val;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* temp = mpp[key];
            temp->value= value;
            deletenode(temp);
            insertnode(temp);
            mpp[key]=head->next;
        }
        else{
            Node* tempnode= new Node(key,value);
            if(mpp.size()==capacity){
                Node* temp1= tail->prev;
                mpp.erase(temp1->key);
                deletenode(tail->prev);
            }
            insertnode(tempnode);
            mpp[key]=tempnode;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */




//  class LRUCache {
//     public:
//     struct Node{
//         public:
//             int key ;
//             int val;
//             Node* prev;
//             Node* next;
//             Node(int key_, int val_){
//                 key=key_;
//                 val=val_;
//             }

// };
//     int cap;
//     map<int,Node*>mpp;
//     Node* head= new Node(-1,-1);
//     Node* tail= new Node(-1,-1);

// public:

//     LRUCache(int capacity) {
//         cap=capacity;
//         mpp.clear();
//         head->next=tail;
//         tail->prev=head;
//     }

// void insertnode(Node* node){
//     Node* temp = head->next;
//     node->next=temp;
//     temp->prev=node;
//     head->next=node;
//     node->prev=head;

// }
// void deletenode( Node* node){
//     Node* temp = node->prev;
//     Node* tempnxt=node->next;
//     temp->next=tempnxt;
//     tempnxt->prev=temp;
// }
//     int get(int key) {
//         if(mpp.find(key)==mpp.end()) return -1;
//         Node* reqval= mpp[key];
//         mpp.erase(key);
//         deletenode(reqval);
//         insertnode(reqval);
//         mpp[key]=head->next;
//         return reqval->val; 
//     }
    
//     void put(int key, int value) {
//         if(mpp.find(key)!=mpp.end()){
//             Node* reqval= mpp[key];
//             reqval->val=value;
//             mpp.erase(key);
//             deletenode(reqval);
//             insertnode(reqval);
//             mpp[key]=head->next;
//         }
//         else{
//             Node* newnode= new Node(key,value);
//             if(mpp.size()==cap){
//                 mpp.erase(tail->prev->key);
//                 deletenode(tail->prev);

//             }
//             insertnode(newnode);
//             mpp[key]=newnode;
//         }
        
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */