#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Approach :- 1 using bfs 
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            
            int val = (temp) ? temp->data : 0 ;
            ans.push_back(val);
            
            if(temp)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node* deSerialize(vector<int> &A)
    {
        int idx = 0;
        
        queue<Node*> q;
        Node* root = new Node(A[idx++]);
        q.push(root);
        
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            
            if(A[idx] != 0)
            {
                node->left = new Node(A[idx++]);
                q.push(node->left);
            }
            else
            {
                node->left = NULL;
                idx++;
            }
        
            if(A[idx] != 0)
            {
                node->right = new Node(A[idx++]);
                q.push(node->right);
            }
            else
            {
                node->right = NULL;
                idx++;
            }
        }
        
        return root;
    }
};