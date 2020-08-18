
void complete(ListNode *&head, ListNode *& node) {
   if(node) {
        head->next = node;
    } 
}
// Time: O(n+m) Space: O(n+m)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(-1);
    ListNode *current = head;
    ListNode *p1 = l1, *p2 = l2;
    while(p1 && p2) {
        ListNode *element = new ListNode();
        if(p1->val < p2->val) {
            element->val = p1->val;
            p1 = p1->next;
        } else {
            element->val = p2->val;
            p2 = p2->next;
        }
        current->next = element;
        current = current->next;
    }
    complete(current, p1);
    complete(current, p2);
    return head->next;
}

// Time: O(n + m) Space: O(1)
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(-1);
    ListNode *current = head;
    while(l1 && l2) {
        if(l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    complete(current, l1);
    complete(current, l2);
    return head->next;
}