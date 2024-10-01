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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q1;
        vector<double> v1;
        if(!root) return v1;
        q1.push(root);
        while(!q1.empty()){
            int n = q1.size();
            vector<int> v2;
            for(int i =0; i<n; i++) {
                TreeNode* node = q1.front();
                q1.pop();
                v2.push_back(node->val);
                if(node->left)
                   q1.push(node->left);
                if(node->right)
                   q1.push(node->right);
            }
           long long  int sum =0;
            for(auto k: v2){
                if(k <= INT_MAX){
                sum = sum + k;
                }
            }
            double level = v2.size();
            v1.push_back(static_cast<double>(sum/level));
            v2.clear();
        }
        return v1;
    }
};