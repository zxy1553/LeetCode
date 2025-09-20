

#include <iostream>
using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };
 

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        int lenA=0, lenB=0;
        ListNode* cnt=a;
        while(cnt){
            lenA++;
            cnt = cnt->next;
        }
        cnt = b;
        while(cnt){
            lenB++;
            cnt = cnt->next;
        }


        
        while(lenB>lenA){
            b = b->next;
            lenB--;
        }
        while(lenA>lenB){
            a = a->next;
            lenA--;
        }

        while(a!=b){
            a=a->next;
            b=b->next;
        }

        return a;
    }
};


int main(){
    ListNode *intersect_node = new ListNode(8);
    intersect_node->next = new ListNode(4);
    intersect_node->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect_node;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect_node;

    Solution sol;
    ListNode *intersection = sol.getIntersectionNode(headA, headB);

    // 打印结果
    if (intersection != nullptr) {
        cout << "相交节点的值是: " << intersection->val << endl;
    } else {
        cout << "两个链表不相交。" << endl;
    }

}