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

int main() {
    setIO();
    int n ,m;
    cin >> n >> m;
    vector<pair<int,int> >arr(m);
    for(int i = 0 ; i <  m ; i++)
    {
        int fi,se;
        cin >> fi >> se;
        arr[i].first = se ;
        arr[i].second = fi;
    }
    sort(all(arr));
    long long int result = 0;
    for(int i = m -1 ; i >= 0 && n > 0 ; i--)
    {
        result += min(arr[i].second , n)  * arr[i].first;
        n -= arr[i].second; 
    }
    cout << result ;
    return 0;
}