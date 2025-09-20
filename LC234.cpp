

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
    private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre=nullptr, *cur=head, *next=nullptr;
        while(cur!=nullptr){
            next = cur->next;
            cur->next = pre;
            pre = cur;

            cur = next;
        }
        return pre;        
    }

    public:
    bool isPalindrome(ListNode *head) {
        if(!head || !head->next) return true;
    ListNode dumb(0);
    dumb.next = head;
    ListNode *slow = &dumb, *fast = &dumb;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *left=nullptr, *right = slow->next;
    slow->next = nullptr;
    if(fast == nullptr){
        left = reverseList(head)->next;
    }else{
        left = reverseList(head);
    }

    while (left!=nullptr &&left->val==right->val) {
        left=left->next;
        right=right->next;
    }

    return left == nullptr?1:0;
    
  }
};

int main() {
  ListNode a(1);
  ListNode b(2);
//   ListNode c(3);
//   ListNode d(2);
//   ListNode e(1);
  a.next = &b;
//   b.next = &c;
//   c.next = &d;
//   d.next = &e;

  Solution sol;
  cout << sol.isPalindrome(&a);
}