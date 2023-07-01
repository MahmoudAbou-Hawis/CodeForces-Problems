#include <bits/stdc++.h>
using namespace std ; 
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long factorial(int n){
if(!n){
return 1 ;
}
return n * factorial(n-1);
}


int freq[26] = {0};
int main()
{

int t;
cin>>t;
while(t--)
{

int n ;
cin>>n;
string s;
cin>>s;
memset(freq,0,sizeof freq);

for(int i = 0 ; i < n ; i++)
freq[s[i]-'a']++;

bool sol = true;

long long int w = 0;
for(int i = 0 ; i < 26 ;i++){
if(freq[i]&1)
	sol = false;
else
w+=factorial(freq[i]/2);


}
if(!sol){
cout<<0<<'\n';
continue;
}

long d = factorial(n/2);

cout<< d /w <<'\n';

}

return 0;
}
