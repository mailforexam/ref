#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 1e4 + 5;

// id[MAX] array stores the parent of each vertex in the graph
int id[MAX], nodes, edges;

/*
In the context of the provided code, this array p is used to store the edges of the graph,
where each edge is represented as a pair. The first element of the pair represents the weight of the 
edge (of type long long), and the second element is a pair of integers representing the vertices 
connected by the edge
*/

pair <long long, pair<int, int> > p[MAX];
//remember only pii in prims and p[max] in kruskal
void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

/*

 The root function helps find the main representative (or "root") of a group of connected vertices. 
 This representative indicates which group or component each vertex belongs to in a graph.

*/
int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

//union joins two vertices
void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long w, mcost;
    initialize();
    cout << "Enter nodes : ";
    cin >> nodes;
    cout << "Enter no of edges : ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "\nFirst Vertex : ";
        cin >> x;
        cout << "Second Vertex : ";
        cin >> y;
        cout << "Weight : ";
        cin >> w;
        p[i] = make_pair(w, make_pair(x, y));
    }

    sort(p, p + edges);
    cout << "MIn cost : " << kruskal(p);
}