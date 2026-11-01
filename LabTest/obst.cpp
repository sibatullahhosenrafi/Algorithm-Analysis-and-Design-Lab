#include<bits/stdc++.h>
using namespace std;
int n;
int dp[105][105];
int root[105][105];
int f[105];
void printTree(int i,int j)
{
    if(i>j)
        return;
    int  k=root[i][j];
    cout<<"Root  "<<k<<endl;
    if(i==j)
    {
        cout<<"Key has no child"<<endl;
        return;
    }
    if(i<=k-1)
    {
        cout<<"Left child of"<<k<<endl;
        printTree(i,k-1);
    }
    if(j>=k+1)
    {
        cout<<"Right child of "<<k<<endl;
        printTree(k+1,j);
    }
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)cin>>f[i];
    for(int len=1; len<=n; len++)
    {
        for(int i=1; i<=n-len+1; i++)
        {
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            double sum=0;
            for(int k=i; k<=j; k++)
            {
                sum+=f[k-1];
            }
            for(int k=i; k<=j; k++)
            {
                int cost=dp[i][k-1]+dp[k+1][j]+sum;
                if(dp[i][j]>cost)
                {
                    root[i][j]=k;
                    dp[i][j]=cost;
                }
            }
        }
    }
    cout<<"Minimum Search Cost"<<endl;
    cout<<dp[1][n]<<endl;
    cout<<"BST"<<endl;
    printTree(1,n);


}
