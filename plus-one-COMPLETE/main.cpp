#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits)
  {
    int idx = digits.size() - 1;

    // Base Case where there is one digit in the number
    if (digits.size() == 1 && digits.at(idx) == 9) {
      digits.push_back(0);
      digits.at(0) = 1;
      return digits;
    }

    // If the last digit is not a '9', return the the vector with the last digit incremented
    if (digits.at(idx) != 9) {
      digits.at(idx)++;
      return digits;
    }

    bool carry = true;
    while (idx >= 0 && digits.at(idx) == 9) {
      digits.at(idx) = 0;
      if (idx)
        carry = digits.at(idx - 1) == 9;

      if (carry && !idx)
        digits.insert(digits.begin() + idx, 1);

      idx--;
    }

    if (idx >= 0)
      digits.at(idx)++;

    return digits;
  }
};

int main()
{
  Solution sol;

  vector<int> case1 = {1, 2, 3};
  vector<int> solCase1 = sol.plusOne(case1);
  std::for_each(solCase1.begin(), solCase1.end(), [](int n) {
    cout << n << " ";
  });
  cout << endl;

  vector<int> case2 = {9};
  vector<int> solCase2 = sol.plusOne(case2);
  std::for_each(solCase2.begin(), solCase2.end(), [](int n) {
    cout << n << " ";
  });
  cout << endl;

  vector<int> case3 = {1,9,9};
  vector<int> solCase3 = sol.plusOne(case3);
  std::for_each(solCase3.begin(), solCase3.end(), [](int n) {
    cout << n << " ";
  });
  cout << endl;

  vector<int> case4 = {0};
  vector<int> solCase4 = sol.plusOne(case4);
  std::for_each(solCase4.begin(), solCase4.end(), [](int n) {
    cout << n << " ";
  });
  cout << endl;

  vector<int> case5 = {9,9,9};
  vector<int> solCase5 = sol.plusOne(case5);
  std::for_each(solCase5.begin(), solCase5.end(), [](int n) {
    cout << n << " ";
  });
  cout << endl;

  return 0;
}
