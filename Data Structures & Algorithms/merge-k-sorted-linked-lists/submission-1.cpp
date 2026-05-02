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
    struct comp
    {
        bool operator()(const ListNode* first, const ListNode* second)
        {
            return first->val > second->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(auto node : lists)
        {
            if(node)
                pq.push(node);
        }
        ListNode* result = new ListNode();
        ListNode* tail = result;
        while(!pq.empty())
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if(tail->next)
                pq.push(tail->next);
        }
        return result->next;
    }
};
