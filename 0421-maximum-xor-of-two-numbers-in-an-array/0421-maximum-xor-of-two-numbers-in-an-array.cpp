// Node structure for Trie
struct Node {
    // Array to store links to child nodes,
    // each index represents a letter
    Node* links[2];
    // Check if the node contains
    // a specific key (letter)
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    // Insert a new node with a specific
    // key (letter) into the Trie
    void put(int bit, Node* node) {
        links[bit] = node;
    }

    // Get the node with a specific
    // key (letter) from the Trie
    Node* get(int bit) {
        return links[bit];
    }
};
class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    public:
    void insert(int num){
        Node* node = root;
        for( int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    public:
    int getmax(int num){
        Node* node= root;
        int maxnum=0;
        for( int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxnum= maxnum | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxnum;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it:nums){
            trie.insert(it);
        }
        int maxi=0;
        for(auto &it:nums){
            maxi=max(maxi,trie.getmax(it));
        }
        return maxi;
    }
};