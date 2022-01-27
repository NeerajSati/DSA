//Q skip all c in string
#include <bits/stdc++.h>
using namespace std;

string skipChar(string s){
    if(s=="")
        return "";
    if(s[0]=='c')
        return skipChar(s.substr(1));
    
    return s[0] + skipChar(s.substr(1));
        
}

void skipCharVoid(string p, string s){
    if(s==""){
        cout<<p<<endl;
        return;
    }
    if(s[0]=='c'){
        skipCharVoid( p , s.substr(1));
    }
    else
    skipCharVoid( p + s[0] , s.substr(1));
}

int main()
{
    string s="abcdaccfc";
    //expected= abdaf
    cout<<skipChar(s)<<endl;
    skipCharVoid("",s);
    return 0;
}
