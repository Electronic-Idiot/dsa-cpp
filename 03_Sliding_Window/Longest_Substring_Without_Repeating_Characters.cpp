/**
 * Problem: Longest Substring Without Repeating Characters
 * Platform: LeetCode / GfG
 * Pattern:
 * Complexity:
 *   - Time:  O()
 *   - Space: O()
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(string s) {
    // Implementation
    unordered_set<char> window;
    int anchor = 0;
    int scout = 0;
    int maxLen = 0;
    while (scout != s.size()) {
      if (window.find(s[scout]) == window.end()) {
        window.insert(s[scout]);
        maxLen = max(maxLen, scout - anchor + 1);
        scout++;
      } else {
        while (window.count(s[scout]) != 0) {
          window.erase(s[anchor]);
          anchor++;
        }
        window.insert(s[scout]);
        scout++;
      }
    }
    return maxLen;
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

  cout << sol.solve("abcabcbb");

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
