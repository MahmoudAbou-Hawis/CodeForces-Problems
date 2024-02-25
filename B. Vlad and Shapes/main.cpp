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
    cin >> t;
    while(t--)
    {
        int dimension;
        char array_element;
        cin >> dimension;
        int last_cnt_Ones = 0;
        bool printed = false;
        for(int i = 0 ; i < dimension ; i++)
        {
            int cnt_Ones = 0;
            for(int j = 0 ; j < dimension ; j++)
            {
                cin >> array_element;
                if(array_element == '1')
                {
                    cnt_Ones++;
                }
            }
            if(last_cnt_Ones != 0)
            {
                if(!printed)
                {
                    if(last_cnt_Ones == cnt_Ones)
                    {
                        cout << "SQUARE\n";
                    }
                    else
                    {
                        cout << "TRIANGLE\n";
                    }
                    printed = true;
                }
            }
            last_cnt_Ones = cnt_Ones;
        }
        cout << t << " \n";
    }
    return 0;
}


