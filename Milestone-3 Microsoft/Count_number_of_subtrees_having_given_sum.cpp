#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Approach :- 1 using dfs
// Time Complexity :- O(N)
// Space Complexity :- O(H)

int solve(Node* root,int x,int &ans)
{
    if(!root) return 0;
    
    int sum = solve(root->left,x,ans) + solve(root->right,x,ans) + root->data;
    if(sum == x) ans++;
    
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
    int ans = 0;
	solve(root,X,ans);
	return ans;
}
