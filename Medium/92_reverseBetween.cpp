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
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(head == nullptr || head->next == nullptr) return head;
//         ListNode* return_head;
//         // if(left > 0) return_head = head;
//         ListNode* before_left = nullptr;
//         ListNode* left_first = nullptr;
//         recursion(head, head->next, 0,left-1,right-1, before_left,left_first,return_head);
//         if(left > 0)
//             return head;
//         else
//             return return_head;

//     }
//     void recursion(ListNode* node, ListNode* next_node, int cur, int left, int right, ListNode* &before_left, ListNode* &left_first, ListNode* &return_head){
//         if(cur < left)
//         {
//             if(cur == left -1)
//             {
//                 before_left = node;
//             }
//             recursion(node,next_node,cur+1,left,right,before_left,left_first,return_head);
//         }else if(cur>= left && cur < right){
//             if(cur == left)
//             {
//                 left_first = node;
//             }
//             if(next_node->next != nullptr)
//             {
//                 ListNode* temp = next_node->next;// num 4 location
//                 next_node->next = node;
//                 recursion(node,next_node,cur+1,left,right,before_left,left_first,return_head);
//             }
//         }else if(cur == right)
//         {
//             before_left->next = node;
//             recursion(node,next_node,cur+1,left,right,before_left,left_first,return_head);
//             return_head = node;
//         }else if(cur == right + 1){
//             left_first->next = node;
//             return;
//         }
//     }
// };
// https://leetcode.com/problems/reverse-linked-list-ii/solutions/5418381/video-simple-solution
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* cur = prev->next;
        // cout << "cur: " << cur->val << endl;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;        
    }
};
