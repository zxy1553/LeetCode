class Solution
{
public:
    ListNode *sortList(listNode *head)
    {
        if (!head || !head->next)
            return head;

        int n = 0;
        for (auto p = head; p; p = p->next)
            ++n;

        ListNode dummy(0);

        dummy.next = head;

        for (int size = 1; size < n; size <<= 1)
        {
            ListNode *prev = &dummy;
            ListNode *curr = dummy.next;
            while (curr)
            {
                ListNode *left = curr;
                ListNode *right = split(left, size);
                curr = split(right, size);
                auto pr = merge(left, right);
                prev->next = pr.first;
                prev = pr.second;
            }
        }
        return dummy.next;
    }

private:
    ListNode *split(ListNode *head, int k)
    {
        if (!head)
            return nullptr;
        for (int i = 1; i < k && head->next; ++i)
            head = head->next;
        ListNode *second = head->next;
        head->next = nullptr;
        return second;
    }

    pair<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next)
            tail = tail->next;
        return { dummy.next, tail }
    }
};