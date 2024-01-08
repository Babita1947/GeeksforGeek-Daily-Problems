//Split Array Largest Sum

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int countStudents(vector<int> &arr, int pages) {
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                students += 1;
                pagesStudent = arr[i];
            }
        }
        return students;
    }

public:
    int splitArray(int arr[], int N, int K) {
        if (K > N)
            return -1;

        vector<int> nums(arr, arr + N);  // Convert array to vector
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(nums, mid);

            if (students > K) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int arr[4] = {1, 2, 3, 4};
    int N = 4, K = 3;
    cout<<s.splitArray(arr,N,K);
    return 0;
}

