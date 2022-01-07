#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using maps
// Time complexity :- O(N*S*(Log(S))) , where S is the length of the string
// Space Complexity :- O(N*S) 

vector<vector<string>> Anagrams(vector<string>& string_list) 
{
    map<string,vector<string>> mp;
    int n = string_list.size();
    
    for(int i=0;i<n;i++)
    {
        string s = string_list[i];
        sort(s.begin(),s.end());
        
        mp[s].push_back(string_list[i]);
    }
    
    vector<vector<string>> v;
    
    for(auto k : mp)
    {
        v.push_back(k.second);
    }
    return v;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<string> string_list(n);
        for (int i = 0; i < n; ++i) cin >> string_list[i]; 

        vector<vector<string>> result = Anagrams(string_list);
        sort(result.begin(),result.end());

        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}