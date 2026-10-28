/**
// PIVOT: Instead of sorting and counting, use a set to find unique numbers and
search in O(1)
//find numbers that are start of a sequence (check whether n-1 exist)
// SYNTAX:(copy.find(num - 1) != copy.end()) continue;
 * Problem: Longest Consecutive Sequence
 * Platform: LeetCode / GfG
 * Pattern: Array,Hash table
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(N)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(vector<int> &nums) {
    // Implementation
    unordered_set<int> copy;
    int maxSeq = 0;
    for (int num : nums) {
      copy.insert(num);
    }
    for (int num : copy) {
      if (copy.find(num - 1) != copy.end()) // can use contains if C++ 20
        continue;
      int start = num;
      int count = num;

      while (copy.find(++count) != copy.end())
        ;
      maxSeq = max(maxSeq, (count - start));
    }
    return maxSeq;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[2,20,4,10,3,4,5]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  cout << sol.solve(nums);

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
