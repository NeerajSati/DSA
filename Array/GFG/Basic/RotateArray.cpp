#include<vector>
#include<iostream>
using namespace std;

int main() {

	int T,N,D,temp;
	vector<int> a;
	cin>>T;
	while(T>=1)
	{
	cin>>N>>D;
	for (int i=0; i<N; i++) 
	{
	cin>>temp;
	a.push_back(temp);
	}
	for(int j=D;j<N;j++)
	{
	    cout<<a[j]<<" ";
	}
	for(int j=0;j<D;j++)
	{
	    cout<<a[j]<<" ";
	}
	cout<<endl;
	
	a.clear();
	T--;
	}
	
	return 0;
	
}
