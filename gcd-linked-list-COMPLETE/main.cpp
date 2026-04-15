#include <iostream>
#include <numeric>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* currp = head;

    while (currp->next) {
      int gcd_val = std::gcd(currp->val, currp->next->val);
      ListNode* tmp = currp->next;
      ListNode* gcd_node = new ListNode(gcd_val, tmp);
      currp->next = gcd_node;
      currp = currp->next->next;
    }

    return head;
  }
};

int main()
{
  Solution sol;

  // 18->6->10->3
  ListNode l1 = ListNode(18);
  ListNode l2 = ListNode(6);
  ListNode l3 = ListNode(10);
  ListNode l4 = ListNode(3);

  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = nullptr;

  ListNode* curr1 = &l1;
  while (curr1) {
    std::cout << curr1->val << " ";
    curr1 = curr1->next;
  }
  std::cout << std::endl;

  ListNode* head = sol.insertGreatestCommonDivisors(&l1);
  while (head) {
    std::cout << head->val << " ";
    head = head->next;
  }

  return 0;
}
