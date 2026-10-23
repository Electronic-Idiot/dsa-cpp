/**
// PIVOT: Array index = frequency. Map counts, then populate buckets, then scan
backwards.
// SYNTAX: vector<vector<int>> buckets(nums.size() + 1);
// buckets[pair.second].push_back(pair.first);
 * Problem: Top K Frequent Elements
 * Platform: LeetCode / GfG
 * Pattern:Array,Hash Table,Divide and Conquer,Sorting
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(N)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> solve(vector<int> &nums, int k) {
    // Implementation
    unordered_map<int, int> count;
    vector<vector<int>> map(nums.size() + 1);
    for (auto &num : nums) {
      count[num]++;
    }
    for (auto &[e, c] : count) {
      map[c].push_back(e);
    }
    vector<int> result;
    for (int i = nums.size(); i >= 0; i--) {
      for (auto e : map[i]) {
        result.push_back(e);
      }
      if (result.size() == k) {
        return result;
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[1, 2, 2, 3, 3, 3]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  vector<int> solution = sol.solve(nums, 2);

  // Example Printers:
  dsa::printVector(solution);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
