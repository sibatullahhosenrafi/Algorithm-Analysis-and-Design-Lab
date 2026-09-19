#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];
int find(int node)
{
    cout<<node<<endl;
    if(par[node]==-1)
        return node;
    int leader= find(par[node]);// O(N)
    par[node]=leader;//O(logN)
    return leader;
}
void dsu_union(int node1,int node2)
{
    int leader1=find(node1);
    int leader2=find(node2);
    if(group_size[leader1]>group_size[leader2])
    {
        par[leader2]=leader1;
        group_size[leader1]+=group_size[leader2];
    }
    else
    {
        par[leader1]=leader2;
        group_size[leader2]+=group_size[leader1];
    }
}
class Edge
{
public:
    int a,b,c;
    Edge(int a,int b,int c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
};
bool cmp(Edge l,Edge r)
{
    return l.c<r.c;
}
int main()
{
    memset(par,-1,sizeof(par));
    memset(group_size,1,sizeof(group_size));
    int n,e;
    cin>>n>>e;
    vector<Edge>edge;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back(Edge(a,b,c));
    }
    sort(edge.begin(),edge.end(),cmp);
//    for(auto ed:edge)
//    {
//        cout<<ed.a<<" "<<ed.b<<" "<<ed.c<<endl;
//    }
    // sort korlam matro
    int totalcost=0;
    for(auto ed: edge)
    {
        int parA=find(ed.a);
        int parB=find(ed.b);
        if(parA!=parB)
        {
            dsu_union(ed.a,ed.b);
            totalcost+=ed.c;
        }

    }
    cout<<totalcost<<endl;
}
