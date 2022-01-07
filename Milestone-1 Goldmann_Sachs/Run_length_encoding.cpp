#include <bits/stdc++.h>
using namespace std;

// Approach :- 1 using map
// Time Complexity :- O(N)
// Space Complexity :- O(N)

// Approach :- 2 optimal solution
// Time Complexity :- O(N)
// Space Complexity :- O(1)

string encode(string src)
{     
    int n = src.length();
    string ans = "";
    int val = 0;
    
    for(int i=0;i<n-1;i++)
    {
        if(src[i] == src[i+1]) val++;
        else
        {
            ans += src[i];
            ans += to_string(val+1);
            val = 0;
        }
    }
    
    // corner case
    ans += src[n-1];
    ans += to_string(val+1);
    
    return ans;
}     
 
int main() 
{
	int T;
	cin >> T;
	while(T--)
	{
		string str;
		cin >> str;
		
		cout << encode(str) << endl;
	}
	return 0;
}

