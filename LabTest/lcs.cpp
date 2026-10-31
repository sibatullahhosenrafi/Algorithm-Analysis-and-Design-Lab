#include<bits/stdc++.h>
using namespace std;
int c[1005][1005];
string x,y;
set<string>dp[1005][1005];
bool vis[1005][1005];
set<string>LCS(int i,int j)
{
    if(i==0||j==0)
    {
        return {""};
    }
    if(vis[i][j])
    {
        return dp[i][j];
    }
    vis[i][j]=true;
    if(x[i-1]==y[j-1])
    {
        set<string>temp=LCS(i-1,j-1);
        for(string s:temp)
        {
            dp[i][j].insert(s+x[i-1]);
        }
    }
    else {
        if(c[i-1][j]==c[i][j])
        {
            set<string>temp=LCS(i-1,j);
            for(string s:temp)
            {
                dp[i][j].insert(s);
            }
        }
        if(c[i][j-1]==c[i][j])
        {
            set<string>temp=LCS(i,j-1);
            for(string s:temp)
            {
                dp[i][j].insert(s);
            }
        }
    }
    return dp[i][j];
}
int main()
{
    cin>>x>>y;
    int n=x.size();
    int m=y.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                c[i][j]=1+c[i-1][j-1];
            }
            else {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    cout<<"LCS Length"<<c[n][m]<<endl;
    set<string>ans=LCS(n,m);
    cout<<"All LCS"<<endl;
    for(string s:ans)
    {
        cout<<s<<endl;
    }

}
