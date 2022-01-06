#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 Using observation
// Time Complexity :- O(1)
// Space Complexity :- O(1)

// There can be multiple approaches to this problem by using recursion and dp.

class Solution2
{
    public:
    //Function to count number of ways to reach the nth stair when order does not matter.
    long long countWays(int m)
    {
        // firstly all ones will be the first solution , then we combine two 1s to get one 2
        return (long)((m/2)+1);
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin >> m;
        Solution2 ob;
        cout << ob.countWays(m) << endl; 
    }
}