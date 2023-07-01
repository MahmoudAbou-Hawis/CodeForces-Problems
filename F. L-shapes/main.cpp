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
vector<vector<char>>graph;  
vector<vector<bool>>visited;
int n,m;
int dx[] ={1,1,0,1,-1,-1,0,-1};
int dy[] ={0,1,1,-1,1,0,-1,-1};
bool valid(int x , int y)
{
    return (x<n && x>=0 && y<m && y >=0);
}
int dfs(int x ,int y)
{
    if(visited[x][y])
    {
        return 0;
    }
    visited[x][y] = true;
    int number = 1;
    for(int i = 0 ; i < 8 ; i++)
    {
       int xChild = x + dx[i];
       int yChild = y + dy[i];
   
       if(valid(xChild,yChild) && graph[xChild][yChild]=='*') 
       {
           number += dfs(xChild,yChild); 
       }
    }
    return number;
}
bool cheacker(int x , int y)
{
    if(valid(x,y+1) && graph[x][y+1]=='*' && valid(x+1,y) &&(graph[x+1][y]=='*' ||graph[x+1][y+1]=='*' ))
    {
        return true;
    }
    if(valid(x+1,y) &&(graph[x+1][y]=='*') &&(graph[x+1][y+1]=='*'||graph[x+1][y-1]=='*'))
    {
        return true;
    }
    return false;
}
int main()
{
    Created By Sofar
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        graph   = vector<vector<char>>(n+1,vector<char>(m+1));
        visited = vector<vector<bool>>(52,(vector<bool>(52,0))); 
        bool Accepted = true;
        for(int i=0 ; i < n && Accepted;i++)
        {
            for(int e = 0 ;e < m ; e++)
            {
                cin>>graph[i][e];
            }
        }
        for(int i = 0 ; i < n ;i++)
        {
            for(int e = 0 ; e < m ;e++)
            {
                if(!visited[i][e] && graph[i][e] =='*')
                {
                    bool totalAsteriskTrue = ((dfs(i,e)==3)&& cheacker(i,e));
                    if(!totalAsteriskTrue)
                    {
                        Accepted = false;
                        break;
                    }
                }
            }
          
        }
        
        cout<<((Accepted)?"YES\n":"NO\n");

    }

    return 0;
}


