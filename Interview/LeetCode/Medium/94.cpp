void inorderValues(vector<int> &inorder, TreeNode *root) {
    if(!root) return;
    inorderValues(inorder, root->left);
    inorder.push_back(root->val);
    inorderValues(inorder, root->right);
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    inorderValues(inorder, root);
    return inorder;
}
