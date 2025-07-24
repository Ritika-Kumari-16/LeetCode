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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxwidth=0;
        while(!q.empty()){
            int s=q.size();
            int mini=q.front().second;
            int frst,last;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front().first;
                long long curid=q.front().second-mini;
                q.pop();
                if(i==0) frst=curid;
                if(i==s-1) last=curid;
                if(node->left) q.push({node->left,curid*2+1});
                if(node->right) q.push({node->right,curid*2+2});
            }
            maxwidth=max(maxwidth,int(last-frst+1));
        }
        return maxwidth;
    }
};