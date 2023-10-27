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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = head;
        if(head == nullptr)
        {
            return head;
        }
        if(head->next != nullptr)
        {
            new_head = recursive(head,head->next);
        }
        else 
        {
            return head;
        }
        head->next = nullptr;
        return new_head;
    }

    ListNode* recursive(ListNode* now, ListNode* next)
    {
        if(next->next != nullptr)
        {
            ListNode* temp_p = next->next;
            next->next = now;
            //cout << "now value: " << now->val<<endl;
            return recursive(next,temp_p);
        }else{
            next->next = now;
            //cout << "now value: " << now->val<<endl;
            return next;
        }
    }
};
