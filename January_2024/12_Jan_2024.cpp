//Reverse First K elements of Queue

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        queue<int> ans;
        while(k--)
        {
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
             ans.push(s.top());
             s.pop();
        }
        while(!q.empty()){
            ans.push(q.front());
            q.pop();
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
    queue<int> q;
    queue<int>ans;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    ans = s.modifyQueue(q,k);
    for(int i=0;i<q.size();i++){
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}