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
    ll n,m,k,t;
    cin >> n >> m >> k >> t;
    vector<pair<ll,ll>> waste;
    vector<pair<ll,ll>> query;
    vector<pair<ll,ll>> queriesNotSorted;
    map<pair<ll,ll>,string>result;
    int a,b;
    for(int i = 0 ; i < k ; i++)
    {
        cin >> a >> b;
        waste.push_back({a,b});
    }
   for(int i = 0 ; i < t ; i++)
    {
        cin >> a >> b;
        query.push_back({a,b});
        queriesNotSorted.push_back({a,b});
    }
    int idx = 0;
    sort(all(waste));
    sort(all(query));
    int cnt = 0;
    for(int i = 0 ; i < t ;i++)
    {
        bool print = false;
        for(idx ; idx < k ;)
        {
            if(waste[idx].first == query[i].first && waste[idx].second == query[i].second)
            {
                result[{query[i].first,query[i].second}] = "Waste";
                print = true;
                idx++;
                cnt++;
                break;
            }
            if(waste[idx].first < query[i].first ||  (waste[idx].first == query[i].first && waste[idx].second < query[i].second))
            {
                cnt++;
                idx++;
            }
            else
            {
                break;
            }
        }
        if(!print)
        {
            
            int y = (((query[i].first -1) * m) + query[i].second-1);
            int type = (((((y%3)-cnt)%3)+3)%3);
            switch ((type))
            {
            case 0:
                result[{query[i].first,query[i].second}] = "Carrots";
                break;
            case 1:
                result[{query[i].first,query[i].second}] = "Kiwis";
                break;
            default:
                result[{query[i].first,query[i].second}] = "Grapes";
            break;
            }
        }
    }
    
    for(int i = 0 ; i < t ;i++)
    {
        cout << result[queriesNotSorted[i]] << '\n';
    }
    return 0;
}