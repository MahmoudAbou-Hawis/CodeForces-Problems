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
    string str ;
    map<char,int>m;
    m['A'] = 0;
    m['B'] = 0;
    m['C'] = 0;
    vector<char>result(3,'k');
    for(int i = 0 ; i < 3 ; i++)
    {
        cin >> str;
        if(str[1] == '>')
        {
            m[str[0]]++;
        }
        else
        {
            m[str[2]]++;
        }
    }
    for(auto &i : m)
    {
        result[i.second-1] = i.first;
    }
    bool flag = true;
    for(auto &i : result)
    {
        if(i == 'k')
        {
            flag = false;
        }
    }
    if(flag)
    {
        for(auto &i : result)
        {
            cout << i;
        }
    }
    else 
    {
        cout << "Impossible";
    }
    return 0;
}


