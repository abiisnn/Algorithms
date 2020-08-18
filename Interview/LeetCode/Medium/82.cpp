#include<bits/stdc++.h> 
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int count(ListNode *node, ListNode *&end) {
    ListNode *current = node;
    int val = node->val;
    int freq = 0;
    while(current && current->val == val) {
        freq++;
        end = current;
        current = current->next;
    }
    return freq;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode *newHead = new ListNode(-1);
    newHead->next = head;
    ListNode *current = newHead;
    while(current->next) { 
        ListNode *end = new ListNode(-1);
        int freq = count(current->next, end); // freq = 2, end = ult 4
        if(freq > 1) { 
            current->next = end->next; // current->next = 5
        } else {
            current = current->next;
        }
    }
    
    return newHead->next;
}

int main() {
    ListNode *head = new ListNode(1);
    ListNode *e2 = new ListNode(2);
    ListNode *e3 = new ListNode(3);
    ListNode *e4 = new ListNode(3);
    ListNode *e5 = new ListNode(4);
    ListNode *e6 = new ListNode(4);
    ListNode *e7 = new ListNode(5);
    
    head->next = e2;
    e2->next = e3;
    e3->next = e4;
    e4->next = e5;
    e5->next = e6;
    e6->next = e7;

    deleteDuplicates(head);
}