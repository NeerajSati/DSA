//Get all substrings
#include <bits/stdc++.h>
using namespace std;

void getSubstr(string p,string s,vector<string> &v){
    if(s==""){
        v.push_back(p);
        return;
    }
    getSubstr(p+s[0], s.substr(1),v);
    getSubstr(p, s.substr(1),v);
    
}

int main()
{
    string s="abc";
    vector<string> v;
    getSubstr("",s,v);
    for(auto it:v){
        cout<<it<<endl;
    }
    return 0;
}
