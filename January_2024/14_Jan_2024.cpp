//Find duplicate rows in a binary matrix

#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        unordered_set<string> seen_rows;
        vector<int> duplicate_rows;

        for (int i = 0; i < M; ++i) {
            // Convert the row to a string for easy comparison
            string row_str(matrix[i].begin(), matrix[i].end());

            // Check if the row string is already seen
            if (seen_rows.count(row_str) > 0) {
                duplicate_rows.push_back(i);
            } else {
                seen_rows.insert(row_str);
            }
        }

        return duplicate_rows;
    } 
};