// Method1: iterations
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Trivial solution due to empty list
    if(list1 == NULL) return list2;
    else if(list2 == NULL) return list1;

    // movenode is the iterations pointer.
    struct ListNode dummynode;
    struct ListNode* movenode = &dummynode;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val <= list2->val)
        {
            movenode->next = list1;
            list1 = list1->next;
            movenode = movenode->next;
        }else{
            movenode->next = list2;
            list2 = list2->next;
            movenode = movenode->next;
        }
    }
    // Remaining list1
    while(list1!= NULL)
    {
        movenode->next = list1;
        list1 = list1->next;
        movenode = movenode->next;
    }
    // Remaining list2
    while(list2!= NULL)
    {
        movenode->next = list2;
        list2 = list2->next;
        movenode = movenode->next;
    }

    return dummynode.next;
}
// Method2: Recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }

    if(list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    }

    if(list1->val > list2->val)
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }

    return list1;
}
