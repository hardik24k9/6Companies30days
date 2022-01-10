#include<bits/stdc++.h>
using namespace std;

// Approach :- 1
// Time Complexity :- O(N*LogN)
// Space Complexity :- O(N*LogN)

vector<string> generate(int N)
{
    vector<string> ans;
    
	for(int i=1;i<=N;i++)
	{
	    string k = "";
	    int num = i;
	    
	    while(num>0)
	    {
	        if(num%2)
	        {
	            k += "1";
	        }
	        else
	        {
	            k += "0";
	        }
	        num /= 2;
	    }
	    
	    reverse(k.begin(),k.end());
	    ans.push_back(k);
	}
	
	return ans;
}