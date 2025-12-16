#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int answer = 0;
    for (int num : nums) {
      answer ^= num;
    }
    return answer;
  }
};

int main() {
  Solution sol;

  vector<int> nums1 = {2, 2, 1};    // Returns 1
  vector<int> nums2 = {-1, -1, -2}; // Returns -2
  vector<int> nums3 = {1, 3, 1, -1, 3};
  cout << sol.singleNumber(nums1) << endl;
  cout << sol.singleNumber(nums2) << endl;
  cout << sol.singleNumber(nums3) << endl;
  return 0;
}
