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
    int heightleft(TreeNode* node){
        int hgt=0;
        while(node){
            hgt++;
            node=node->left;
            
        }
        return hgt;
    }
    int heightright(TreeNode* node){
        int hgt=0;
        while(node){
            hgt++;
            node=node->right;
            
        }
        return hgt;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=heightleft(root);
        int rh=heightright(root);
        if(rh==lh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};