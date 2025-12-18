#include <iostream>
#include <cassert>
#include <memory>
#include <vector>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;

struct ListNode {
  int val;
  std::shared_ptr<ListNode> next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::shared_ptr<ListNode> createListSP(vector<int> & nums)
{
  if (nums.empty()) {
    cout << "Got an empty vector" << endl;
    return nullptr;
  }
  std::shared_ptr<ListNode> head = std::make_shared<ListNode>(nums[0]);
  assert(head);

  std::shared_ptr<ListNode> iter = head;

  for (int i = 1; i < nums.size(); i++) {
    iter->next = std::make_shared<ListNode>(nums[i]);
    iter = iter->next;
  }

  return head;
}

class Solution {
public:
  ListNode* insertGreatestCommonDivisors(std::shared_ptr<ListNode> & head_shared)
  {
    std::shared_ptr<ListNode> head = head_shared;

    while (head->next) {
      int gcd_val = std::gcd(head->val, head->next->val);
      auto gcd = std::make_shared<ListNode>(gcd_val);
      gcd->next = head->next;
      head->next = gcd;
      head = gcd->next;
    }
    return head_shared.get();
  }
};

int main()
{
  Solution sol;

  vector<int> case1 = {18,6,10, 3};
  std::shared_ptr<ListNode> test1 = createListSP(case1);
  ListNode *gcd1 = sol.insertGreatestCommonDivisors(test1);

  vector<int> case2 = {7};
  std::shared_ptr<ListNode> test2 = createListSP(case2);
  ListNode *gcd2 = sol.insertGreatestCommonDivisors(test2);

  ListNode *head = gcd1;
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next.get();
  }

  return 0;
}
