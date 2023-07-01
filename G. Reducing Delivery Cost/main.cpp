#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
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
#define infinity 0x3f3f3f3f
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
const int N=2000;
int dis[N][N];
int Costs[N];
vector<pi>adj[N];

void clr(){
    fi(i,0,N){
        Costs[i]=infinity;
    }
}
void dijkstra(int src){
    priority_queue<pi>priorityQueue;
    priorityQueue.push({0,src});
    Costs[src]=0;
    while(!priorityQueue.empty()){
        pi node = priorityQueue.top();
        priorityQueue.pop();
           node.first*=-1;
        if(node.first != Costs[node.second])
            continue;
        for(auto child : adj[node.second]){
            if(node.first + child.first < Costs[child.second]){
                dis[src][child.second]=node.first+child.first;
                Costs[child.second]=node.first+child.first;
                priorityQueue.push({-Costs[child.second],child.second});
            }
        }
    }
}
int main() {
    setIO();
    int n,m,q;
    cin>>n>>m>>q;
    vector<pi>edges;
    for(int i = 0 ; i < m ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b});
        adj[a].pb({c,b});
        adj[b].pb({c,a});
    }
    for(int i = 1 ; i <=n;i++) {
        clr();
        dijkstra(i);
    }
    vector<pi>qu;
    for(int i = 0 ; i < q; i++){
        int a,b;
        cin>>a>>b;
        qu.pb({a,b});
    }
    long long int  reult  = 1e9;
    for(int i=0;i<m;i++){
        long long int sum = 0;
        int VertixX= edges[i].first;
        int VertixY = edges[i].second;
        for(int e = 0 ;e <q;e++){
            sum+=min({dis[qu[e].first][qu[e].second], dis[qu[e].first][VertixX] + dis[VertixY][qu[e].second] , dis[qu[e].f][VertixY]+dis[VertixX][qu[e].s] });
        }
        reult=min(reult , sum);
    }
    cout<<reult<<'\n';
    return 0;
}
