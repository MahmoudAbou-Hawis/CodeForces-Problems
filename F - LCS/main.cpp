#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Sofar cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;   
int main()
{
    Created By Sofar
    string a,b;
    cin>>a>>b;
    vector<vector<int>>dp(3001,vector<int>(3001,0));
    for(int i = 1 ; i <= a.size(); i++)
    {
        for(int e = 1 ; e <= b.size() ; e++)
        {
           if(a[i-1]==b[e-1])
           {
              dp[i][e] = 1 + dp[i-1][e-1];
           }
           else
           {
            dp[i][e] = max(dp[i][e-1], dp[i-1][e]); 
           }
        }
    }
    for(int i = 1 ; i <= a.size(); i++)
    {
        for(int e = 1  ; e <= b.size() ; e++)
        {
            cout<<dp[i][e]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}


