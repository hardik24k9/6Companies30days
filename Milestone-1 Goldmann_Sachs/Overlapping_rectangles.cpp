#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using observation
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution 
{
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) 
    {
        if((R2[1] > L1[1]) or (R1[1] > L2[1]) or (L1[0] > R2[0]) or (L2[0] > R1[0]) )
        {
            return false;
        }
        return true;
    }
};