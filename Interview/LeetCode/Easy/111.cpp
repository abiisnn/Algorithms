// Recursive
int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    int consider = std::min(left, right);
    if(!left) {
        consider = right;
    } else if(!right) {
        consider = left;
    }
    return 1 + consider;
}
// Iterative
int minDepth(TreeNode* root) {
    if(root == NULL) return 0;
    
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 1));
    
    int currentLevel = 1;
    while(!q.empty()) {
        pair<TreeNode*, int> node = q.front();
        q.pop();            
        if(node.first->left == NULL && node.first->right == NULL) {
            currentLevel = node.second;
            break;
        }
        if(node.first->left) q.push(make_pair(node.first->left, node.second+1));              
        if(node.first->right) q.push(make_pair(node.first->right, node.second+1));
    }
    return currentLevel;
}