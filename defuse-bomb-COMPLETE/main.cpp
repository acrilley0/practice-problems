#include <vector>
#include <iostream>
#include <algorithm>

/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous -k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
*/

// NOTE: We will probably have to use a modulo operation to achieve the circular code

// NOTE: We are starting this with a double for loop, but I want to optimize

class Solution {
public:
  std::vector<int> decrypt(std::vector<int>& code, int k) {
    std::vector<int> result(code.size(), 0);
    if (k == 0) {
      std::fill(code.begin(), code.end(), 0);
    } else if (k > 0) {
      for (int i = 0; i < code.size(); i++) {
        int sum = 0;
        for (int j = 1; j <= k; j++) {
          int idx = (i + j) % code.size();
          sum += code[idx];
        }
        result[i] = sum;
      }
    } else if (k < 0) {
      for (int i = 0; i < code.size(); i++) {
        int sum = 0;
        for (int j = 1; j <= std::abs(k); j++) {
          int idx = i - j;
          if (idx < 0) {
            sum += code[code.size() + idx];
          } else {
            sum += code[idx];
          }
        }
        result[i] = sum;
      }
    }

    return result;
  }
};

int main() {
  Solution sol;

  // std::vector<int> t1 = {5,7,1,4};
  // std::vector<int> result1 = sol.decrypt(t1, 3);
  // for (const auto & num : result1) {
  //   std::cout << num << " ";
  // }
  // std::cout << std::endl;
  //
  // std::vector<int> t2 = {1,2,3,4};
  // std::vector<int> result2 = sol.decrypt(t2, 0);
  // for (const auto & num : result2) {
  //   std::cout << num << " ";
  // }
  // std::cout << std::endl;
  //
  // std::vector<int> t3 = {2,4,9,3};
  // std::vector<int> result3 = sol.decrypt(t3, -2);
  // for (const auto & num : result3) {
  //   std::cout << num << " ";
  // }
  // std::cout << std::endl;

  std::vector<int> t4 = {10,5,7,7,3,2,10,3,6,9,1,6};
  std::vector<int> result4 = sol.decrypt(t4, -4);
  for (const auto & num : result4) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
