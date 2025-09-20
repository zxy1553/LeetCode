#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next)
      return nullptr;
    ListNode *fast = head->next, *slow = head;

    while (fast != slow && fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (!fast || !fast->next)
      return nullptr;

    int len = 0;
    do {
      slow = slow->next;
      fast = fast->next->next;
      len++;
    } while (fast != slow);
    
    ListNode *entry_fast=head, *entry_slow=head;
    for (int i = 0; i < len; ++i) {
      entry_fast = entry_fast->next;
    }
    while (entry_slow != entry_fast) {
      entry_fast = entry_fast->next;
      entry_slow = entry_slow->next;
    }
    return entry_fast;
  }
};

int main() {
  ListNode a(1);
//   ListNode b(2);
//   ListNode c(0);
//   ListNode d(-4);
  //   ListNode e(5);
//   a.next = &b;
//   b.next = &a;
//   c.next = &d;
//   d.next = &b;
  Solution sol;
  cout << sol.detectCycle(&a)->val;
}