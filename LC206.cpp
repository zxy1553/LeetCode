#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dumb = new ListNode(0);
        dumb->next=head;
        ListNode *pre=head, *cur=head, *next=nullptr;
        while(cur){
            next = cur->next;
            pre = cur;
            cur->next = pre;
            dumb->next = cur;

            cur = next;
        }
        return dumb->next;        
    }
};


int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    
    Solution sol;

    cout <<    sol.reverseList(&a)->val;
}