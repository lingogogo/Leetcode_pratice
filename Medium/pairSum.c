/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head){
    int cou_leng = 0;
    int* value_map = (int*)malloc(sizeof(int)*100000);
    
    struct ListNode* start = head;
    while(start != NULL)
    {
        value_map[cou_leng] = start->val;
        start = start->next;
        cou_leng++;
    }
    cou_leng--;
    int max = 0;
    int start_n = 0;
    int stop = cou_leng / 2;
    while(start_n <= stop)
    {
        if(max < (value_map[start_n] + value_map[cou_leng]))
            max = value_map[start_n] + value_map[cou_leng];
        start_n ++;
        cou_leng --;
        
    }
    free(value_map);
    return max;
}
