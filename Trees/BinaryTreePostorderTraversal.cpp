class Solution {
public:

    void postorderTraversalUtil(TreeNode* root, vector<int>& res) {
        if (!root) return;
        postorderTraversalUtil(root->left, res);  
        postorderTraversalUtil(root->right, res);  
        res.push_back(root->val);                  
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversalUtil(root, res);
        return res;
    }
};
/*manikanta*/