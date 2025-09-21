struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k , int v){
        key=k;
        val=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
unordered_map<int,Node*>mpp;
Node* head;
Node* tail;
int capa;
void deletenode(Node* node){
    Node* prevnode= node->prev;
    Node* nextnode=node->next;
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
    delete(node);
}
void insertnode(Node* node){
    Node* temp=node;
    Node* prevnode= tail->prev;
    prevnode->next=temp;
    temp->prev=prevnode;
    temp->next=tail;
    tail->prev=temp;
}
    LRUCache(int capacity) {
        capa=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node= mpp[key];
        int value = node->val;
        deletenode(node);
        mpp.erase(key);
        Node* newnode= new Node(key,value);
        insertnode(newnode);
        mpp[key]=newnode;
        return value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)==mpp.end() && mpp.size()==capa){
            Node* node= head->next;
            int key1=node->key;
            deletenode(node);
            mpp.erase(key1);
        }
        else if(mpp.find(key)!=mpp.end()){
            Node* node= mpp[key];
            mpp.erase(key);
            deletenode(node);
        }
        Node* newnode= new Node(key,value);
        insertnode(newnode);
        mpp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */