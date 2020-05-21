#include<iostream>
#include<iomanip>
using namespace std;
class time
{
	int h,m,s;
	public:
		gettime();
		printtime(); 
};

time::gettime()
{
	cout<<"\nEnter time:";
	cout<<"\nHours? ";
	cin>>h;
	cout<<"Minutes? ";
	cin>>m;
	cout<<"Seconds? ";
	cin>>s;
}

time::printtime()
{
	cout<<"The time is="<<setfill('0')<<setw(2)<<h<<":"<<setfill('0')<<setw(2)<<m<<":"<<setfill('0')<<setw(2)<<s;
	long int sum=h*3600+m*60+s;
	cout<<"\nTime in total seconds:"<<sum;
}

int main()
{
	time t;
	t.gettime();
	t.printtime();
	return 0;
}
