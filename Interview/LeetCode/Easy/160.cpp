int sizeList(ListNode *head) {
    ListNode* current = head;
    int size = 0;
    while(current) {
        size++;
        current = current->next;
    }
    return size;
}
ListNode *getiNode(ListNode *head, int i) {
    int cont = 1;
    ListNode* current = head;
    while(cont <= i) {
        current = current->next; 
        cont++;
    }
    return current;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int sizeA = sizeList(headA);
    int sizeB = sizeList(headB);

    int dif = max(sizeA, sizeB) - min(sizeA, sizeB);
    ListNode *currentA = headA;
    ListNode *currentB = headB;
    
    if(sizeA > sizeB) {
        currentA = getiNode(currentA, dif);
    } else {
        currentB = getiNode(currentB, dif);
    }
    
    while(currentA && currentB && currentA != currentB) {
        currentA = currentA->next;
        currentB = currentB->next;
    }
    return currentA;
}