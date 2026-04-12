#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* a = NULL;
        ListNode* b = NULL;

        while(fast && fast->next){
            a = slow;
            slow = slow->next;
            b = slow->next;
            fast = fast->next->next;
        }
        a->next = b;
        return head;
    }
};

int main() {

    return 0;
}