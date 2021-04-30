/*
Please program a binary search tree for integers. It needs to handle the following:
 - Initial population from an unsorted array
 - Answer if a given number is in the tree
 - Insert new members into the tree (it doesn't need to rebalance)

Input: [1, 3, 4, 0, 23] target = 23 -> YES

BST = (array) -> Constructer
exist(target) -> True or false
insert(target)
*/
#include<bits/stdc++.h>
using namespace std;
struct BST {
    BST *left;
    BST *right;
    int val;
    BST(int val): left(nullptr), right(nullptr), val(val) {}
};
BST* insertVector(vector<int> &numbers, int l, int r) { // Time Complexity: O(n), Memory comple: O(n)
    if(l > r) return NULL;
    int middle = l + (r - l) / 2;
    BST *root = new BST(numbers[middle]);
    root->left = insertVector(numbers, l, middle - 1);
    root->right = insertVector(numbers, middle + 1, r);
    return root;
}

int main() {// n: size of the vector
    vector<int> numbers = {2, 4, 5,  0, 4, 5};
    sort(numbers.begin(), numbers.end()); // O(n * log(n))
    BST *binarySTroot = insertVector(numbers, 0, numbers.size()-1);
}
