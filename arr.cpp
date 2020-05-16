#include<iostream>
using namespace std;
int main()
{
    int n,i;
	cout<<"Enter the number of elements:\n";
	cin>>n;
	int a[n];
	int *p;
	p=a;
	cout<<"Enter elements:";
	for( i=0;i<n;i++)
	{
		cin>>*(p+i);
	}
	cout<<"You entered:";
	for(i=0;i<n;i++)
	   cout<<*(p+i)<<"\n";
	return 0;
}
