#include <functional>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution{
public:
  int xorOperation(int n, int start)
  {
    vector<int> nums = {};
    int x = 0;
    for (int i = 0; i < n; i++) {
      nums.push_back(start + (2 * i));
      x ^= nums[i];
    }
    return x;
  }
};

int main()
{
  Solution sol;
  cout << sol.xorOperation(5, 0) << endl;
  cout << sol.xorOperation(4, 3) << endl;
  return 0;
}
