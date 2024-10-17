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
        if (head == nullptr)
            return false;
        
        ListNode* slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            //这里得先执行++,不然程序一进来slow == fast
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)   //如果有环，就会相等
                return true;
        }

        //没有环while就会结束
        return false;
    }
};