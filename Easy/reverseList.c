/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* recursive(struct ListNode* now,struct ListNode* before)
{   
    
    if(now == NULL)
    {
        return NULL;
    }
   
    struct ListNode* temp = now->next;
    if(now->next == NULL)
    {
    now->next = before;
    return now;
    }
         
    now->next = before;
    before = now;
    return recursive(temp,before);
}

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* ans;
    ans = recursive(head,NULL);
    return ans;
}
