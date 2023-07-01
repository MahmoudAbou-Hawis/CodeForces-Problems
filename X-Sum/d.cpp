#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Tourists cout.tie(0);
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
int n,m;
vector<vector<ll>>grid;
vector<vector<ll>>gridR;
vector<vector<ll>>gridY;
bool valid(int x,int y)
{
    return (x>=0 && x< n && y>=0 && y<m);
}
ll dfs(int x,int y ,ll sum)
{
    if(valid(x,y))
    {
        return gridR[x][y] = dfs(x+1,y+1,sum + grid[x][y]) ; 
    }
    else
    {
        return sum;
    }
}
ll dfs2(int x,int y ,ll sum)
{
    if(valid(x,y))
    {
      return gridY[x][y] =   dfs2(x+1,y-1,sum+grid[x][y]);
    }
    else
    {
        return  sum;
    }

}
int main(){
    Created By Tourists
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        grid = vector<vector<ll>>(n,vector<ll>(m));
        gridR = vector<vector<ll>>(n,vector<ll>(m,-1));
        gridY = vector<vector<ll>>(n,vector<ll>(m,-1));
        for(int i = 0 ; i < n ;i++)
        {
            for(int e = 0 ;e < m ;e++)
            {
                cin>>grid[i][e];
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int e = 0 ;e < m ;e++)
            {
                if(gridR[i][e] == -1)
                {
                    dfs(i,e,0);
                }
                 if(gridY[i][e] == -1)
                {
                    dfs2(i,e,0);
                }
            }
        }
        long long int result = 0;
        for(int i = 0 ; i < n ;i++)
        {
            for(int e = 0 ; e< m ;e++)
            {
                result = max(result,gridR[i][e] + gridY[i][e] - grid[i][e]);
            }
        }
        cout<<result<<'\n';
    }
    

    return 0;
}


