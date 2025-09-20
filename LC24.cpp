
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
  ListNode *swap(ListNode *a, ListNode *b) {
    a->next = b->next;
    b->next = a;
    return b;
  }

public:
  ListNode *swapPairs(ListNode *head) {
    if (!head)
      return nullptr;
    if (!head->next)
      return head;
    ListNode dumb(0);
    ListNode *pre = &dumb, *cur = head;
    while (cur != nullptr && cur->next != nullptr) {
      pre->next = swap(cur, cur->next);
      pre = cur;
      cur = cur->next;
    }

    return dumb.next;
  }
};

int main() {
  ListNode a(1);
  ListNode b(2);
  ListNode c(3);
  ListNode d(4);
//   ListNode e(5);
  a.next = &b;
  b.next = &c;
  c.next = &d;
//   d.next = &e;


    Solution sol;
    cout<<sol.swapPairs(&a)->val;
}