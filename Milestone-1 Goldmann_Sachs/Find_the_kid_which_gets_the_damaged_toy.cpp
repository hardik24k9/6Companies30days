#include <bits/stdc++.h>
using namespace std;

// Approach :- 1 using observation
// Time Complexity :- O(1)
// Space Complexity :- O(1)

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;

        // n is the size of the circle
        // m is the number of items to be distributed
        // k is the starting point of the distribution

        if(k-1+m <= n)
        {
            cout << k-1+m << endl;
        }
        else
        {
            int v1 = n-k+1;
            m -= v1;
            m %= n;
            
            if(m == 0) m = n; // corner case
            cout << m << endl;
        }
    }
}