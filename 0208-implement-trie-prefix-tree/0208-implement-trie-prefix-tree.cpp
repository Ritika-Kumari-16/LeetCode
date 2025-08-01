struct Node{
    public:
    Node* links[26];
    bool flag=false;
    bool containskey(char ch){
        return (links [ch-'a']!=NULL);
    }
    void put(char ch , Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag=true;
    }
    bool getend(){
        return flag;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setend();

    }
    bool search(string word) {
       Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->getend();
    }
    
    bool startsWith(string word) {
       Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */