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
bool checker(string previous , string current)
{
    bool flag = false;
    int size = sz(current);
    int Psize = sz(previous);
    for(int i = 0 ; i < size ; i++)
    {
        if(previous[0] == current[i])
        {
            int idx = 0;
            for(int e = i ; e < i+Psize ; e++)
            {
               flag =((current[e]==previous[idx++])?true:false);
               if(!flag)break;
            }
        }
        if(flag)break;
    }
    return flag;
}
int main()
{
    Created By Sofar
    int n;
    cin>>n; 
    vector<string>v(n);
    for(int i = 0 ; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end()
    ,
    [&] (const string &first , const string &second)
    {
        return (sz(first) < sz(second));
    }
    );
    bool flag =true;
    for(int i = 1 ; i <  n  && flag; i++)
    {
        flag &=checker(v[i-1],v[i]);
    }
    if(flag)
    {
        cout<<"YES\n";
        for(auto &i : v)cout<<i<<'\n';
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}


