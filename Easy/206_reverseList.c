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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Method 2
// struct ListNode* reverseList(struct ListNode* head) {
//     struct ListNode* fake_head = NULL;
//     struct ListNode* cur = fake_head;
//     struct ListNode* next = head;

//     while(next!= NULL)
//     {
//         struct ListNode* temp = next->next;
//         next->next = cur;

//         cur = next;
//         next = temp;
//     }

//     return cur; 
// }
