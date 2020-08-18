int getSize(ListNode *head) {
    ListNode *headbk = head;
    int size = 0;
    while(headbk) {
        size++;
        headbk = headbk->next;
    }
    return size;
}
ListNode* middleNode(ListNode* head) {
    int size = getSize(head);
    int middle = size / 2, i = 0;
    ListNode *headbk = head;
    while(headbk) {
        if(i == middle) {
            break;
        }
        i++;
        headbk = headbk->next;
    }
    return headbk;
}
