#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 
// Time Complexity :- O(N*N)
// Space Complexity :- O(1)

class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        vector<int> ans;
        int left = 0,right = c-1;
        int top = 0,down = r-1;
        
        int dir = 0;
        
        while(left <= right and top <= down)
        {
            if(dir == 0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1)
            {
                for(int i=top;i<=down;i++)
                {
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }
            else if(dir == 3)
            {
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};