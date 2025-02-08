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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int siz=q.size();
            vector<int>temp;
            for(int i=0;i<siz;i++){
                TreeNode* nwnode=q.front();
                q.pop();
                temp.push_back(nwnode->val);
                if(nwnode->left!=NULL){
                    q.push(nwnode->left);
                }
                if(nwnode->right!=NULL){
                    q.push(nwnode->right);
                }
            }
            ans.push_back(temp);

        }
        int i=ans.size()-1;
        int j=0;
        while(j<i){
            swap(ans[j],ans[i]);
            j++;
            i--;
        }
        return ans;
    }
};