/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // // Method 1 - using map -> TC = SC = O(N)
    // bool solve(TreeNode* root, int k, unordered_set<int> &s){
    //     if(!root){
    //         return false;
    //     }

    //     if(s.find(k - root -> val) != s.end()){
    //         return true;
    //     }

    //     s.insert(root -> val);

    //     bool leftAns = solve(root -> left, k, s);
    //     bool rightAns = solve(root -> right, k, s);

    //     return leftAns || rightAns;
    // }

    // bool findTarget(TreeNode* root, int k) {
    //     unordered_set<int> s;
    //     return solve(root,k,s);
    // }



    // Method 2 - using 2 pointers -> TC = SC = O(N) -> SINCE IN BST Inorder is sorted to store that and apply 2 pointers
    void inorder(TreeNode* root, vector<int> &v){
        if(!root){
            return;
        }
        
        inorder(root -> left, v);

        v.push_back(root -> val);

        inorder(root -> right, v);

    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);

        int s = 0, e = v.size()-1;
        while(s < e){
            if(v[s] + v[e] == k){
                return true;
            }
            else if(v[s] + v[e] < k){
                s++;
            }
            else{
                e--;
            }
        }
        return false;
    }
};