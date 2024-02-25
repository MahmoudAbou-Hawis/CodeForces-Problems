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

vector<unsigned int>dp(200001,0);

int sumOfDigits(int num)
{
    int sum = 0;
    while(num)
    {
        sum+=(num%10);
        num/=10;
    }
    return sum;
}

void preprocessing()
{
    dp[0] = 0;
    for(int i = 1; i < 200001 ; i++)
    {
        dp[i] = dp[i-1] + sumOfDigits(i);
    }
}

int main()
{
    Created By Sofar
    preprocessing();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}


