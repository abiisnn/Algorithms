int getSizeList(ListNode *head) {
    int size = 0;
    while(head) {
        head = head->next;
        size++;
    }
    return size;
}
ListNode* rotateRight(ListNode* head, int k) {
    int sizeList = getSizeList(head);
    if(head == NULL || k % sizeList == 0) return head;
    
    int steps = sizeList - (k % sizeList) - 1; // Element that will be disconnected
    ListNode* current = head;
    while(steps--) {
        current = current->next;
    }
    ListNode* newHead = current->next; // Make backup of the head
    current->next = NULL; // Disconect one element before new head
    
    current = newHead; // Find element before end of list
    while(current->next) {
        current = current->next;
    } 
    current->next = head; // Last element pointing to the original head
    return newHead;
}