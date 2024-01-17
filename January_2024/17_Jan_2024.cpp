//All Unique Permutations of an array

#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<int>&nums,vector<vector<int>>&ans,int index){
        // Base case
        if(index == nums.size()-1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        
        for(int j=index;j<nums.size();j++){
            //check for duplicates before swapping.
            if(used.count(nums[j])==1)
               continue;
            used.insert(nums[j]);
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            //Backtrack
            swap(nums[index],nums[j]);
        }
    }
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> ans;
        int index = 0;
        solve(arr,ans,index);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr{1,1,2};
    int n = 3;
    vector<vector<int>> ans;
    ans = s.uniquePerms(arr,n);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}