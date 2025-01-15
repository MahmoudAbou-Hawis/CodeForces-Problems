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
 
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

 
int main()
{
    setIO("");
    int n;
    cin >> n;
    vector<pair<int,int>> teams(n);
    for(auto &[home_uniform,guest_uniform] : teams)
    {
        cin >> home_uniform >> guest_uniform;
    }
    int result = 0;    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1;j < n ; j++)
        {
            auto &[host_home_uniform,host_guest_uniform] = teams[i];
            auto &[guest_home_uniform,guest_guest_uniform] = teams[j];
            if(host_home_uniform == guest_guest_uniform)result++;
            if(host_guest_uniform == guest_home_uniform) result++;
        }
    }
    cout <<  result;
    
    return 0;
}