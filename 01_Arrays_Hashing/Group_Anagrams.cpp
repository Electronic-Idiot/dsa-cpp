/**
 * Problem: Group Anagrams
 * Platform: LeetCode / GfG
 * Pattern:
 * Complexity:
 *   - Time:  O()
 *   - Space: O()
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    // Implementation
    string sorted_word;
    unordered_map<string, vector<string>> map;
    for (auto &word : strs) {
      sorted_word = word;
      sort(sorted_word.begin(), sorted_word.end());
      map[sorted_word].push_back(word);
    }
    vector<vector<string>> result;
    result.reserve(map.size());
    for (auto &word : map) {
      result.push_back(word.second);
    }
    return result;
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
