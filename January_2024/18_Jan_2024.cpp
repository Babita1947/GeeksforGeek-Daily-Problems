//water the plants

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        int arr[n];
        memset(arr,-1,sizeof(arr));
        for(int i=0;i<n;i++){
            if(gallery[i] == 0){
                arr[i] = max(arr[i],i);
            }
            else if(gallery[i] != -1){
                int start = i-gallery[i];
                int end = i + gallery[i];
                start = max(0,start);
                end = min(end,n);
                for(int j = start;j<=end;j++){
                    arr[j]=max(arr[j],end);
                }
            }
        }
        int ans = 0,i = 0;
        while(i < n){
            if(arr[i] == -1 || i == -1){
                return -1;
            }
            ans++;
            i = arr[i]+1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n = 6;
    int gallery[] = {-1, 2, 2, -1, 0, 0};
    cout<<s.min_sprinklers(gallery,n);
    return 0;
}