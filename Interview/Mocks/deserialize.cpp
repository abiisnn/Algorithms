
/*serialized: 20 8 -1 -1 22 -1 -1 

tree:
      20
    /   \
   8     22 

preorder: 20 8 4 12 10 14
[20 8 4 -1 -1 12 10 -1 -1 14 -1 -1 -1]


        20
       /    
      8     
     /      \
    4       12 
  -1 -1    /  \
          10  14
*/
void deserialize(Node *&root, vector<int> &a, int &i) {
  if((a[i] != -1)  && (i < a.size())) {
    root->val = new node(a[i]);
    i++;
    traversal(left, i)
    traversal(right, i)
  } 
  return; 
}