#include <iostream>
using namespace std;

struct Employee 
{
	string code, name, desgn;
	int days, pay;
};

void addrecords(Employee emp[], int &n)
{
	int i, nn;
	cout<<"\nEnter the no. of employees to add: ";
	cin>>nn;
	for(i= n; i<n+nn; i++)
	{
		cout<<"\nEnter details of employee #"<<(i-n+1)<<": ";
		cout<<"\nEnter name: "; 
		getchar(); getline(cin, emp[i].name); 
		cout<<"Enter code: ";
		getline(cin, emp[i].code);
		cout<<"Enter designation: ";
		getline(cin, emp[i].desgn);
		cout<<"Enter salary: Rs ";
		cin>>emp[i].pay;
		cout<<"Enter no. of days worked:";
		cin>>emp[i].days;
	}
	n+= nn;
}

void showrecords(Employee emp[], int n)
{
	cout<<"\nDetails of the employee given below:\n#\t\tNAME\t\t\t\tCODE\t\tDESIGNATION"<<
	               "\t\tSALARY\t\tNO. OF DAYS"<<endl;
	for(int i=0; i<n; i++)
	    cout<<(i+1)<<"\t\t"<<emp[i].name<<"\t\t"<<emp[i].code<<"\t\t"<<emp[i].desgn<<"\t\t"<<emp[i].pay<<"\t\t"<<
	             emp[i].days<<endl;
}

void findemployees(Employee emp[], int n)
{
	float avg= emp[0].pay;
	int i, maxPos=0, minPos=0;

	for(i=1; i<n; i++)
	{
		if(emp[i].pay > emp[maxPos].pay)
			maxPos= emp[i].pay;
		if(emp[i].pay < emp[minPos].pay)
			minPos= emp[i].pay;
		avg+= emp[i].pay;
	}
    cout<<"\nDetails of the highest paid employee given below:\nNAME\t\t\t\tsCODE\t\tDESIGNATION"<<
	               "\t\tSALARY\t\tNO. OF DAYS"<<endl;
	cout<<emp[maxPos].name<<"\t\t"<<emp[maxPos].code<<"\t\t"<<emp[maxPos].desgn<<"\t\t"<<emp[maxPos].pay<<"\t\t"<<
	             emp[maxPos].days<<endl;
	cout<<"\nDetails of the lowest paid employee given below:\nNAME\t\t\t\tCODE\t\tDESIGNATION"<<
	               "\t\tSALARY\t\tNO. OF DAYS"<<endl;
	cout<<emp[minPos].name<<"\t\t"<<emp[minPos].code<<"\t\t"<<emp[minPos].desgn<<"\t\t"<<emp[minPos].pay<<"\t\t"<<
	             emp[minPos].days<<endl;
	cout<<"\nAverage pay of all employees: "<<(avg/n)<<endl;
}

int main()
{
	Employee emp[10];
	int n=0, ch;

	do
	{
		cout<<"\nEMPLOYEE MENU OPTIONS:"<<
	         "\n01. Add Records"<<
	         "\n02. Show Records"<<
		     "\n03. Show details of highest, lowest and average paid employees"<<
	         "\n04. Exit program";
        cout<<"\nEnter your choice(1 - 4): ";
        cin>>ch;

     	switch(ch)
     	{
           case 1:
           addrecords(emp, n);
           break;

           case 2:
           showrecords(emp, n);
           break;

           case 3:
           findemployees(emp, n);
           break;

           case 4:
           cout<<"\nThe program ends here. Thank you for using it!\n";
           break;

           default:
           cout<<"\nInvalid choice entered! Please try again.\n";
           break;
        }
	} while(ch!=4);
	return 1;
}