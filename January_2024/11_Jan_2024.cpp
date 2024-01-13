//Remove K Digits

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string removeKdigits(string S, int K) {
        if (S.length() == K)
          return "0";
    
        string ans;
        vector<char> stack;
    
        for (int i = 0; i < S.length(); ++i) {
          while (K > 0 && !stack.empty() && stack.back() > S[i]) {
            stack.pop_back();
            --K;
          }
          stack.push_back(S[i]);
        }
    
        while (K-- > 0)
          stack.pop_back();
    
        for (const char c : stack) {
          if (c == '0' && ans.empty())
            continue;
          ans += c;
        }
    
        return ans.empty() ? "0" : ans;
    }
};