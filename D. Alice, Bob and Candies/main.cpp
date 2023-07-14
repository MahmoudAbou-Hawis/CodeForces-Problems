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
        cin >> n ;
        vector<int>v(n);
        int counter = 0;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> v[i];
        }
        int APrevious , BPrevious ;
        APrevious = BPrevious = 0;
        int SumA,SumB;
        SumA = SumB = 0;
        int st = -1 ; int end = n;
        int tempSum = 0;
        bool alice = 1;
        while(st < end)
        {
            if(alice)
            {
                if(st+1 == end)break;
                if(tempSum == 0) counter++;
                tempSum += v[++st];
                SumA += v[st];
                if(tempSum > BPrevious)
                {
                    APrevious = tempSum;
                    tempSum = 0;
                    alice = 0;
                }
            }
            else
            {
                if(end -1 == st) break;
                if(tempSum == 0) counter++;
                tempSum += v[--end];
                SumB += v[end];
                if(tempSum > APrevious)
                {
                    BPrevious = tempSum;
                    tempSum = 0;
                    alice = 1;
                }
            }
        } 

        cout << counter << " "<< SumA << " " <<SumB<<'\n';
    }


    return 0;
}