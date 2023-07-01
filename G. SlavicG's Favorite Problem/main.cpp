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
const int N = 1e5 + 10;
vector<pair<int,int>> graph[N];
int n,a,b;
bool flag = false;
set<int>may;
void clr()
{
    for(int i = 0 ; i < n ; i++)
    {
        graph[i].clear();
    }
}

void DfsFromSrc(int src,int par , int x)
{
    if(src == b) return;
    may.insert(x);
    for(auto child:graph[src])
    {
        int w    = child.s;
        int node = child.f; 
        if(node != par)
        {
            DfsFromSrc(node , src , w^x);
        }
    }
}

bool DfsFromDes(int src,int par , int x)
{
    if(src !=b && may.count(x)) return true;
    for(auto child:graph[src])
    {
        int w    = child.s;
        int node = child.f; 
        if(node != par)
        {
            if(DfsFromDes(node , src , w^x))
                return true;
        }
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
        may.clear();
        cin>>n>>a>>b;
        --a,--b;
        clr();
        for(int i = 0 ; i < n -1 ; i++)
        {
            int x,y,w;
            cin>>x>>y>>w;     
            --x,--y;
            graph[x].push_back({y,w});
            graph[y].push_back({x,w});
        }
        DfsFromSrc(a,-1,0);

        cout<<(DfsFromDes(b,-1,0) ? "YES\n":"NO\n");

    }
    return 0;
}