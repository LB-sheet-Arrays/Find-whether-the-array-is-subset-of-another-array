/*
Approach 1:
use 2 nested for loops to check if every element of a2[] is [resent in a1[]
TC => O(n^2)

Approach 2:
Sort a1[] and then search for every lement of a2[] in a1[] using binary search
TC => O(mlogm + nlogm)

*/

//ISSUE: 
//Make hashmap solution later
//Modify code to handle duplicates

#include<iostream>                       
#include<cstdlib>       //to dynamically allocate memory
#include<algorithm>     //to use sort()

using namespace std;

void PrintArray(int a[],int n)
{
	cout<<"\n";
	cout<<" { ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<" } ";
}

//returns 1 if found
int binarysearch(int a[],int m,int key)
{
	int l=0;
	int r=m-1;
	
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		
		//Base case
		if(a[mid]==key)
		{
			return 1;
		}
		else if(a[mid]<key)  //it must be present in right half
		{
			l=mid+1;
		}
		else if(a[mid]>key)  //it must be present in right half
		{
			r=mid-1;
		}
	}
}

void subset(int b[],int a[],int n,int m)
{

	int count=0;
	for(int i=0;i<n;i++)
	{
		count+=binarysearch(a,m,b[i]);
	}
	
	if(count==n)
	{
		cout<<"\nIts a subset!";
	}
	else
	{
		cout<<"\nIts NOT a subset!";
	}
}

int main()
{
	int *a,*b,m,n;
	
	cout<<"\nHow many elements do you want in the array no. 1? => ";
	cin>>m;
	
	cout<<"\nHow many elements do you want in the array no. 2? => ";
	cin>>n;
	
	//corner cases:
	if(n<0 || m<0)
	{
		cout<<"\nSize of an  array can't be negative!";
	}
	else if(n==0 || m==0)
	{
		return 0;
	}
	else if(n>m)
	{
		cout<<"\nSecond array is larger than first one! So, its not a subarray of first array";
	}
	else
	{
		cout<<"\nWe need to check if second array is subset of first one.\n";
		
		//allocating array 1 dynamically
		a=(int*)malloc(m*sizeof(int));
		
		cout<<"\nFeeding array 1";
		//feeding the array 
		for(int i=0;i<m;i++)
		{
			cout<<"\n\nElement no "<<i+1<<" ";
			cin>>a[i];
		}
		
		//allocating array 2 dynamically
		b=(int*)malloc(n*sizeof(int));
	
		cout<<"\nFeeding array 2";
		//feeding the array 
		for(int i=0;i<n;i++)
		{
			cout<<"\n\nElement no "<<i+1<<" ";
			cin>>b[i];
		}
		
		//sort larger(first) array first
		sort(a,a+m);
		
		//calling our function
		subset(b,a,n,m);
		
		
	}
	
return 0;	
}
