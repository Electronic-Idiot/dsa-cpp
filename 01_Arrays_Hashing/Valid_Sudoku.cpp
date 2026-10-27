/**
 * Problem: Valid_Sudoku
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
  bool solve(vector<vector<char>> &board) {
    // Implementation
    bool rowCheck[9][10] = {false};
    bool colCheck[9][10]{false}; // column 0 is unused ,1-9 is useful to
                                 // us,avoid extra manipluation this way,
    bool subMatrix[9][10] = {
        false}; // array index and element value matches this way

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.')
          continue;

        int curr = board[i][j] - '0';
        int subMatrixCalc = (i / 3) * 3 + (j / 3);

        if (rowCheck[i][curr] || colCheck[j][curr] ||
            subMatrix[subMatrixCalc][curr])
          return false;

        rowCheck[i][curr] = true;
        colCheck[j][curr] = true;
        subMatrix[subMatrixCalc][curr] = true;
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
  vector<vector<int>> mat = dsa::parseMatrix(
      "[[" 1 "," 2 ",".","."," 3 ",".",".",".","."],[" 4 ",".","."," 5 ",".","
          .",".",".","."],["."," 9 "," 8 ",".",".",".",".","."," 3 "],[" 5 ","
          .",".","."," 6 ",".",".","."," 4 "],[".",".","."," 8 ","."," 3 ",".","
          ."," 5 "],[" 7 ",".",".","."," 2 ",".",".","."," 6 "],[".",".",".","
          .",".","."," 2 ",".","."],[".",".","."," 4 "," 1 "," 9 ",".","
          ."," 8 "],[".",".",".","."," 8 ",".","."," 7 "," 9 "]]");
  // ListNode* head = dsa::parseLinkedList("[1,2,3,4,5]");

  sol.solve(mat);

  // Example Printers:
  // dsa::printVector(nums);
  // dsa::printMatrix(mat);
  // dsa::printLinkedList(head);

  return 0;
}
