#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int getSize(ListNode* root) {
    ListNode* current = root;
    int size = 0;
    while(current) {
        size++;
        current = current->next;
    }
    return size;
}
vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int sizeList = getSize(root);
    int part = sizeList / k;
    int extra = sizeList % k;

    vector<ListNode*> split(k);
    for(int i = 0; i < k; i++) {
        int lim = part;
        if(extra > 0) lim++;
        if(lim) {
            split[i] = root;
            lim--;
            while(lim--) {
                root = root->next;
            }
            ListNode *backup = root->next;
            root->next = NULL;
            root = backup;
        }
        extra--;
    }
    return split;
}
int main() {
    int n, k, num; cin >> n >> k;

    ListNode* head = new ListNode(-1);
    ListNode* current = head;
    for(int i = 0; i < n; i++) {
        cin >> num;
        ListNode *element = new ListNode(num);
        current->next = element;
        current = element;
    }
    vector<ListNode*> v = splitListToParts(head->next, k);

    
}