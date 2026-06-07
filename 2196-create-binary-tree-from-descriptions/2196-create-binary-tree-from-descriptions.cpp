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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> node_map;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parent_val = desc[0];
            int child_val  = desc[1];
            bool is_left    = desc[2] == 1;

            if (!node_map.count(parent_val)) {
                node_map[parent_val] = new TreeNode(parent_val);
            }
            if (!node_map.count(child_val)) {
                node_map[child_val] = new TreeNode(child_val);
            }

            if (is_left) {
                node_map[parent_val]->left = node_map[child_val];
            } else {
                node_map[parent_val]->right = node_map[child_val];
            }

            children.insert(child_val);
        }

        for (auto& [val, node] : node_map) {
            if (!children.count(val)) {
                return node;
            }
        }

        return nullptr; 
    }
};