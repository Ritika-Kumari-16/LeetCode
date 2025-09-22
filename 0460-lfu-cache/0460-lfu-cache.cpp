struct Node{
    int key;
    int val;
    int count;
    Node* prev;
    Node* next;
    Node(int k , int v){
        key=k;
        val=v;
        count=1;
        prev=NULL;
        next=NULL;
    }
};
struct List{
    Node* head;
    Node* tail;
    int size;
    List(){
        head= new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void insertnode(Node* node){
        Node* prevnode= tail->prev;
        prevnode->next=node;
        node->prev=prevnode;
        node->next=tail;
        tail->prev=node;
        size++;
    }
    void removenode(Node* node){
        Node* prevnode=node->prev;
        Node* nextnode=node->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        size--;
    }
};
class LFUCache {
public:
map<int,List*>freqlist;
map<int,Node*>keynode;
int cap;
int cursize;
int minfreq;

void updatefreq(Node* node){
    keynode.erase(node->key);
    freqlist[node->count]->removenode(node);
    if(node->count==minfreq && freqlist[node->count]->size==0){
        minfreq++;
    }
    List* newlist= new List();
    if(freqlist.find(node->count+1)!=freqlist.end()){
        newlist=freqlist[node->count+1];
    }
    node->count+=1;
    newlist->insertnode(node);
    freqlist[node->count]=newlist;
    keynode[node->key]=node;
}
    LFUCache(int capacity) {
        cap=capacity;
        cursize=0;
        minfreq=0;
    }
    
    int get(int key) {
        if(keynode.find(key)==keynode.end()) return -1;
        Node* node= keynode[key];
        int value= node->val;
        updatefreq(node);
        return value;
    }
    
    void put(int key, int value) {
        if(cap==0) return ;
        if(keynode.find(key)!=keynode.end()){
            Node* node= keynode[key];
            node->val=value;
            updatefreq(node);
        }
        else{
            if(cursize==cap){
                List* temp=freqlist[minfreq];
                keynode.erase(temp->head->next->key);
                freqlist[minfreq]->removenode(temp->head->next);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List* newlist= new List();
            if(freqlist.find(minfreq)!=freqlist.end()){
                newlist=freqlist[minfreq];
            }
            Node* node= new Node(key,value);
            keynode[key]=node;
            newlist->insertnode(node);
            freqlist[minfreq]=newlist;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */