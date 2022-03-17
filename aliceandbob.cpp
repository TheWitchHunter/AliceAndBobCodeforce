#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll t,x,y,n;
    cin>>t;
    for(ll j=0;j<t;j++){
        cin>>n;
        vector<ll>alice;
        vector<ll>bob;
        for(ll i=0;i<n;i++){
            cin>>x;
            if(x%2==0){
                alice.push_back(x);
            }
            else{
                bob.push_back(x);
            }
        }
        sort(alice.begin(),alice.end(),greater<int>());
        sort(bob.begin(),bob.end(),greater<int>());
        ll alicescore=0;
        ll bobscore=0;
        ll chance=1;
        vector<ll>::iterator it1=alice.begin();
        vector<ll>::iterator it2=bob.begin();
        while(it1!=alice.end() && it2!=bob.end()){
            if(chance%2!=0){
            if(*it1>*it2){
                alicescore+=*it1;
                it1++;
            }
            else{
                it2++;
            }
            }
            else if(chance%2==0){
                if(*it1<*it2){
                bobscore+=*it2;
                it2++;
            }
            else{
                it1++;
            }
            }
            chance++;
        }
        while(it1<alice.end()){
            if(chance%2!=0){
            alicescore+=*it1;
            }
            chance++;
            it1++;
        }
        while(it2<bob.end()){
            if(chance%2==0){
            bobscore+=*it2;
            }
            chance++;
            it2++;
        }
        if(alicescore>bobscore){
            cout<<"Alice"<<endl;
        }
        else if(alicescore<bobscore){
            cout<<"Bob"<<endl;
        }
        else{
            cout<<"Tie"<<endl;
        }
    }
    return 0;
}