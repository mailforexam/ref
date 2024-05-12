#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long, int> pii; //pii is typedef
bool visited[MAX];
vector<pii> adj[MAX]; //aj[MAX]

int prims(int x)
{
    int y;
    pii p;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    //visited[x] = 1;
    q.push(make_pair(0, x));
    int c = 0;

    while (!q.empty())
    {
        p = q.top();
        q.pop();
        x = p.second;

        if (visited[x])
        {
           continue;   //continue not return
        }
        c+=p.first;
        visited[x] = 1;

        for(int i=0;i<adj[x].size();i++)
        {
            y = adj[x][i].second;
            if(!visited[y])
            {
                q.push(adj[x][i]);
            }
        }
    }
    return c;
}

int main()
{
    int n,e,w;
    cout<<"Enter number of nodes : ";cin>>n;
    cout<<"Enter number of edges : ";cin>>e;

    for(int i=0;i<e;i++)
    {
        int x,y;
        cout<<"\nEnter node1 : ";cin>>x;
        cout<<"Enter node2 : ";cin>>y;
        cout<<"Enter weight : ";cin>>w;
        adj[x].push_back(make_pair(w,y));
        adj[y].push_back(make_pair(w,x));
    }

    cout<<"Min cost is : "<<prims(0);
}