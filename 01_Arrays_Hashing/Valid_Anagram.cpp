/**
 * Problem: Valid Anagram
 * Platform: LeetCode / GfG
 * Pattern:Array,hash table
 * Complexity:
 *   - Time:  O(NlogN+MlogM)
 *   - Space: O(logN +logM)
 */
// STATUS:BRUTE_FORCE -REQUIRES O(N) OPTIMIZATION

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool solve(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < (max(s.length(), t.length()) - 1); i++) {
      if (s[i] != t[i]) {
        return false;
      }
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

  cout << sol.solve("racecar", "carrace");

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
