/* RECURSION */
void helper(ListNode* head, ListNode* &copy) {
    if(!head) return;
    helper(head->next, copy);
    head->next = NULL;
    copy->next = head;
    copy = copy->next;
}
// Opt1
ListNode* reverseList(ListNode* head) {
    ListNode* backup = new ListNode(-1);
    ListNode* newHead = backup;
    helper(head, backup);
    return newHead->next;
}
// Opt 2
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode*  newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

/* Iterative */
// opt 1
ListNode* reverseList(ListNode* head) {
    if(!head) return head;
    ListNode *backup = head, *last = NULL;
    while(head->next) {
        backup = head->next;
        head->next = last;
        last = head;
        head = backup;
    }
    backup->next = last;
    return head;
}
// opt2
ListNode* reverseList(ListNode* head) {
    ListNode *current = head, *previous = NULL, *backup = NULL;
    while(current) {
        backup = current->next;
        current->next = previous;
        previous = current;
        current = backup;
    }
    return previous;
}