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
        ll min01 = OO;
        ll min11 = OO;
        ll min10 = OO;
        ll result ;
        ll num ;
        string a;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> num >> a;
            if(a == "01")
            {
                min01 = min(min01,num);
            }
            else if(a == "11")
            {
                min11 = min(min11,num);               
            }
            else if(a == "10")
            {
                min10 = min(min10 ,num);
            }
        }
        result = min(min10+min01 , min11);
        if(result >= OO)
        {
            cout<<-1<<'\n';

        }
        else
        {
            cout<<result <<'\n';
        }
    }
    return 0;
}

