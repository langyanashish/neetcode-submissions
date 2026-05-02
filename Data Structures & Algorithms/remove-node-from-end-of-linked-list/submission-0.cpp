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
    int CountNodes(ListNode* head)
    {
        if(!head)
            return 0;
        int num = 0;
        ListNode* cur = head;
        while(cur)
        {
            num++;
            cur = cur->next;
        }
        return num;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = CountNodes(head);
        if(num == n)
            return head->next;
        n = num - n - 1;
        ListNode* cur = head;
        for(int i = 0; i < n; i++)
            cur = cur->next;
        cur->next = cur->next->next;
        return head;
    }
};
