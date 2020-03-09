/*
Given a binary tree, determine if it is a valid binary search tree (BST).
  
    2
   / \
  1   2

Output: true

struct Node {
  int val;
  Node* left, right;
}  

1. All the values in the left child are smaller than the father. 
2. All the values in the right chidl are greater or equal than the father,

---> node value = 2
    ----> left child 
          node value = 1
          
-> Left child exist
-> Right chid exist
-> left and right chid exist
-> Node is a null point
*/
struct Node {
  int val;
  Node *left, *right;
}

bool isBinarySearchTree(Node *father) { // 2
    if(father == NULL) {
      return false;
    } 
    if(father->left == NULL && father->right == NULL) { // Right and left child doesnt exist
      return false;
    }
  
    bool ans = false;
    if(father->right == NULL  && father->left) { // Just the left chidl exist
      if(father->left->val < father->val) { // Left child exist
        ans = true;
      }
    } else if(father->left == NULL && father->right) { // Right child exist
      if((father->val <= father->right->val)) { 
        ans = true;
      }
    } else if(father->left && father->right) { // Left and right child exist // fval = 2, fRightV = 2 
        // true, true, true, true
      if(father->val <= father->right->val && father->left->val < father->val) {
         ans = true;
     }
    }
    if(ans && isBinarySearchTree(father->right) && isBinarySearchTree(father->left)) {
      ans = true;
    }
    return ans;
}


// [1, 2, 3]

//          5
//        /    \
//       3      9
//      / \    / \
//     1   4  8   10  


// preorder:   5, 3, 1, 4, 9, 8, 10
// inorder:    1, 3, 4, 5, 8, 9, 10
// postorder:  1, 4, 3, 8, 10, 9, 5
void traversalINORDER(Node *root) {
  if(root == NULL) {
    return;
  }
  traversal(root->left);
  cout << root->value << " ";
  traversal(root->right);
}
void traversalPREORDER(Node *root) {
  if(root == NULL) {
    return;
  }
  cout << root->value << " ";
  traversal(root->left);
  traversal(root->right);
}
void traversalPOSTORDEN() {
  if(root == NULL) {
    return;
  } 
  traversal(root->left);
  traversal(root->right);
  cout << root->value << " ";
}
