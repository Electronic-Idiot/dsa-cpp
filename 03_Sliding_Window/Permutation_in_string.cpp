/**
 * Problem: Permutation in string
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
#include <vector>

using namespace std;

class Solution {
public:
  bool solve(string s1, string s2) {
    // Implementation
    // build a fixed sliding window because we know the size of the valid
    // substring
    unordered_map<char, int> count1;
    for (char c : s1) {
      count1[c]++;
    }
    int anchor = 0;
    int scout = s1.size() - 1;
    unordered_map<char, int> count2;
    for (int i = 0; i <= (s2.size() - s1.size()) + 1; i++) {
      int radar = anchor;
      int curr = 0;
      while (radar <= scout) {
        char c = s2[radar];
        count2[c]++;
        if (count1[c] < count2[c]) {
          break;
        }
        if (count1[c] == count2[c]) {
          curr++;
        }
        radar++;
      }
      if (curr == s1.size())
        return true;
      anchor++;
      scout++;
    }
    return false;
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

  cout << sol.solve("adc", "dcda");
  cout << sol.solve("abc", "leccabe");

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
