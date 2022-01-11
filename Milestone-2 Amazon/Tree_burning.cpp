#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using bfs
// Time Complexity :- O(2*N) -> O(N) , where O(N) for mapping and O(N) for finding the max_time
// Space Complexity :- O(2*N) -> O(N) , where O(N) for map and O(N) for queue 

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

class Solution
{
  public:
  
    int find_Max_Distance(map<Node*,Node*> &mp,Node* target)
    {
        queue<Node*> q;
        q.push(target);
        map<Node*,int> vis;
        vis[target] = 1;
        int maxi = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            int fl = 0;
            
            for(int i=0;i<sz;i++)
            {
                Node* temp = q.front();
                q.pop();
                
                if(temp->left and !vis[temp->left])
                {
                    fl = 1;
                    vis[temp->left] = 1;
                    q.push(temp->left);
                }
                
                if(temp->right and !vis[temp->right])
                {
                    fl = 1;
                    vis[temp->right] = 1;
                    q.push(temp->right);
                }
                
                if(mp[temp] and !vis[mp[temp]])
                {
                    fl = 1;
                    vis[mp[temp]] = 1;
                    q.push(mp[temp]);
                }
            }
            if(fl) maxi++;
        }
        
        return maxi;
    }
  
    Node* map_all_nodes_with_parent_node(map<Node*,Node*> &mp,Node* root,int target)
    {
        queue<Node*> q;
        q.push(root);
        
        Node* ref;
        
        while(!q.empty())
        {
            Node* temp = q.front();
            if(temp->data == target) ref = temp;
            q.pop();
            
            if(temp->left)
            {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        return ref;
    }
  
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*> mp;
        Node* target_ref = map_all_nodes_with_parent_node(mp,root,target);
        int maxi = find_Max_Distance(mp,target_ref);
        return maxi;
    }
};