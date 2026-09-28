#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int src, int sink,
         vector<int> &parent) {

    int V = rGraph.size();

    vector<bool> vis(V, false);
    queue<int> q;

    q.push(src);
    vis[src] = true;
    parent[src] = -1;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (int v = 1; v < V; v++) {

            if (!vis[v] && rGraph[u][v] > 0) {

                vis[v] = true;
                parent[v] = u;

                if (v == sink)
                    return true;

                q.push(v);
            }
        }
    }

    return false;
}

int findMaxFlow(int V, vector<vector<int>> &edges) {

    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int cap = edge[2];

        graph[u][v] = cap;
    }

    vector<vector<int>> rGraph = graph;

    int src = 1;
    int sink = V;

    vector<int> parent(V + 1);
    int maxFlow = 0;

    while (bfs(rGraph, src, sink, parent)) {

        int pathFlow = INT_MAX;

        for (int v = sink; v != src; v = parent[v]) {

            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = sink; v != src; v = parent[v]) {

            int u = parent[v];

            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {

    int V = 4;

    vector<vector<int>> edges = {
        {1, 2, 10},
        {1, 3, 10},
        {2, 3, 10},
        {2, 4, 10},
        {3, 4, 10}
    };

    cout << findMaxFlow(V, edges) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
};

// Prim's algorithm - returns total cost and fills mstEdges with the tree edges
int spanningTree(int &n, vector<Edge> &mstEdges, vector<Edge> &ed)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> key(n + 1, INT_MAX);   // best edge weight seen so far for each vertex
    int res = 0;

    // start from the smallest vertex label (works for 0-indexed and 1-indexed input)
    int start = INT_MAX;
    for (auto &x : ed)
        start = min(start, min(x.u, x.v));
    if (start == INT_MAX) return 0;

    key[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int wt = p.first;
        int u = p.second;
        if (vis[u]) continue;

        res += wt;
        vis[u] = true;
        if (parent[u] != -1)
            mstEdges.push_back({parent[u], u, wt});

        for (int i = 0; i < (int)ed.size(); i++)
        {
            int a = ed[i].u;
            int b = ed[i].v;
            int w = ed[i].w;

            if (a == u && !vis[b] && w < key[b])
            {
                key[b] = w;
                parent[b] = u;
                pq.push({w, b});
            }
            else if (b == u && !vis[a] && w < key[a])
            {
                key[a] = w;
                parent[a] = u;
                pq.push({w, a});
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<Edge>> forest;   // MST of every graph, together = the Minimum Spanning Forest
    vector<int> costs;             // individual cost of each graph's MST

    for (int g = 1; g <= 3; g++)
    {
        int n, e;
        cin >> n >> e;
        vector<Edge> ed;
        while (e--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            ed.push_back({u, v, w});
        }

        cout << "========================================\n";
        cout << "GRAPH " << g << " (V = " << n << ")\n";
        cout << "========================================\n";

        vector<Edge> mstEdges;
        int cost = spanningTree(n, mstEdges, ed);

        cout << "Minimum Spanning Tree edges (u - v : w):\n";
        for (auto &x : mstEdges)
            cout << "  " << x.u << " - " << x.v << " : " << x.w << "\n";

        cout << "\nCost to build the Minimum Spanning Tree for Graph " << g
             << " = " << cost << "\n\n";

        forest.push_back(mstEdges);
        costs.push_back(cost);
    }

    // ---------- Minimum Spanning Forest (all 3 trees together) ----------
    cout << "========================================\n";
    cout << "MINIMUM SPANNING FOREST (Graph 1 + Graph 2 + Graph 3)\n";
    cout << "========================================\n";

    int forestTotalCost = 0;
    for (int g = 0; g < (int)forest.size(); g++)
    {
        cout << "Tree " << (g + 1) << " (Graph " << (g + 1) << ") edges:\n";
        for (auto &x : forest[g])
            cout << "  " << x.u << " - " << x.v << " : " << x.w << "\n";
        cout << "  Cost of Tree " << (g + 1) << " = " << costs[g] << "\n\n";
        forestTotalCost += costs[g];
    }

    cout << "Total cost to build the Minimum Spanning Forest = "
         << forestTotalCost << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int par[1005];
int group_size[1005];

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = par[node] = find(par[node]);
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if (group_size[leader1] > group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edge l, Edge r)
{
    return l.c < r.c;
}

// Generates a random complete weighted graph on n vertices (weights 1..maxW)
vector<Edge> generateCompleteGraph(int n, int maxW)
{
    vector<Edge> edge;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            edge.push_back(Edge(i, j, 1 + rand() % maxW));
    return edge;
}

void printGraph(vector<Edge> &edge)
{
    cout << "Edges (u - v : w):\n";
    for (auto &e : edge)
        cout << "  " << e.a << " - " << e.b << " : " << e.c << "\n";
}

int main()
{
    srand(time(0));
    int n = 10;      // V = 10
    int maxW = 50;   // random weight range 1..50

    vector<vector<Edge>> forest;   // MST of every graph, together = the Minimum Spanning Forest
    vector<int> costs;             // individual cost of each graph's MST

    for (int g = 1; g <= 3; g++)
    {
        cout << "========================================\n";
        cout << "GRAPH " << g << " (V = " << n << ", complete graph)\n";
        cout << "========================================\n";

        vector<Edge> edge = generateCompleteGraph(n, maxW);
        printGraph(edge);

        sort(edge.begin(), edge.end(), cmp);

        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            group_size[i] = 1;
        }

        vector<Edge> mstEdges;
        int totalCost = 0;
        for (auto &ed : edge)
        {
            int parA = find(ed.a);
            int parB = find(ed.b);
            if (parA != parB)
            {
                dsu_union(ed.a, ed.b);
                totalCost += ed.c;
                mstEdges.push_back(ed);
            }
        }

        cout << "\nMinimum Spanning Tree edges (u - v : w):\n";
        for (auto &e : mstEdges)
            cout << "  " << e.a << " - " << e.b << " : " << e.c << "\n";

        cout << "\nCost to build the Minimum Spanning Tree for Graph " << g
             << " = " << totalCost << "\n\n";

        forest.push_back(mstEdges);
        costs.push_back(totalCost);
    }

    // ---------- Minimum Spanning Forest (all 3 trees together) ----------
    cout << "========================================\n";
    cout << "MINIMUM SPANNING FOREST (Graph 1 + Graph 2 + Graph 3)\n";
    cout << "========================================\n";

    int forestTotalCost = 0;
    for (int g = 0; g < (int)forest.size(); g++)
    {
        cout << "Tree " << (g + 1) << " (Graph " << (g + 1) << ") edges:\n";
        for (auto &e : forest[g])
            cout << "  " << e.a << " - " << e.b << " : " << e.c << "\n";
        cout << "  Cost of Tree " << (g + 1) << " = " << costs[g] << "\n\n";
        forestTotalCost += costs[g];
    }

    cout << "Total cost to build the Minimum Spanning Forest = "
         << forestTotalCost << "\n";

    return 0;
}
