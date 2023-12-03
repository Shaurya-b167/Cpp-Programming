#include <iostream>
using namespace std;

class TeleBill
{
	private:
		string phno, name;
	    float amt;
		int n;

	public:
		TeleBill(string phone, string nam, int nn)
		{
             phno= phone;
             name= nam;
             n= nn;
             amt= 0;
		}

		void compute()
		{
			if(n<=100)
				amt= 500;
			else if(n<=200)
				amt= 500 + (n-100);
			else if(n<=300)
				amt= 500 + (1*100) + (n-200)*1.2;
			else
				amt= 500 + (1*100) + (100*1.2) + (n-300)*1.5;
		}

		void dispdata()
	    {
            cout<<phno<<"\t\t"<<name<<"\t\t"<<n<<"\t\t\t"<<amt<<endl;
		}
};

int main()
{
	string phone, name;
	int n;
	cout<<"To compute the telephone bills for the customers:"<<endl<<
	"\nEnter the details of the customer: "<<endl;
	cout<<"Enter the name: ";
	getline(cin, name);
	cout<<"Enter the phone number: ";
	getline(cin, phone);
	cout<<"Enter the no. of calls made: ";
	cin>>n;

	TeleBill obj (phone, name, n);
	obj.compute();
           
    cout<<endl<<"PHONE NUMBER\t\tNAME\t\t\tTOTAL CALLS\t\tAMOUNT"<<endl;
   	obj.dispdata();

    return 1;
}
