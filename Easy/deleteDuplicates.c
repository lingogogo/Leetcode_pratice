/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    
    
    struct ListNode* start = head;
    if(head == NULL)
    {
        return head;
    }
    // start->next != NULL can handle most problem
    
    while(start->next != NULL)
    {
        if(start->val == start->next->val)
        {
            start->next = start->next->next;
            continue;
        }
        start = start->next;
    }

    return head;
}
