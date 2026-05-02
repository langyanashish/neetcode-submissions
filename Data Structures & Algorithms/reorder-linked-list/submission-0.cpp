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
    ListNode* FindMiddleNode(ListNode* node)
    {
        ListNode *slow = node, *fast = node;
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(!fast)
                return slow;
        }
        return slow->next;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *cur = head, *result = NULL;
        while(cur)
        {
            ListNode *nxt = cur->next;
            cur->next = result;
            result = cur;
            cur = nxt;
        }
        return result;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* mid = FindMiddleNode(head);
        mid = reverseList(mid);
        ListNode* dummy = new ListNode(0, head);
        ListNode *first = head, *second = mid, *cur = dummy;;
        while(first && second)
        {
            ListNode* nxt1 = first->next;
            ListNode* nxt2 = second->next;
            cur->next = first;
            first->next = second;
            cur = second;
            second->next = NULL;
            first = nxt1;
            second = nxt2;
        }
        if(first)
        {
            cur->next = first;
            first->next = NULL;
        }
    }
};

/*
2 4 6 8 10
2 4 6 10 8
2 1- 4 8 6

2 4 6 8 10 12
2 4 6 12 10 8
*/
