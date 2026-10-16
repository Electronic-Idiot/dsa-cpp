#!/usr/bin/env bash

if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: ./scripts/new_problem.sh <Folder_Prefix> <Problem_Name>"
    echo "Example: ./scripts/new_problem.sh 01 \"Two_Sum\""
    exit 1
fi

TARGET_DIR=$(ls -d ${1}_* 2>/dev/null | head -n 1)

if [ -z "$TARGET_DIR" ]; then
    echo "Error: Directory matching prefix '$1' not found."
    exit 1
fi

FILE_NAME="$(echo "$2" | tr ' ' '_').cpp"
FULL_PATH="$TARGET_DIR/$FILE_NAME"

if [ -f "$FULL_PATH" ]; then
    echo "File already exists: $FULL_PATH"
    exit 1
fi

cat << TEMPLATE > "$FULL_PATH"
/**
 * Problem: $2
 * Platform: LeetCode / GfG
 * Pattern: 
 * Complexity:
 *   - Time:  O()
 *   - Space: O()
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../scripts/dsa_utils.hpp" // Utility parser

using namespace std;

class Solution {
public:
    void solve() {
        // Implementation
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
TEMPLATE

chmod +x "$FULL_PATH"
echo "Created: $FULL_PATH"
code "$FULL_PATH" 2>/dev/null || codium "$FULL_PATH" 2>/dev/null || true
