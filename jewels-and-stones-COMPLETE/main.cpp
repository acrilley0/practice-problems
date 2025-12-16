#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  // All characters in 'jewels' are unique
  int numJewelsInStones(string jewels, string stones)
  {
    int count = 0;
    for (int i = 0; i < jewels.size(); i++) {
      // std::find will return the index of where the byte/bytes were found,
      // otherwise it returns <container>.end(), hence the condition on the loop
      string::iterator iter = std::find(stones.begin(), stones.end(), jewels[i]);
      while (iter != stones.end()) {
        ++iter;
        iter = std::find(iter, stones.end(), jewels[i]);
        count++;
      }
    }

    return count;
  }
};

int main()
{
  Solution sol;
  cout << sol.numJewelsInStones("aA", "aAAbbbb") << endl;
  cout << sol.numJewelsInStones("z", "ZZ") << endl;

  return 0;
}
