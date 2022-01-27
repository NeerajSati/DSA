//Q skip a substring cal in string
#include <bits/stdc++.h>
using namespace std;

string skipChar(string s){
    if(s=="")
        return "";
    if(s.find("cal") == 0)
        return skipChar(s.substr(3));
    else
    return s[0] + skipChar(s.substr(1));
        
}

int main()
{
    string s="bcaljoucalij";
    //expected= bjouij
    cout<<skipChar(s)<<endl;
    return 0;
}
