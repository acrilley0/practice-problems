#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
  int majorityElement(std::vector<int>& nums) {
    std::map<int,int> freqs;

    for (int& num : nums) {
      freqs[num]++;
    }

    for (const auto & pair : freqs) {
      if (pair.second > (nums.size() / 2)) {
        return pair.first;
      }
    }

    return 0;
  }
};

int main() {
  Solution sol;
  std::vector<int> nums1 = {3,2,3};
  std::cout << sol.majorityElement(nums1) << std::endl;

  std::vector<int> nums2 = {2,2,1,1,1,2,2};
  std::cout << sol.majorityElement(nums2) << std::endl;

  return 0;
}
