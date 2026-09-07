#include <bits/stdc++.h>

using namespace std;
struct Edge
{
    int u,v,w;
};
vector<Edge>ed;
int spanningTree(int &n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<bool>vis(n,false);
    int res=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        pair<int,int>p=pq.top();
        pq.pop();
        int wt=p.first;
        int u=p.second;
        if(vis[u])continue;
        res+=wt;
        vis[u]=true;

        for(int i = 0; i < ed.size(); i++)
        {
            int a = ed[i].u;
            int b = ed[i].v;
            int wt = ed[i].w;

            if(a == u && !vis[b])
            {
                pq.push({wt, b});
            }
            else if(b == u && !vis[a])
            {
                pq.push({wt, a});
            }
        }

    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back({u,v,w});
    }
    cout<<spanningTree(n);

}
