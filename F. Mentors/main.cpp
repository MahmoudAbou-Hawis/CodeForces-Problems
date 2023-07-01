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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>v;
    int nm;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>nm;
        v.pb({nm,i});
    }

    map<int,int>freq;
    map<int,int>quarrel;
    int a,b;
    for(int i = 0;  i < m ; i++)
    {   
        cin>>a>>b;
        if(v[a-1].f > v[b-1].f)
        {
            quarrel[a-1]++;   
        }
           if(v[a-1].f < v[b-1].f)
        {
            quarrel[b-1]++;   
        }
    }
    sort(all(v));
    vector<int>result(n);
    for(int i = 0 ; i < n ; i++)
    {
        result[v[i].s] = i-(freq[v[i].f]+quarrel[v[i].s]);
        freq[v[i].f]++;
    }
    for(auto &i :result)
    {
        cout<<i<<' ';
    }
    return 0;
}


