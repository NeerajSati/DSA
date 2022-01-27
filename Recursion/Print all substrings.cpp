//Print all substrings
#include <bits/stdc++.h>
using namespace std;

void printSubstr(string p,string s){
    if(s==""){
        cout<<p<<endl;
        return;
    }
    printSubstr(p+s[0], s.substr(1));
    printSubstr(p, s.substr(1));
        
}

int main()
{
    string s="abcd";
    printSubstr("",s);
    return 0;
}
