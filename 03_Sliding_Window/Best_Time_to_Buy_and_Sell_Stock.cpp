/**
// PIVOT: Instead of finding every possible combination of profits possible,fins
the maximum profit possible for a selling price aka find the lowest price to buy
from before the selling price.
// SYNTAX:buyPrice = min(buyPrice, prices[i]);
      maxProfit = max((prices[i] - buyPrice), maxProfit);
 * Problem: Best Time to Buy and Sell Stock
 * Platform: LeetCode / GfG
 * Pattern:Array,Sliding Window
 * Complexity:
 *   - Time:  O(N)
 *   - Space: O(1)
 */

#include "../scripts/dsa_utils.hpp" // Utility parser
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int solve(vector<int> &prices) {
    // Implementation
    // buy low sell high
    int buyPrice = *max_element(prices.begin(), prices.end());
    // can also assign INT_MAX or prices[0] as initial value
    //  vector<int> sellPrices(prices.size(), 0);
    //  using a heap array to store the prices cause
    //  O(N) space complexity,optimal is O(1)
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
      buyPrice = min(buyPrice, prices[i]);
      maxProfit = ((prices[i] - buyPrice) > maxProfit) ? prices[i] - buyPrice
                                                       : maxProfit;
      // instead of ternary ,can also use std::max
    }
    // int maxProfit = *max_element(sellPrices.begin(), sellPrices.end());
    return maxProfit;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Solution sol;

  // Example Parsers:
  vector<int> nums = dsa::parseVector("[7,1,5,3,6,4]");
  // vector<vector<int>> mat = dsa::parseMatrix("[[1,2],[3,4]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  cout << sol.solve(nums);

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
