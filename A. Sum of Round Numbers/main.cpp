#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
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
const long long int MOD=1e9 + 7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 9 ;


int main()
{
    Code By Abou_Hawis
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int tenP = 1;
        vector<int>result;
        while(n)
        {
            int temp = n %10;
            if(temp != 0)
            {
                result.pb(temp * tenP);
            }
            tenP *= 10;
            n /= 10;
        }
        cout << sz(result) << '\n';
        for(auto &i : result)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
       

    return 0;
}