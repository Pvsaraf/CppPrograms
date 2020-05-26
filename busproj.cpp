#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
using namespace std;
// included all the necessary header files
#define MAX 50
//Considered maximum of 50 seats in a bus
#define MAXB 30
//Considered maximum number of buses is 30 
static int c=0;
//Generated a count variable to know how many buses have been installed
class b
{
	string busno,drivername,from,to,arrtime,deprtime;
	char status[MAX][11],passname[MAX][35];
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void availseats();
		void avail();
		//void position();
}bus[MAXB];
//Created a class of buses and its information

void b::install()
{
	 //Entered the information of the bus
     cout<<"From:\n";
     cin>>bus[c].from;
     cout<<"To:\n";
     cin>>bus[c].to;
     cout<<"Enter the departure time from source(hh:mm)(in 24 hours system):\n";
     cin>>bus[c].deprtime;
     cout<<"Enter the arrival time at destination(hh:mm)(in 24 hours system):\n";
     cin>>bus[c].arrtime;
     
     cout<<"Enter the bus number:";
	 cin>>bus[c].busno;
     cout<<"Enter the driver's name:";
     cin>>bus[c].drivername;
     bus[c].empty();
     c++;//Incremented the count variable
} 


void b::empty()
{
	for(int i=0;i<MAX;i++)
	{
		strcpy(status[i],"Empty");       //Initialized the status of each seat to be empty
	
	}
	
}

void b::allotment()
{
	char n[MAX];
	int req,sno,opt,flag=0;
	cout<<"Enter the bus number:\n";
	cin>>n;
	for(int i=0;i<c;i++)
	{
		flag=0;
		if(strcmp(bus[i].busno.c_str(),n)==0)              //Comparing busno of each bus element with the entered bus no
		{
			req=i;
			flag=1;      //To notice that any bus found with the given bus no.
			break;
		}
		     
	}
	if(flag==0)
	{
		cout<<"The bus number you have entered is wrong\n";
		return;
	}         
    do
	{
		bus[req].availseats();     //Shows us the seat number of available seats
	    cout<<"Enter the seat number:\n";
     	cin>>sno;
     	if(sno>MAX)
     	{
     		cout<<"A bus does not contain more than "<<MAX<<"seats\n";          //Seat no is more than max seats
     		break;
		}
	if(strcmp(bus[req].status[sno-1],"Empty")==0)             //If the seat is available for reservation
	{
		cout<<"Enter the passenger's name:\n";              
		cin>>bus[req].passname[sno-1];
		strcpy(bus[req].status[sno-1],"Occupied");
		break;
	}
	else
	{
	  cout<<"This seat is already reserved:\nPlease enter 1 to search for another seat number or 0 to exit:";
	  cin>>opt;
	}
   }while(opt==1); 

}

void b::availseats()
{
	cout<<"The empty seat numbers are:\n";
	for(int i=0;i<MAX;i++)
	{
		if(strcmp(status[i],"Empty")==0)
		     cout<<i+1<<" ";                           //Prints the available seat nos
	}
	cout<<endl;
}

void b::show()
{
	int i,flag=0;
	string n;
	//Prints the details of the bus
	cout<<"\n Enter the bus number:";
	cin>>n;
	for(i=0;i<c;i++)
	{
		if(strcmp(bus[i].busno.c_str(),n.c_str())==0)
		         {
		         	flag=1;
		         	break;
				 }
    }
    if(flag==0)
    {
    	cout<<"The bus number you entered is wrong\n";
    	return;
	}
    
		cout<<"Bus number:"<<bus[i].busno<<endl;
		cout<<"From:"<<bus[i].from<<endl;
		cout<<"To:"<<bus[i].to<<endl;
		cout<<"Departure time from source:"<<bus[i].deprtime<<endl;
		cout<<"Arrival time to destination:"<<bus[i].arrtime<<endl;
		
		cout<<"Driver name:"<<bus[i].drivername<<endl;
		cout<<"\nSeat No.\tReservation status\tPassenger name\n\n";
		//Shows the information about each seat
		for(int j=0;j<MAX;j++)
		{
			cout<<j+1<<".\t\t"<<bus[i].status[j];
			if(strcmp(bus[i].status[j],"Occupied")==0)
			          cout<<"\t\t"<<bus[i].passname[j];     //Prints passenger name if seat is already booked 
			else
			          cout<<"\t\t--";                       //Otherwise prints --
			cout<<"\n";
		}
}

void b::avail()
{
	string f,t;
	cout<<"From:";         //Entered the source position
	cin>>f;
	cout<<"To:";           //Entered the destination position  
	cin>>t;
	for(int i=0;i<c;i++)
	{
		
		if(strcmp(bus[i].from.c_str(),f.c_str())==0)                     //compares from with f
		{   
			if(strcmp(bus[i].to.c_str(),t.c_str())==0)                     //compares to with t
			{      
			        cout<<endl;
			         //Prints the bus information if such a bus is found 
				    cout<<"Bus number:"<<bus[i].busno<<endl;
	            	cout<<"From:"<<bus[i].from<<endl;
		            cout<<"To:"<<bus[i].to<<endl;
	            	cout<<"Arrival time:"<<bus[i].arrtime<<endl;
            		cout<<"Departure time:"<<bus[i].deprtime<<endl;
            		cout<<"Driver name:"<<bus[i].drivername<<endl;   		
			}
		}
		
	}
}

int main()
{
	int opt,choice;
	b B;
	//Menu driven program
	do
	{
		cout<<"\n\t\t MENU\n\n";
		cout<<" 1.Install\n 2.Reservation\n 3.Show\n 4.Buses available\n 5.Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:B.install();
			       break;
			case 2:B.allotment();
			       break;  
			case 3:B.show();
			       break;
			case 4:B.avail();
			       break;
			case 5:exit(0);
			       break;
			default:cout<<"Wrong choice.\n";                    
		}
		cout<<"Enter 1 to continue and 0 to exit:";
		cin>>opt;
	}while(opt==1);
	return 0;
}

