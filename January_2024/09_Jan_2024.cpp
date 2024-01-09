// Search Pattern (KMP-Algorithm)

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> ans;
            int i = 0;
            while(i < txt.size()){
                
                int k = i;
                int j = 0;
                while(j < pat.size() && txt[k] == pat[j]){
                    k++;
                    j++;
                }
                if(j == pat.size()){
                    ans.push_back(i+1);
                }
                i++;
            }
            return ans;
        }
     
};

int main()
{
    Solution s;
    string txt = "geeksforgeeks";
    string pat = "geek";
    vector<int> vec;
    vec = s.search(txt, pat);

    for(int i=0;i<vec.size();i++)
       cout<<vec[i]<<" ";
    return 0;
}
