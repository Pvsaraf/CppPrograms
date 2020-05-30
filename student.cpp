#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
//Included all the header files required
#define MAX 100
//Macro definition i.e. maximum of 100 students


string filename;//Global variable

struct student
{
	char firstname[50],lastname[50],course[50];
	int section;

};     //created  a structure of student

student s;//Globally defined it

void add()
{
	FILE *fp;               //Declaration of a file pointer
	fp=fopen(filename.c_str(),"a");///Opening the file
	if(fp==NULL)
	{
		cout<<"Error in opening file\n";
		exit(0);
	}
	//Takes the input from user
	cout<<"Enter the first name of the student:\n";
	cin>>s.firstname;
	cout<<"Enter the last name of the student:\n";
	cin>>s.lastname;
	cout<<"Enter the course enrolled by the student:\n";
	cin>>s.course;
	cout<<"Enter the section of the student:\n";
	cin>>s.section;
	//Prints in the file 
	fprintf(fp,"%s %s %s %d\n",s.firstname,s.lastname,s.course,s.section);
	fclose(fp);//Close the file pointer
}

void show()
{
	//Reads the data and prints it
	FILE *fp;
	fp=fopen(filename.c_str(),"r");
	if(fp==NULL)
	{
		cout<<"Error in opening file\n";
		exit(0);
	}
	cout<<"\nFirst name\t Last name\t Course \t Section\n";
	while(fscanf(fp,"%s %s %s %d",s.firstname,s.lastname,s.course,&s.section)!=EOF)
	{
		cout<<s.firstname<<"\t\t"<<s.lastname<<"\t\t"<<s.course<<"\t\t"<<s.section;
		cout<<endl;
	}
}

void modify()
{
	int n,c=1,flag=0;
    cout<<"Enter the student number whose details you want to modify:\n";
	cin>>n;//reads the number
	FILE *fp1,*fp2;
	fp1=fopen(filename.c_str(),"r+"); //Open it in r+ mode
	if(fp1==NULL)
	{
		cout<<"Error in opening file\n";
		exit(0);
	}
	fp2=fopen("temp.txt","w+");       //Open in w+ mode so as to delete the initial content
	if(fp2==NULL)
	{
		cout<<"Error in opening file\n";
		exit(0);
	}
	//Instead of n th line copy all the other
	while(fscanf(fp1,"%s %s %s %d",s.firstname,s.lastname,s.course,&s.section)!=EOF)
	{
		if(c==n)
		{
			flag=1;
			break;
		}
		else
		   fprintf(fp2,"%s %s %s %d\n",s.firstname,s.lastname,s.course,s.section);
		c++;
	}
	if(flag==1)//got the desired line
	{
		cout<<"Enter the first name(Modified):";
		cin>>s.firstname;
		cout<<"Enter the last name(Modified):";
		cin>>s.lastname;
		cout<<"Enter the course enrolled(Modified):";
		cin>>s.course;
		cout<<"Enter the section (Modified):";
		cin>>s.section;
		fprintf(fp2,"%s %s %s %d",s.firstname,s.lastname,s.course,s.section);
	}//Copied the nth modified line to fp2
	fprintf(fp2,"\n");
	while(fscanf(fp1,"%s %s %s %d",s.firstname,s.lastname,s.course,&s.section)!=EOF)
	{
		   fprintf(fp2,"%s %s %s %d\n",s.firstname,s.lastname,s.course,s.section);
	}//copy the next lines after nth line to fp2
	fclose(fp1);
	fp1=fopen(filename.c_str(),"w");
	rewind(fp2);
	//Now copy it to fp1
	while(fscanf(fp2,"%s %s %s %d",s.firstname,s.lastname,s.course,&s.section)!=EOF)
	{
		   fprintf(fp1,"%s %s %s %d\n",s.firstname,s.lastname,s.course,s.section);
	}
	fclose(fp1);
	fclose(fp2);
}

void del()
{
    //deleted the file
		FILE *fp;
		fp=fopen(filename.c_str(),"w");
		if(fp==NULL)
		{
			cout<<"Error in opening file:";
			exit(0);
		}
		cout<<"File deleted:\n";
		fclose(fp);
}

int main()
{
	int opt,choice;
    cout<<"Enter the name of file name:\n";
    cin>>filename;
	FILE *fp;
	fp=fopen(filename.c_str(),"w");
	if(fp==NULL)
	{
			cout<<"Error in opening file:\n";
			exit(0);
	}
	fclose(fp);
	//Menu driven program
	do
	{
		cout<<"\n\t\t MENU\n\n";
		cout<<" 1.Add\n 2.List\n 3.Modify\n 4.Delete\n 5.Exit\n";
		cout<<"Enter your choice:\n";
		cin>>choice;
		switch(choice)
		{
			case 1:add();
			       break;
			case 2:show();
			       break;  
			case 3:modify();
			       break;
			case 4:del();
			       break;
			case 5:exit(0);
			       break;
			default:cout<<"Wrong choice.\n";                    
		}
		cout<<"Enter 1 to continue and 0 to exit:";
		cin>>opt;
	}while(opt==1); 	//Exit if option =0
	return 0;
}
