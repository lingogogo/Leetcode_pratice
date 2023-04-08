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
