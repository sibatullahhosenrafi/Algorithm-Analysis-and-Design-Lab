#include <bits/stdc++.h>

using namespace std;
int cutRod(vector<int>&price,int n)
{
    vector<int>dp(n+1,0);
    for(int i=1; i<=n; i++)
    {
        int rodLength=i;
        int currentPrice=price[i-1];
        for(int j=rodLength; j<=n; j++)
        {
            dp[j]=max(dp[j],currentPrice+dp[j-rodLength]);
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++)cin>>price[i];
    int maxProfit = cutRod(price,n);
    cout << "Length of rod: " << n <<endl;
    cout << "Maximum obtainable value: " << maxProfit << endl; 
  /*8
1 5 8 9 10 17 17 20
ans = 22 */
}

