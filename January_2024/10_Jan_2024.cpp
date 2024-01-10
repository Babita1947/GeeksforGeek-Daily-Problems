//Longest subarray with sum divisible by K

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0,rem,mx=0;
	    unordered_map<int,int>mp;
	   
	    for(int i=0;i<n;i++){
	        
	        sum += arr[i];
	        rem=sum%k;
	        
	        if(rem == 0)
	          mx = max(mx,i+1);
	        
	        if(rem<0)
	          rem += k;
	         
	        if(mp.find(rem)!=mp.end())
	        {
	            mx = max(mx,i-mp[rem]);
	        }
	        else
	        {
	            mp[rem] = i;
	        }
	    }
	    return mx;
	}    
};

int main()
{
    Solution s;
    int N = 6, K = 3;
    int arr[] = {2, 7, 6, 1, 4, 5};
    cout<<s.longSubarrWthSumDivByK(arr,N,K);
    return 0;
}