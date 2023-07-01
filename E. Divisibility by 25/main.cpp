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
int calculate(string s,char Xpos , char Ypos )
{
    int result = 0;
    if(s.rfind(Ypos)==s.npos)
        return INT32_MAX;
    result += s.size()-s.rfind(Ypos)-1;
    s.erase(s.rfind(Ypos),1);
	if(s.rfind(Xpos)==s.npos)
	return INT32_MAX;
	result=result+s.length()-s.rfind(Xpos)-1;
	s.erase(s.rfind(Xpos),1);
	int sum=0;
	while(s[sum]=='0')
	sum++;
	return sum+result;
}
int main()
{
    Created By Sofar
    string a;
	cin>>a;
	int ans=min(calculate(a,'0','0'),min(calculate(a,'5','0'),min(calculate(a,'2','5'),calculate(a,'7','5'))));
	if(ans==INT32_MAX)
	cout<<-1<<endl;
	else
	cout<<ans<<'\n';
    return 0;
}


