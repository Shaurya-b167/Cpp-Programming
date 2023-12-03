#include <iostream>
using namespace std;

static int oddCnt, evenCnt;
void reduce(int p, int q)
{
    if(p>q)
        p= p + q - (q = p);
    for(int i= p; i>=2; i--)
        if(oddCnt%i==0 && evenCnt%i==0)
        {
            p= p/i;
            q= q/i;
            i++;
        }
}

int main()
{
    oddCnt=0;
    evenCnt=0;
    int n, num;
    cout<<"Enter the no. of numbers to be entered: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter number #"<<i<<": ";
        cin>>num;
        if(num%2==0)
            evenCnt++;
        else
            oddCnt++;
    }
    if(oddCnt>evenCnt)
       n=1;
    reduce(oddCnt, evenCnt);
    if(n=1)
       cout<<"\nThe ratio of odd and even numbers= "<<oddCnt<<" : "<<evenCnt<<endl<<endl;
    else
       cout<<"\nThe ratio of odd and even numbers= "<<evenCnt<<" : "<<oddCnt<<endl<<endl;
}
