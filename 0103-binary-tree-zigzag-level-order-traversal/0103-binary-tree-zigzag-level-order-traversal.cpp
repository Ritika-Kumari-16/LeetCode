/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if (root != NULL)
            q.push({root, 0});
        int i = 0;
        while (!q.empty()) {
            int x = (q.front()).second;
            i = max(i, x + 1);
            TreeNode* temp = q.front().first;

            if ((temp->left) != NULL) {
                q.push({temp->left, x + 1});
            }
            if ((temp->right) != NULL) {
                q.push({temp->right, x + 1});
            }
            q.pop();
        }
        vector<vector<int>> ans(i);
        if (root != NULL)
            q.push({root, 0});
        while (!q.empty()) {
            TreeNode* temp = q.front().first;

            int y = q.front().second;

            int x = (q.front().first)->val;
            ans[y].push_back(x);

            
                if (temp->left != NULL) {
                    q.push({temp->left, y + 1});
                }
                if (temp->right != NULL) {
                    q.push({temp->right, y + 1});
                }
           
            q.pop();
        }
        for(int j=1;j<i;j+=2){
            int x=0;
            int y=ans[j].size()-1;
            while(x<y){
                swap(ans[j][x],ans[j][y]);
                x++;
                y--;
            }
        }
        return ans;

    }
    

};