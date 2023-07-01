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
        vi v(n);
        vector<int>freq(10,0);
        for(int i = 0 ; i < n ; i++)
        {
            cin>>v[i];
            freq[v[i]%10]++;
        }
        bool flag = true;
        for(int i  = 0 ; i <10 && flag ; i++)
        {
            if(freq[i])
            {
                freq[i]--;
                for(int e = 0 ; e < 10 && flag ;e++)
                {
                    if(freq[e])
                    {
                        freq[e]--;
                        int number  = (i + e)%10; 
                        if(number > 3)
                        {
                            if(freq[13-number])
                            {
                                flag = false;
                            }
                        }
                        else
                        {
                            if(freq[3-number])
                            {
                                flag = false;
                            }
                        }
                        freq[e]++;
                    }
                }

                freq[i]++;
            }
        }
        cout<<(!(flag)?"YES\n":"NO\n");

    }


    return 0;
}


