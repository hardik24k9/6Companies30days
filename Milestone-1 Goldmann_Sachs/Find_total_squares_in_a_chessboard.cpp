#include <bits/stdc++.h>
using namespace std;

// Approach :- 1 brute force (summing up squares of all values)
// Time Complexity :- O(N)
// Starts Complexity :- O(1)

// Approach :- 2 using math formula for calculating sum of squares of all values
// Time Complexity :- O(1)
// Starts Complexity :- O(1)

class Solution 
{
  public:
    long long squaresInChessBoard(long long N) 
    {
        return (N*(N+1)*(2*N+1))/6;
    }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        long long N;
        cin >> N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
} 