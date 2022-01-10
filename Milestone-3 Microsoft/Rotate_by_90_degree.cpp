#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 brute force (using extra matrix)
// Problem :- Rotate In Anti-clockwise direction (so reverse will be on columns)
// Time Complexity :- O(N*N)
// Space Complexity :- O(N*N)

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    vector<vector<int>> matrix1(n,vector<int> (n));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix1[n-1-i][j] = matrix[j][i];
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j] = matrix1[i][j];
        }
    }
}

// Approach :- 2 taking transpose then reversing all every columns 
// Problem :- Rotate In Anti-clockwise direction (so reverse will be on columns)
// Time Complexity :- O(N*N)
// Space Complexity :- O(1)

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    
    // taking transpose of a matrix
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    // now just reverse every column as it's in anti-clockwise direction
    for(int i=0;i<n/2;i++)
    {
        for(int j=0;j<n;j++)
        {
            swap(matrix[i][j],matrix[n-1-i][j]);
        }
    }
}