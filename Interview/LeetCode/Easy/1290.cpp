int getSize(ListNode* head) {
    ListNode *headbk = head;
    int size = 0;
    while(headbk) {
        size++;
        headbk = headbk->next;
    }
    return size;
}
int getDecimalValue(ListNode* head) {
    ListNode *headbk = head;
    int size = getSize(head), num = 0;
    int pot = 1 << (size - 1);
    while(headbk) {
        if(headbk->val) {
            num += pot;
        }
        pot >>= 1;
        headbk = headbk->next;
    }
    return num;
}