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
    TreeNode* buildTreeinpre(vector<int>& preorder, int sp , int ep , vector<int>&inorder , int si , int ei , unordered_map<int,int>&mp){
        if(sp > ep || si > ei) return NULL ;
        TreeNode* root = new TreeNode(preorder[sp]);
        int inroot = mp[preorder[sp]];
        int numsleft=inroot-si;
        root->left=buildTreeinpre(preorder, sp+1,sp+numsleft , inorder , si, inroot-1,mp);
        root->right=buildTreeinpre(preorder, sp+numsleft+1, ep , inorder, inroot+1, ei, mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()) return NULL ;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root = buildTreeinpre(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , mp);
        return root;

        
    }
};