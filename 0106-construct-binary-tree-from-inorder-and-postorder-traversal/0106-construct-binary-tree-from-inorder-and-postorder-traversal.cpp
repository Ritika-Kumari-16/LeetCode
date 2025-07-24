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
TreeNode* build(vector<int>&postorder , int ps , int pe , vector<int>&inorder , int is , int ie,unordered_map<int,int>&mpp){
    if(ps>pe || is>ie) return NULL;
    TreeNode* node= new TreeNode(postorder[pe]);
    int inroot=mpp[node->val];
    int leftel=inroot-is;
    node->left=build(postorder,ps,ps+leftel-1,inorder,is,ie+leftel-1,mpp);
    node->right=build(postorder,ps+leftel,pe-1,inorder,inroot+1,ie,mpp);
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(postorder.size()==0) return NULL;
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
        
    }
};