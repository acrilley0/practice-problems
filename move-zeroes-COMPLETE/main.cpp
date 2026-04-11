#include <vector>
#include <iostream>

class Solution {
public:
  // This solution does not work if there are two zeroes in a row
  // void moveZeroes(std::vector<int>& nums) {
  //   for (int i = 0; i < nums.size(); i++) {
  //     int tmp;
  //     if (nums[i] == 0) {
  //       int j = i;
  //       while (j < nums.size() - 1) {
  //         tmp = nums[j+1];
  //         nums[j+1] = 0;
  //         nums[j] = tmp;
  //         j++;
  //         // }
  //       }
  //     }
  //   }
  // }
  void moveZeroes(std::vector<int>& nums) {
    int last_non_zero_idx = 0; // This is our write pointer indicating what idx we are writing a non zero value to
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        nums[last_non_zero_idx] = nums[i];
        last_non_zero_idx++;
      }
    }

    // Now we can start looping from the write pointer, which at this point indicates the last non zero value,
    // and we can set all numbers after this point to 0 because we have moved all non zero nums to be before this
    for (int i = last_non_zero_idx; i < nums.size(); i++) {
      nums[i] = 0;
    }
  }
};

void printNums(std::vector<int>& nums) {
  for (const int& num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  Solution sol;
  std::vector<int> t1 = {0,1,0,3,12};
  printNums(t1);
  sol.moveZeroes(t1);
  printNums(t1);

  std::vector<int> t2 = {0,0,1,2,3};
  printNums(t2);
  sol.moveZeroes(t2);
  printNums(t2);

  std::vector<int> t3 = {0,1,2,0,3};
  printNums(t3);
  sol.moveZeroes(t3);
  printNums(t3);

  return 0;
}
