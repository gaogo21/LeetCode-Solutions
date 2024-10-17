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


 //找到中间节点，翻转链表，再同时走，不相同就返回false;
 //全部翻转，和原链表进行比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        
        ListNode* slow = endOfFirstHalf(head);
        ListNode* fast = reverseList(slow->next);

        ListNode* p1 = head, *p2 = fast;
        while(p2)
        {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    ListNode* endOfFirstHalf(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};