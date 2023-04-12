/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */



struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    struct ListNode *k1 = headA;
    struct ListNode *k2 = headB;

    while(k1 && k2 && k1 != k2)
    {
        k1 = k1->next;
        k2 = k2->next;
        if(k1 == k2)
        {
            return k1;
        }
        
        if(k1 == NULL)
            k1 = headB;
        if(k2 == NULL)
            k2 = headA;
    }
    return k1;
   

}
