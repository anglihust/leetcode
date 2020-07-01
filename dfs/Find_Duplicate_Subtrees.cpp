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
 //serilized tree with preorder/postorder(not inorder) and record the each subtree in string
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> store;
         vector<TreeNode*> ans;
        dfs(root,store,ans);
        return ans;
    }
    
    string dfs(TreeNode* root, unordered_map<string,int> &store,vector<TreeNode*> &ans){
        if(root==NULL) return "#";
        string temp =  to_string(root->val)+dfs(root->left,store,ans)+dfs(root->right,store,ans);
        store[temp]++;
        if(store[temp]==2) ans.push_back(root);
        return temp;
    }
};
