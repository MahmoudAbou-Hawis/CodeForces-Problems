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
    int n;
    cin>>n;
    vector<int> qIl;
    vector<int> qIr;
    vector<vector<int>>lv(28);
    vector<vector<int>>rv(28);
    vector<int>freql(28,0);
    vector<int>freqr(28,0);
    string l;
    string r;
    int lIdx  = 0;
    int rIndx = 0;
    cin>>l>>r;
    for(int i = 0 ; i < n ; i++)
    {
        if(l[i]!='?')
        {
            freql[l[i]-'a']++;
            lv[l[i]-'a'].pb(i);
        }
        else
        {
            qIl.pb(i);
        }
        if(r[i] !='?'){
            freqr[r[i]-'a']++;
            rv[r[i]-'a'].pb(i);
        }
        else
        {
            qIr.pb(i);
        }
    }
    vector<pair<int,int>>pairs;
    for(int i = 0 ; i < 28 ; i++)
    {
        int le = freql[i];
        int re = freqr[i];
        int mn = min(le,re);
        for(int e = 0 ; e < mn ; e++)
        {
            pairs.push_back({lv[i][e],rv[i][e]});
        }
        while(le < re && lIdx < qIl.size())
        {
            pairs.push_back({qIl[lIdx] , rv[i][le]});
            lIdx++;
            le++;
        }
        while(re < le && rIndx < qIr.size())
        {
            pairs.pb({lv[i][re],qIr[rIndx]});
            rIndx++;
            re++;
        }
    }
    int t = min((qIl.size()-lIdx),(qIr.size()-rIndx));
    for(int i = 0 ; i < t ; i++)
    {
        pairs.pb({qIl[lIdx],qIr[rIndx]});
        lIdx++;
        rIndx++;
    }
    cout<<pairs.size()<<'\n';
    for(auto &idx :pairs)
    {
        cout<<idx.f+1 << " "<< idx.s+1<<'\n';
    }

    return 0;
}


