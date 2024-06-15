#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define Created ios_base::sync_with_stdio(0);
#define By cin.tie(0);
#define Sofar cout.tie(0);
using namespace std;
using ll = unsigned long long;
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

ll n,m,k;
long long int x,y;

bool Valid(long long int x , long long int y)
{
    return !(x <= 0 || x > n || y <= 0 || y > m);
}


int main()
{
    Created By Sofar
    cin >> n >> m >> x >> y >> k;
    ll mx = (n * m);
    vector<pair<long long int,long long int>> p;
    ll result = 0;
    int dx,dy;
    for(int i = 0 ; i < k ; i++)
    {
        cin >> dx >> dy;
        p.push_back({dx,dy});
    }
    for(int i = 0 ; i < k ; i++)
    {
        long long int low   = 0;
        long long int high  = mx; 
        long long int res = 0;
        long long int add = 0;
        while(low <= high)
        {
            long long int mid = low + (high - low) / 2;
            if(Valid(x+(p[i].first * mid) ,y+(p[i].second * mid)))
            {
                res = mid;
                low = mid + 1;
                add = mid;
            }
            else
            {
                high = mid -1;
            }
        }
        result += res;
        x += (p[i].first * add);
        y += (p[i].second * add);
    }
    cout << result;
    return 0;  
}
