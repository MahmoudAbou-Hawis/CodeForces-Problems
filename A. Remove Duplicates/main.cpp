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
    vi v(n);
    for(auto &i:v)
    {
        cin>>i;
    }
    vector<bool> freq(1002,0);
    vi result;
    for(int i  = n-1 ; i >=0;i--)
    {
        if(!freq[v[i]])
        {
            result.pb(v[i]);
            freq[v[i]] = 1;
        }
    }
    reverse(result.begin(),result.end());
    cout<<result.size()<<'\n';
    for(auto &i:result)
    {
        cout<<i << " " ;
    }
    return 0;
}


