/*
    Brute solution: n: size of list
    -> Save first n/2 elements in a stack
    -> walk from the n/2| element and compare whith the last element in the stack
    1->2->3->2->1   5/2 = 2
    [1, 2]
    2->1
    stack = 2, list = 2
    stack = 1, list = 1
    TRUE
    Time Complexity: O(n), Space Complexity: O(n/2) => O(n)
    
    Solution:
    -> Split list into 2 list: 
        - Size of list is odd: 1=>[0, n/2 - 1] 2=>[n/2 + 1, n-1]
        - Size of list is even: 1=>[0, n/2 - 1] 2=>[n/2, n-1]
    -> Reverse any list
         1->2->3->4   => 1<-2
            >1
            save the next element backup = 2
            change direcction 1 is pointing to last
            last = current
            current = backup
    -> Compare element by element
    
    1->2->3->2->1   5/2 = 2
    
    List1 = 1->2->3
    List2 = 2->1 
    Reverse2 = 1->2
    Compare element by element until the 5/2 positions
    TRUE
    Time Complexity: O(n), Space Complexity: O(1)
*/
int getSize(ListNode* head) {
    ListNode* current = head;
    int size = 0;
    while(current) {
        size++;
        current = current->next;
    }
    return size;
}
ListNode* getiNode(ListNode* head, int element) {
    ListNode* current = head;
    int i = 1;
    while(current->next && i < element) {
        current = current->next;
        i++;
    }
    return current;
}
ListNode* reverseList(ListNode* head) {
    ListNode* previous = NULL;
    ListNode* current = head;
    while(current) {
        ListNode* backup = current->next;
        current->next = previous;
        previous = current;
        current = backup;
    }
    return previous;
}
bool isPalindrome(ListNode* head) {
    if(head == NULL) return true;
    
    int sizeList = getSize(head);
    int sizeSplit = sizeList/ 2;
    if(sizeList & 1)sizeSplit++;
        
    ListNode* listA = head;
    ListNode* listB = getiNode(head, sizeSplit + 1);
    
    listB = reverseList(listB);
    int times = 0;
    
    bool ans = true;
    while(times < sizeList/2) {
        if(listA->val != listB->val) {
            ans = false;
            break;
        }
        times++;
        listA = listA->next;
        listB = listB->next;
    }
    return ans;
}