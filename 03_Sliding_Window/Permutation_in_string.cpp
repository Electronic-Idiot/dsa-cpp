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
    // TODO: needs to understand the movement of the window after the substring
    // fully processed
    // need to drill in the curr amensia issue
    // tried to replace the fatal break statement with continue but not the
    // right approach ,needs review
    // can replace the curr counter with the operator overloading the operator==
    // to compare the unordered map (also vectors)
    // VISUALISE THE FIXED SIZE WINDOW STATE MACHINE TO FIND THE SOLUTION

    unordered_map<char, int> count1;
    for (char c : s1) {
      count1[c]++;
    }
    int anchor = 0;
    int scout = s1.size() - 1;
    unordered_map<char, int> count2;
    int curr = 0;
    // check if s2 is larger than s1

    while (scout < s2.size() - 1) {
      int radar = anchor;
      if (anchor == 0) {
        while (radar <= scout) {
          char c = s2[radar];
          count2[c]++;
          if (count1[c] < count2[c]) {
            // count2[anchor]--;
            // break;
            count2[s2[anchor]]--;
            anchor++;
            scout++;
            continue;
          }
          if (count1[c] == count2[c]) {
            curr++;
          }
          radar++;
        }
        // anchor++;
        // scout++;
      } else {
        count2[s2[anchor - 1]]--;
        char c = s2[scout];
        count2[c]++;
        if (count1[c] < count2[c]) {
          // count2[anchor]--;
          continue;
        }
        if (count1[c] == count2[c]) {
          curr++;
        }
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
