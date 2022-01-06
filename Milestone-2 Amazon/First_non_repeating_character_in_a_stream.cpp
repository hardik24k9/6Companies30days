#include<bits/stdc++.h>
using namespace std;

// Approach :- 1 using queue
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution 
{
	public:
		string FirstNonRepeatingChar(string A)
		{
		    queue<char> q;
		    int freq[26] = {0};
		    string ans = "";
		    
		    for(int i=0;i<A.length();i++)
		    {
		        q.push(A[i]);
		        freq[A[i] - 97]++;
		        
		        while(q.size() != 0 and freq[q.front() - 97] != 1)
		        {
		            q.pop();
		        }
		        
		        if(q.size() == 0)
		        ans += '#';
		        else
		        ans += q.front();
		    }
		    return ans;
		}
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        Solution ob;
        string ans = ob.FirstNonRepeatingChar(a);
        cout << ans << endl;
    }
}