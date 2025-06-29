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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        int count_link = 0;
        ListNode* temp = head;
        while(temp)
        {
            count_link++;
            temp = temp->next;
            
        }
        k%=count_link;
        if(k == 0) return head;

        // int end = count_link - k;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        for(int i = 0; i < count_link - k+1; i++)
        {
            temp = dummy;
            dummy = dummy->next;
        }
        temp->next = nullptr;
        temp = dummy;
        while(temp->next)
        {
            // if(temp->next)
            temp = temp->next;
        }
        temp->next = head;

        return dummy;
    }
};
