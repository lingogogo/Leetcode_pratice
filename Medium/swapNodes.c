struct ListNode* swapNodes(struct ListNode* head, int k){
    int length = 0;
    struct ListNode* count = head;
    while(count != NULL)
    {
        count = count->next;
        length ++;
    }

    
    struct ListNode* start = head;
    struct ListNode* end = head;
    int con_start = k - 1;
    int con_end = length - k;
    while(con_start > 0)
    {
        start = start->next;
        con_start--;
    }
    while(con_end > 0)
    {
        end = end->next;
        con_end--;
    }

    int temp = start->val;
    start->val = end->val;
    end->val = temp;
    return head;
    
    
}
