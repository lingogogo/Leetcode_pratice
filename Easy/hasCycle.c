bool hasCycle(struct ListNode *head) {
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast != NULL && fast->next != NULL){
        // Move slow pointer by 1 node and fast at 2 at each step.
        slow = slow->next;
        fast = fast->next->next;
        // If both the pointers meet at any point, then the cycle is present and return true...
        if(slow == fast)
            return true;
    }
    return false;

}
