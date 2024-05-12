#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int level)
{
    visited[node] = 1;
    cout << "\nNode :  " << node << "   Level : " << level << endl;
    level++;

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            dfs(graph, visited, neighbour, level );
        }
    }
}

void bfs(vector<vector<int>> &graph, vector<bool> &visited, int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    queue<int>l;
    l.push(0);

    //int level = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int level = l.front();
        l.pop();

        cout << "Node : " << node << "  level : " << level << endl;
        //level++;

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                q.push(neighbour);
                l.push(level+1);
            }
        }
    }
}

int main()
{
    vector<vector<int>>graph ={
        {1, 5},     // Adjacent nodes of node 0
        {0, 2},  // Adjacent nodes of node 1
        {1, 3},     // Adjacent nodes of node 2
        {2,4},        // Adjacent nodes of node 3
        {3, 5},
        {0,4}

    } ;

    vector<bool>visited(graph.size(),false);

    dfs(graph,visited,0,0);

    fill(visited.begin(),visited.end(),false);

    bfs(graph,visited,0);
}

/*

RECURSIVE CODE FOR BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, vector<bool> &visited, queue<int> &q)
{
    if (q.empty())
        return;

    int node = q.front();
    q.pop();

    cout << "Node: " << node << endl;

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            visited[neighbour] = true;
            q.push(neighbour);
        }
    }

    bfs(graph, visited, q); // Recursively call bfs for the next level
}

int main()
{
    vector<vector<int>> graph = {
        {1, 5}, // Adjacent nodes of node 0
        {0, 2}, // Adjacent nodes of node 1
        {1, 3}, // Adjacent nodes of node 2
        {2, 4}, // Adjacent nodes of node 3
        {3, 5}, // Adjacent nodes of node 4
        {0, 4}  // Adjacent nodes of node 5
    };

    vector<bool> visited(graph.size(), false); // Initialize visited array with proper size
    queue<int> q;

    // Start BFS from node 0
    q.push(0);
    visited[0] = true;
    bfs(graph, visited, q);

    return 0;
}


*/