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
    TreeNode* buildTreeinpost(vector<int>& postorder, int sp , int ep , vector<int>&inorder , int si , int ei , unordered_map<int,int>&mp){
        if(sp > ep || si > ei) return NULL ;
        TreeNode* root = new TreeNode(postorder[ep]);
        int inroot = mp[postorder[ep]];
        int numsleft=inroot-si;
        root->left=buildTreeinpost(postorder, sp,sp+numsleft-1 , inorder , si, inroot-1,mp);
        root->right=buildTreeinpost(postorder, sp+numsleft, ep-1 , inorder, inroot+1, ei, mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()!=inorder.size()) return NULL ;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = buildTreeinpost(postorder , 0 , postorder.size()-1 , inorder , 0 , inorder.size()-1 , mp);
        return root;
    }
};