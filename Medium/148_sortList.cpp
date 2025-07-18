/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        // Find the middle using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        // Recursively split and merge
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        
        // ListNode* result;
        // if(l1->val < l2->val){
        //     result = l1;
        //     l1 = l1->next;
        // }else{
        //     result = l2;
        //     l2=l2->next;
        // }

        // ListNode* tail = result;
        // while(l1 && l2)
        // {
        //     if (l1->val < l2->val) {
        //         tail->next = l1;
        //         l1 = l1->next;
        //     } else {
        //         tail->next = l2;
        //         l2 = l2->next;
        //     }
        //     tail = tail->next;
        // }

        // tail->next = l1 ? l1 : l2;
        // return result;

        // Methode 2
        // ListNode* dummy = new ListNode(0);
        // ListNode* tail = dummy;
        
        // while (l1 && l2) {
        //     if (l1->val < l2->val) {
        //         tail->next = l1;
        //         l1 = l1->next;
        //     } else {
        //         tail->next = l2;
        //         l2 = l2->next;
        //     }
        //     tail = tail->next;
        // }
        
        // tail->next = l1 ? l1 : l2;
        // ListNode* result = dummy->next;
        // delete dummy;
        // return result;

        // Method 3
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
