#include<iostream>
using namespace std;
int main()
{
	int age;
	cout<<"\n Enter your age:";
	cin>>age;
	(age>=18)?cout<<"You are eligible for voting":cout<<"You are not eligible for voting";
	return 0;
}
