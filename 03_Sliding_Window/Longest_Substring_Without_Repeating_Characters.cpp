/**
//CODE REQUIRES FURTHER OPTIMIZATIONS AND POLISH
// PIVOT:Use the principle of sliding window,anchor is the starting poin the
window(RADAR) and scout travels away from the anchor ,increasing the range of
the radar.Once the condition that we need is met the scout stops and anchor
moves forward by one space,this step should done carefully as once the anchor
moves forward threr is no going back and whatever it left is considered
processed completely
In this problem the scout travels forward until it meets a duplicate (Radar
grows in this stage) Once the scout meets a duplicate, we are done with the
place the anchor currently sitting at thus we move the anchor forward one space.
// SYNTAX:
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
        window.insert(s[scout]); // lines part of both branches,make it common
        scout++;
      }
 * Problem: Longest Substring Without Repeating Characters
 * Platform: LeetCode / GfG
 * Pattern: Hash Table, Sliding Window, String
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(M) where 'M' is the number of unique characters in the string
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
        window.insert(s[scout]); // lines part of both branches,make it common
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
