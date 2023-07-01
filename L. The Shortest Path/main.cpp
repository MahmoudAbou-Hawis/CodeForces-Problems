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
const ll N = 1e4 +10;
vector<pair<int,pi>>Edges;
int n,m;
ll Bellman()
{
    vector<ll>cost(n , LOO);
    bool hasCycle = 0;
    for(int i = 0 ; i < n ;i++)cost[i]=0;
    for(int i = 1 ; i <= n ;i++)
    {
        bool isUpdated = 0;
        for(auto &edge :Edges)
        {
            if(cost[edge.s.s] > cost[edge.s.f] + edge.f)
            {
                cost[edge.s.s] =  cost[edge.s.f] + edge.f;
                isUpdated = 1;
            }
        }
        if(!isUpdated)
            break;
        else if(i==n)
            hasCycle =  1;

    }
    if(hasCycle) return -LOO;
    ll mn = LOO;
    for(int i = 0 ;i < n ; i++)
        mn = min(mn ,cost[i]);
    return mn;

}

int main(){
    Created By Tourists
    int t;
    cin>>t;
    while(t--) {
        Edges.clear();
        cin >> n >> m;
        ll mn = LOO;
        for (int i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            Edges.push_back({c, {--a, --b}});
            mn = min(mn,c);
        }
        ll Result = Bellman();
        if (Result == -LOO)
            cout << "-inf\n";
        else if(Result < 0)
            cout << Result << '\n';
        else
             cout<<mn<<'\n';
    }

    return 0;
}
