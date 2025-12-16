#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
  static bool isPalindrome(string s)
  {
    /* A string is a palindrome if it is the same after doing the following:
     * 1. Convert all uppercase letters to lowercase letters
     * 2. Remove all non-alphanumeric characters (spaces, commas, periods)
     */

    // Step 1: Convert string to all lowercase and remove non-alphanumerics
    for (int i = 0; i < s.size(); i++) {
      if (std::isupper(s[i])) {
        s[i] = std::tolower(s[i]);
      }
    }

    /* remove-erase idiom
    * 1. Call 'remove' to relocate the elements we want to remove to the end
    *    of the container and return a new logical end of the range.
    * 2. Erase all of the elements that are after the new logical end.
    */

    s.erase(std::remove_if(s.begin(), s.end(), ::ispunct), s.end());

    // This is not a fast way to do this
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

    if (s.size() == 1) {
      return true;
    }

    // Step 2: Compare the input and reversed string
    // Note: There is probably a 'reverse' method in the string class
    // but for the purpose of learning I'm gonna do it the "hard" way.
    int fp = 0;
    int lp = s.size() - 1;

    int iter = 0;
    while (fp < lp) {
      if (s[fp] != s[lp]) {
        return false;
      }
      fp++, lp--;
      iter++;
    }

    return true;
  }
};

int main()
{
  string test1 = "A man, a plan, a canal: Panama"; // true
  string test2 = "race a car"; // false
  string test3 = " "; // true
  string test4 = "......a....."; // true

  // cout << "Test 1: " << test1 << " Palindrome? " << Solution::isPalindrome(test1) << endl;
  // cout << "Test 2: " << test2 << " Palindrome? " << Solution::isPalindrome(test2) << endl;;
  // cout << "Test 3: " << test3 << " Palindrome? " << Solution::isPalindrome(test3) << endl;;
  // cout << "Test 4: " << test4 << " Palindrome? " << Solution::isPalindrome(test4) << endl;;
  cout << Solution::isPalindrome(test4);

  return 0;
}
