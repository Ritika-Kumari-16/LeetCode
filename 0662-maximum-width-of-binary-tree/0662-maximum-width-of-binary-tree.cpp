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
    typedef long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        ll ans=0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,ll >>q;
        q.push({root,0});
        while(!q.empty()){
            ll  sz = q.size();
            ll mini= q.front().second;
            ll first, last;
            for(int i=0;i<sz;i++){
                TreeNode* node= q.front().first;
                ll curr_id=q.front().second-mini;
                q.pop();
                if(i==0) first=curr_id;
                if(i==sz-1) last=curr_id;
                ans=max(ans, last-first+1);
                if(node->left) {
                    q.push({node->left,curr_id*2+1});
                }
                if(node->right) {
                    q.push({node->right,curr_id*2+2});
                }

            }

        }
        return ans;
    }
};