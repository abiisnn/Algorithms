void insertElement(ListNode* &list, ListNode* &element) {
    list->next = element;
    list = list->next;
    
    ListNode* backup = element->next;
    element->next = NULL;
    element = backup;
}
ListNode* join(ListNode* odd, ListNode* even) {
    ListNode* root = new ListNode(-1);
    ListNode* last = root; 
    root->next = odd;
    while(odd) {
        last = odd;
        odd = odd->next;
    }
    last->next = even;
    return root->next;
}

ListNode* oddEvenList(ListNode* head) {
    ListNode* headOdd = new ListNode(-1);
    ListNode* headEven = new ListNode(-1);
    ListNode* odd = headOdd;
    ListNode* even = headEven; 
    int i = 1;
    while(head) {
        if(i & 1) {
            insertElement(odd, head);
        } else {
            insertElement(even, head);
        }
        i++;
    }
    ListNode *root = join(headOdd->next, headEven->next);
    return root;
}