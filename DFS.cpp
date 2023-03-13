//For example:
//Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.back()->val);
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ret;
      helper(root, 1, ret);
      return ret;
    }
    void helper(TreeNode* node, int level, vector<int>& values){
      if(!node) return; 
      if(values.size() < level) values.push_back(node->val);
      helper(node->right, level+1, values);
      helper(node->left, level+1, values);
    }
};
