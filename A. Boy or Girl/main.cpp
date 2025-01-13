#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
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
 
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

char chrcmp(char a,char b)
{
    a = tolower(a);
    b = tolower(b);
    return ((a == b) ? 0 : ((a > b)?1:-1));
}
 
int main()
{
    setIO("");

    string str;
    cin >> str;
    map<char,bool> m;
    int result = str.size();
    for(int i = 0 ; i < str.length();i++)
    {
        if(m[str[i]]) result--;
        m[str[i]] = true;
    }
    cout << ((result&1)? "IGNORE HIM!": "CHAT WITH HER!");
    return 0;
}