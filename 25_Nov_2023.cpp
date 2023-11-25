// Suffle Integers
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void shuffleArray(int arr[], int n) {
        int temp = n / 2;
        vector<int> v1;
        vector<int> v2;

        for (int i = 0; i < temp; i++) {
            v1.push_back(arr[i]);
        }

        for (int i = temp; i < n; i++) {
            v2.push_back(arr[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                arr[i] = v1[i / 2]; // Use i/2 to access indices in v1
            else
                arr[i] = v2[i / 2]; // Use i/2 to access indices in v2
        }
    }
};

int main()
{
    Solution s;
    int n = 6 ;
    int arr[] = {1, 2, 3, 4, 5, 6};
    s.shuffleArray(arr,n);
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    return 0;
}