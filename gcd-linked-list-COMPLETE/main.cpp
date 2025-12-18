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

std::shared_ptr<ListNode> createListSP(vector<int> nums)
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

  // Even though this is a raw pointer (because .get() was called on a shared_ptr)
  // it does need to be manually deleted because the shared_ptr still owns the object
  // and is responsible for its deletion when it goes out of scope
  // ListNode *test1 = createList({18, 6, 10, 3}).get();
  std::shared_ptr<ListNode> test1 = createListSP({18, 6, 10, 3});
  sol.insertGreatestCommonDivisors(test1);
  std::shared_ptr<ListNode> head = test1;
  while (head != nullptr) {
    cout << head->val << " ";
    head = head->next;
  }

  return 0;
}
