#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }

        // fast一次走两步， slow一次走一步
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            printf("fast = %d, slow = %d \n", fast->val, slow->val);
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        // 如果无环
        if(fast->next == nullptr || fast->next->next == nullptr){
            return nullptr;
        }

        // 如果有环，那么一定能相遇
        if(fast == slow){
            fast = head;
        }

        // 一次走一步
        while(fast != slow){
            printf("fast = %d, slow = %d \n", fast->val, slow->val);
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{   
    ListNode *two = new ListNode(2);
    ListNode *four = new ListNode(4);
    four->next = two;
    ListNode *zero = new ListNode(0);
    zero->next = four;
    ListNode *three = new ListNode(3);
    three->next = two;
    two->next = zero;

    Solution mysolution;
    ListNode *p = mysolution.detectCycle(three);
    printf("p = %d \n", p->val);
    return 0;
}
