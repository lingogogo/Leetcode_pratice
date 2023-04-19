/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    
    // Remove first element if there is the same node.
    // Or you have to use more computation.
    while(head && head -> val == val)
        head = head->next;
    
    struct ListNode* current = head;
    while(current != NULL && current->next != NULL)
    {
        if(current->next->val == val)
            current->next = current->next->next;
        else
            current = current->next;
    }
    return head;
}
