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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if((p==NULL && q!=NULL ) || (p!=NULL && q==NULL)) return false;
        if(p->val !=q->val) return false;
        bool lt=isSameTree(p->left,q->left);
        bool rt=isSameTree(p->right,q->right);
        if(lt==true && rt==true) return true;
        return false;
    }
};