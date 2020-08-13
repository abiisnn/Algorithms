/*             5
            3     9
          1  4   8  10
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* left, *right;
  int val;
  Node(int v, Node* l = NULL, Node* r = NULL) : val(v), left(l), right(r) {}
};
  
bool getPath(Node *root, Node *target, vector<Node *> &path) {
  if(root == NULL) {
    return false;
  }
  if(root == target) {
    path.push_back(root);
    return true;
  }
  if(getPath(root->left, target, path) or getPath(root->right, target, path)) {
    path.push_back(root);
    return true;
  } 
  return false;
}
Node* getFirstEqualElement(vector<Node *> &a, vector<Node *> &b) {
  Node * ans = NULL;
  // set = [10, 9, 5]
  // [4, 3, 5]
  set<Node *> s;
  for(int i = 0; i < (int)a.size(); i++) {
    s.insert(a[i]);
  }
  for(int i = 0; i < (int)b.size(); i++) {
    if(s.count(b[i])) {
      ans = b[i];
      break;
    }
  }
  return ans;
}
Node* LCA(Node *root, Node *a, Node *b) {
  vector<Node *> pathA;
  vector<Node *> pathB;
  Node *ans = new Node(-1);
  
  if(getPath(root, a, pathA) && getPath(root, b, pathB)){ 
    ans = getFirstEqualElement(pathA, pathB);
    
  } 
  return ans;
}

/*             5
            3     9
          1  4   8  10
*/

void inorden(Node* root) {
  if(!root) return;
  inorden(root->left);
  cout << root->val << " ";
  inorden(root->right);
}

int main() {
  Node* five = new Node(5);
  Node* one = new Node(1);
  Node* three = new Node(3);
  Node* eight = new Node(8);
  Node* four = new Node(4);
  Node* ten = new Node(10);
  Node* nine = new Node(9);
  
  three->left = one;
  three->right = four;
  nine->left = eight;
  nine->right = ten;
  
  five->left = three;
  five->right = nine;
  Node * root = five;
  
  cout << LCA(root, eight, ten)->val << endl;
}
