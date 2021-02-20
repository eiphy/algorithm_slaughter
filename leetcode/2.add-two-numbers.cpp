/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int jinwei{0};
        ListNode *answerp{new ListNode(-1)};
        ListNode *nextp = answerp;

        int temp{0};
        while (true)
        {
            temp = l1->val + l2->val + jinwei;
            jinwei = temp / 10;
            temp %= 10;

            nextp->val = temp;
            if (!(l1->next) && !(l2->next) && !jinwei)
                break;
            nextp->next = new ListNode(0);
            nextp = nextp->next;
            l1 = l1->next ? l1->next : new ListNode(0);
            l2 = l2->next ? l2->next : new ListNode(0);
        }
        return answerp;
    }
};
// @lc code=end
