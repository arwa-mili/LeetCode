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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

       return dfs(root1, root2);
    
    }


    TreeNode* dfs(TreeNode* root1, TreeNode* root2) {

        if (!root1 && !root2){
            return nullptr;
        }

        int value1 = root1 != nullptr ? root1->val : 0;
        int value2 = root2 != nullptr ?  root2->val : 0;

        int sum = value1 + value2;

        TreeNode* node = new TreeNode(sum);

        node->left = dfs(root1 != nullptr ? root1 -> left : nullptr,root2 != nullptr ? root2 -> left : nullptr);
        node->right = dfs(root1 != nullptr ? root1 -> right : nullptr,root2 != nullptr ? root2 -> right : nullptr);
        return node;

    }
};