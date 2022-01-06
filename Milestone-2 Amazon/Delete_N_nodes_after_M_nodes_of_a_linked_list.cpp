#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* start = NULL; 

void insert(int n)
{
    Node* temp;

    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if(i == 0)
        {
            start = new Node(val);
            temp = start;
        }
        else
        {
            temp->next = new Node(val);
            temp = temp->next;
        }
    }
}

void printList(Node* temp)
{
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        if(!head) return;
        
        Node* temp = head;
        
        while(temp)
        {
            int cnt1 = 1;
            
            while(temp and cnt1 < M)
            {
                temp = temp->next;
                cnt1++;    
            }
            
            if(!temp) return;
            
            Node* prev = temp;
            temp = temp->next;
            int cnt2 = 0;
            
            while(temp and cnt2 < N)
            {
                temp = temp->next;
                cnt2++;
            }
            
            prev->next = temp;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n1;
        cin >> n1;
        int m,n;
        cin >> m >> n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    return 0;
}