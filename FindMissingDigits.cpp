#include <iostream>
using namespace std;

int main()
{
    int n, cn, dig, i, arr[]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<"Enter the number to find the missing digits: ";
    cin>>n;
    cn= n;

    cout<<"\nThe missing digits are:\n";
    while(cn>0)
    {
        dig= cn%10;
        cn/=10;
        arr[dig]=-1;
    }
    for(i=0; i<=9; i++)
       if(arr[i]!=-1)
           cout<<i<<", ";
    cout<<endl<<endl;
}
