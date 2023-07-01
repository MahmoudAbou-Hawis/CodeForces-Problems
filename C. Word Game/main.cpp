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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>Result(3,0);
        vector<string>strings[3];
        map<string ,int>freq;
        string st;
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int e = 0 ;e <n ;e++)
            {
                cin>>st;
                strings[i].pb(st);
                freq[st]++;
            }
        }
        for(int i = 0 ; i < 3 ; i++)
        {
            for(auto &e : strings[i])
            {
                Result[i] += ((freq[e]==3)?0:((freq[e]==2)?1:3));
            }
        }
        for(auto &i : Result)
        {
            cout<<i<<" ";
        }
    cout<<'\n';
    }
  

    return 0;
}


