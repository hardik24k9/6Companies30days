#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 brute force 
// Time Complexity :- O(N*N)
// Space Complexity :- O(1)

// Approach :- 2 optimal solution
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution
{
    public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0;i<n;i++)
        {
            int days = 1;
            
            while(!st.empty() and st.top().first <= price[i])
            {
                days += st.top().second;
                st.pop();
            }
            
            st.push({price[i],days});
            ans.push_back(days);
        }
        
        return ans;
    }
};
