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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *result = new ListNode();
        ListNode *res = result;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                result->next = list1;
                result = result->next;
                list1 = list1->next;
            }
            else
            {
                result->next = list2;
                result = result->next;
                list2 = list2->next;
            }
        }
        if(list1)
            result->next = list1;
        if(list2)
            result->next = list2;
        return res->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        while(lists.size() > 1)
        {
            ListNode* temp = mergeTwoLists(lists[0], lists[1]);
            lists.push_back(temp);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};
