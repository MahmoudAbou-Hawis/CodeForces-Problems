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

int SumOfBIts(string str)
{
    int sum = 0 ;
    for(int i = 0 ; i < str.size() ; i++)
    {
        if(str[i] == '+')sum++;
        else sum--;
    }
    return sum;
}

int Check(string str,int number)
{
    int sum = 0;
    for(int i = 0 ; i < str.size();i++)
    {
        if((str[i] == '+' && (number &(1 << str.size()-1-i)) == 0 ) || (str[i] == '-' && (number &(1 << str.size()-1-i)) > 0 ))
        {
            return INT_MAX;
        }
        else
        {
            if((number &(1 << str.size()-1-i)) > 0)
            {
                sum++;
            }
            else
            {
                sum--;
            }
        }
    }
    return sum;
}

int main()
{
    Created By Sofar
    string a,b;
    cin >> a >> b;
    bool flag = false;
    int SumA = SumOfBIts(a);
    int cnt  = 0;
    for(int i = 0 ; i < b.size() ; i++)
    {
        if(b[i] == '?')
        {
            flag = true;
            cnt++;
        }
    }
    if(flag)
    {
        int result = 0;
        for(int i = 0 ; (i >> b.size() == 0) ;i++)
        {
            int y = Check(b,i);
            if(y == SumA)
            {
                result++;
            }
        }
        cout << fixed << setprecision(12) << (double)result / (2 << (cnt - 1)) << '\n';
    }
    else
    {
       int SumOfB = SumOfBIts(b);
       if(SumOfB == SumA)
       {
            cout << "1.000000000000";
       }
       else
       {
            cout << "0.000000000000";
       }
       return 0;
    }

    return 0;
}


