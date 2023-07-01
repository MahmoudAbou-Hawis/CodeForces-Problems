#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Mahmoud_Abou_Hawis cout.tie(0);
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
const ll N = 1e5 +10;
vector<pair<pair<ll,ll>,ll>>graph[N];
ll n ,m ,MaxC;
ll Costs[N];
void clear()
{
    for(int i = 0 ; i < N ;i++) {
        graph[i].clear();
        Costs[i] = LOO;
    }
}

bool dijkstra(ll w)
{
    for(int i = 0 ; i < N ;i++)
        Costs[i] = LOO;
    priority_queue<ll , vector<ll>, greater<ll>>p_q;
    p_q.push(1);
    Costs[1] = 0;
    while(!p_q.empty())
    {
        ll Node = p_q.top();
        if(Node == n)
        {
            return true;
        }
        p_q.pop();
        for(auto &child : graph[Node])
        {
            if(child.first.first + Costs[Node] < MaxC && child.first.first + Costs[Node] < Costs[child.s] && child.first.second<=w )
            {
                    p_q.push(child.s);
                    Costs[child.s] =  child.first.first + Costs[Node] ;
            }
        }
    }
    return false;
}

ll binarySearch()
{
    ll low= 1 ; ll high = 1e9+1;
    while(low<high)
    {
        ll mid = low + (high-low)/2;
        if(dijkstra(mid))
        {
            high = mid;
        }else{
            low = mid +1 ;
        }
    }
    return ((high > (ll)1e9)? (ll)-1:high);
}


int main(){
    Created By Mahmoud_Abou_Hawis
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>MaxC;
        for(int i = 0 ; i < m ;i++)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            graph[a].push_back({{c,d},b});
            graph[b].push_back({{c,d},a});
        }
        cout<<binarySearch()<<'\n';
        clear();
    }
    return 0;
}