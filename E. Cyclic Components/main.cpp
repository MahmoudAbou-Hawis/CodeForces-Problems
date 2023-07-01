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
int n,m;
const int N = 3e5 +40;
vector<int>graph[N];
bool inPath[N];
vector<int>v(N,0);
int Parents[N];
int FindParent(int node)
{
    return Parents[node] = ((node == Parents[node])?node: FindParent(Parents[node]));
}
void join(int x, int y)
{
    int a = FindParent(x);
    int b = FindParent(y);
    if(a!=b)
        Parents[a]=b;
}
int dfs(int Node , int parent)
{
    if(v[Node] != 2)
    {
       return  0;
    }
    inPath[Node]  = 1;
    for(auto &child : graph[Node])
    {
        if(parent!=child)
        {
            if(inPath[child])
            {
                inPath[Node] =0;
                return child;
            }
            else
            {
               return dfs(child,Node);
            }
        }
    }

}

int main()
{
    Created By Sofar
    for(int i = 0 ;i < N ;i++)
    {
        Parents[i]=i;
    }
    cin>>n>>m;
    for(int i =  0 ; i < m ; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
        v[a]++;
        v[b]++;
        join(a,b);
    }
    int ans =0;
    for(int i = 1 ; i <=n ; i++)
        if(Parents[i]==i)
           if(dfs(i,0)==i)ans++;
    cout<<ans<<'\n';
    return 0;
}


