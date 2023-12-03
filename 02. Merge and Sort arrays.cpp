#include <iostream>
using namespace std;

int *mergesorted(int arr1[], int n1, int arr2[], int n2)
{
	int *merge= new int[n1+n2], i=0, j= n2-1, k=0;

	while(i<n1 || j>=0)
		merge[k++]= j<0 || (i<n1 && arr1[i] < arr2[j]) ? arr1[i++]: arr2[j--];
	
		/*
		if(cnt1<n1 && cnt2<n2)
		   if(arr1[cnt1] < arr2[n2-cnt2-1])
		  	  merge[i]= arr1[cnt1++];
		   else
		  	  merge[i]= arr2[n2- cnt2++ - 1];
		else if(cnt1>=n1)
			merge[i]= arr2[n2- cnt2++ - 1];
		else if(cnt2>=n2)
            merge[i]= arr1[cnt1++];
    */
	return merge;
}

int main()
{
	int i, arr1[100], n1, arr2[100], n2, *merge;

	cout<<"Enter the size of the first array: ";
	cin>>n1;
	cout<<"Enter the size of the second array: ";
	cin>>n2;

	cout<<"\nEnter "<<n1<<" elements for the first array in ASCENDING ORDER\n:";
	for(i=0; i<n1; i++)
	{
		cout<<"Enter element #"<<(i+1)<<": ";
        cin>>arr1[i];
	}
	cout<<"\nEnter "<<n2<<" elements for the second array in DESCENDING ORDER:\n";
	for(i=0; i<n2; i++)
	{
		cout<<"Enter element #"<<(i+1)<<": ";
        cin>>arr2[i];
	}

	merge = mergesorted(arr1, n1, arr2, n2);

	cout<<"\nFirst array elements:\n";
	for(i=0; i<n1; i++)
		cout<<arr1[i]<<", ";
	cout<<"\nSecond array elements:\n";
	for(i=0; i<n2; i++)
		cout<<arr2[i]<<", ";
	cout<<"\nMerge-sorted array:\n";
	for(i=0; i<n1+n2; i++)
	     cout<<merge[i]<<", ";
	
	return 1;
}