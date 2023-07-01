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
int main()
{
    Created By Tourists
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vi v(n);
        for(int i =  0 ; i < n ; i++)
        {
            cin>>v[i];
        }
        ll result = 0;
        for(int i = 0 ;i < n ;i++)
        {
            for(int e = i+1 ; e < n ;e++)
            {
                if(v[e] <= v[i])result++;
            }
        }
        cout<<result<<'\n';
    }
    return 0;
}


