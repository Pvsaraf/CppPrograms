#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float a,b;
	cout<<"\n Enter two numbers:";
	cin>>a>>b;
	cout<<" Product="<<fixed<<setprecision(1)<<a*b;
	return 0;
}
