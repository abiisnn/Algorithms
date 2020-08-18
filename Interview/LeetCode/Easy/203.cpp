// Time: O(n), Space = O(n)
ListNode* removeElements(ListNode* head, int val) {
    ListNode *newHead = new ListNode(-1);
    ListNode *last = newHead;
    while(head) {
        if(head->val != val) {
            ListNode *node = new ListNode(head->val);
            last->next = node;
            last = last->next;
        }
        head = head->next;
    }
    return newHead->next;
}
// Time: O(n), Space = O(1)
ListNode* removeElements(ListNode* head, int val) {
    if(!head) return head;
    ListNode *newHead = new ListNode(-1);
    newHead->next = head;
    ListNode *node = newHead;
 
    while(node->next) { // 1
        if(node->next->val == val) { // l[1] = 6
           node->next = node->next->next; // 
        } else { // node = 1
            node = node->next;
        }
    }
    return newHead->next;
}