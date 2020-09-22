vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> order;
    queue<pair<TreeNode*, int>> bfs; 
    if(root) bfs.push(make_pair(root, 0));
    
    int last = -1;
    while(!bfs.empty()) {
        pair<TreeNode*, int> node = bfs.front();
        bfs.pop();
        
        if(last != node.second) {
            order.push_back(vector<int>(0));
            last = node.second;
        }
        order[node.second].push_back(node.first->val);
        if(node.first->left) {
            bfs.push(make_pair(node.first->left, node.second + 1));
        }
        if(node.first->right) {
            bfs.push(make_pair(node.first->right, node.second + 1));
        }
    }
    return order;

void fillOrder(vector<vector<int>> &order, TreeNode* root, int current) {
    if(root == NULL) return;
    if(current + 1 > order.size()) {
        order.push_back(vector<int>(0));
    }
    order[current].push_back(root->val);
    fillOrder(order, root->left, current + 1);
    fillOrder(order, root->right, current + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> order;
    fillOrder(order, root, 0);
    return order;
}