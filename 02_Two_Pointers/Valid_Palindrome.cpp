/**
// PIVOT: The Two Pointer idea:start comparing things from the two extremes in
one reducing both complexities
// SYNTAX:copy[i] != copy[copy.size() - 1 - i] //Front of the string compared
with rear
 * Problem: Valid Palindrome
 * Platform: LeetCode / GfG
 * Pattern:Two Pointers,String
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(1)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool solve(string s) {
    // Implementation
    string copy;
    for (auto letters : s) {

      if ((letters >= 'A' && letters <= 'Z') ||
          (letters >= 'a' && letters <= 'z') ||
          (letters >= '0' && letters <= '9'))
        copy += (char)tolower(letters);
    }
    for (int i = 0; i < copy.size(); i++) {
      if (copy[i] != copy[copy.size() - 1 - i])
        return false;
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  // vector<int> nums = dsa::parseVector("[2,7,11,15]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  sol.solve();

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
