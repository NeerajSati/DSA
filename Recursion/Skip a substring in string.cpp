//Q skip a substring cal in string
#include <bits/stdc++.h>
using namespace std;

string skipString(string s){
    if(s=="")
        return "";
    if(s.find("cal") == 0)
        return skipString(s.substr(3));
    else
    return s[0] + skipString(s.substr(1));
        
}

int main()
{
    string s="bcaljoucalij";
    //expected= bjouij
    cout<<skipString(s)<<endl;
    return 0;
}
