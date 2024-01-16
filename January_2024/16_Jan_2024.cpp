// Sequence and Sequence
// BOTTOM UP DYNAMIC PROGRAMMING
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int numberSequence(int m, int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(/*max term*/ i==0 or /*no. of term*/ j==0 or i<j){
                    dp[i][j] = 0;
                }
                else if(j==1){
                    dp[i][j] = i;
                }
                else {
                    dp[i][j] = dp[i-1][j] + dp[i/2][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    int m = 10,n = 4;
    cout<<s.numberSequence(m,n);
    return 0;
}