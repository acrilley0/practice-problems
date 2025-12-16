#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      std::unordered_set<int> values;
      for (int num : nums) {
        /* An unordered_set will only store unique keys, which
         * means that an attempt to insert a duplicate element will fail.
         *
         * insert() on an unordered_set returns a std::pair of
         * <iterator, bool>

         * Note that a std::pair is just a simple container that provides
         * a way to hold two related values together.
         *
         * The iterator represents the iterator to the inserted
         * element or the element that revented the inesertion.
         *
         * The bool tells us whether the insertion took place.
         */
        auto rc = values.insert(num);
        if (!rc.second) {
          return true;
        }
      }
      return false;
    }
};

int main()
{
  Solution sol;
  vector<int> test1 = {1, 2, 3, 1};
  cout << sol.containsDuplicate(test1) << endl;
  vector<int> test2 = {1, 2, 3, 4};
  cout << sol.containsDuplicate(test2) << endl;

  return 0;
}
