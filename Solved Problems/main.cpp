#include <bits/stdc++.h>

using namespace std;
vector<pair<long long,long long> >v;
vector<  vector<long long> >d(100000+9);
int main(){
long long n=0,k=0,dist=1;

cin>>n>>k;
for(int i=1;i<=n;i++){int x=0;cin>>x;d[x].push_back(i);}
if((int)d[0].size()>1){cout<<-1;return 0;}
n--;
while(n){
long long K=k-(dist>1);
if(!d[dist].size()){cout<<-1;return 0;}
if(d[dist].size()>d[dist-1].size()*K){cout<<-1;return 0;}

long long indx=0,next=d[dist].size();

for(int i=0;i<(int)d[dist-1].size();i++,next-=min(next,K))
    for(int j=0;j<min(next,K);j++)
        v.push_back(make_pair(d[dist-1][i],d[dist][indx++]));



n-=d[dist++].size();
}

cout<<v.size()<<"\n";
for(int i=0;i<(int)v.size();i++)cout<<v[i].first<<" "<<v[i].second<<"\n";

    return 0;
}
