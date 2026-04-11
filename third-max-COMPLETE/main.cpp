#include <vector>
#include <set>
#include <iostream>

class Solution {
public:
  int thirdMax(std::vector<int>& nums) {
    std::set<int> maxes;

    for (int num : nums) {
      maxes.insert(num);
    }

    if (maxes.size() < 3) {
      return *maxes.rbegin();
    }

    int i = 0;
    for (auto riter = maxes.rbegin(); riter != maxes.rend(); ++riter) {
      if (i == 2) {
        return *riter;
      }
      i++;
    }

    return *nums.end();
  }
};

int main() {
  Solution sol;

  std::vector<int> t1 = {3,2,1};
  std::cout << sol.thirdMax(t1) << std::endl;

  std::vector<int> t2 = {1,2};
  std::cout << sol.thirdMax(t2) << std::endl;

  std::vector<int> t3 = {2,2,3,1};
  std::cout << sol.thirdMax(t3) << std::endl;

  std::vector<int> t4 = {5,2,2};
  std::cout << sol.thirdMax(t4) << std::endl;

  std::vector<int> t5 = {1,2,2,5,3,5};
  std::cout << sol.thirdMax(t5) << std::endl;

  return 0;
}
