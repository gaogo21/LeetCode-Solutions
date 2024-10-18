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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        int carry = 0;
        while(p1 != nullptr || p2 != nullptr || carry)
        {
            int sum = carry;
            if (p1 != nullptr)
            {
                sum += p1->val;
                p1 = p1->next;
            }

            if (p2 != nullptr)
            {
                sum += p2->val;
                p2 = p2->next;
            }

            carry = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;
        }

        return dummy->next;
    }
};