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
const int N = 10000 ;
int freq[N];
vector<int>sum;

int main()
{
    Code By Abou_Hawis
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        sum.resize(n+1);
        memset(freq,0,sizeof freq);
        int element;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> element;
            freq[element]++;
            sum[i+1] = sum[i] + element;
        }
        int cnt = 0;
        for(int i = 0 ; i <= n ;i++)
        {
            for(int j = i+2 ; j <= n ;j++)
            {
                if(sum[j] - sum[i] <= 8000 && freq[sum[j] - sum[i]])
                {
                    cnt += freq[sum[j] - sum[i]];
                    freq[sum[j] - sum[i]] = 0;
                }
            }
        }

        cout << cnt << '\n';

    }
    

    return 0;
}