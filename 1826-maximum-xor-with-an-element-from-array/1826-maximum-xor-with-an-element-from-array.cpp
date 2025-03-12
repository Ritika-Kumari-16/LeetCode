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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>oq;
        int q= queries.size();
        for(int i=0;i<q;i++){
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        Trie trie;
        vector<int>ans(q,0);
        int ind=0;
        for(int i=0;i<q;i++){
            int ai=oq[i].first;
            int xi=oq[i].second.first;
            int qind= oq[i].second.second;
            while(ind<n && nums[ind]<=ai){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0){
                ans[qind]=-1;
            }
            else{
                ans[qind]=trie.getmax(xi);
            }
        }
        return ans;
    }
};