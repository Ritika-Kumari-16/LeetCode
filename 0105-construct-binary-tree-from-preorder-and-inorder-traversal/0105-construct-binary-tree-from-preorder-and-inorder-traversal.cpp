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
TreeNode* build(vector<int>&preorder , int ps , int pe , vector<int>&inorder , int is , int ie,unordered_map<int,int>&mpp){
    if(ps>pe || is>ie) return NULL;
    TreeNode*node=new TreeNode(preorder[ps]);
    int idx=mpp[node->val];
    int leftel=idx-is;
    node->left=build(preorder,ps+1,ps+leftel,inorder,is,idx-1,mpp);
    node->right=build(preorder,ps+leftel+1,pe,inorder,idx+1,ie,mpp);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};