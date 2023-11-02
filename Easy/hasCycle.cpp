class Solution {
public:
	bool hasCycle(ListNode *head) {
        while (head) {
            if (head == head->next)
                return true;
            tmp = head->next;
            head->next = head;
            head = tmp;
        }
        return false;
    }
private:
    ListNode *tmp = nullptr;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* first_p = head;
        ListNode* sec_p = head;
        if(head == nullptr)
        {
            return false;
        }
        while(true)
        {
            if(first_p->next != nullptr && sec_p->next != nullptr && sec_p->next->next!=nullptr)
            {
                first_p = first_p->next;
                sec_p = sec_p->next->next;
            }else if(first_p->next == nullptr || sec_p->next == nullptr || sec_p->next->next == nullptr )
            {
                return false;
            }

            if(first_p == sec_p)
            {
                return true;
            }
        }
    }
};
