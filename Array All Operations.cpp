#include <iostream>
using namespace std;
int *arr,s;
void update(){
	int i,n;
	cout<<"\nEnter element to be updated in array : ";cin>>n;
	for(i=0;i<s;i++)
	{
		if(arr[i]==n)
		{
			cout<<"\nEnter New Value to update : ";cin>>arr[i];
			cout<<"\nUpdate Complete ";
			break;
		}
	}
	if(i==s)
		cout<<"\n"<<n<<" not found !!!";
}
void Delete(){
	int n,i;
	cout<<"\nEnter element to be deleted in array : ";cin>>n;
	for( i=0;i<s;i++)
	{
		if(arr[i]==n)
		{
			arr[i]=0;
			cout<<"\nElement deleted ";
			break;
		}
	}
	if(i==s)
		cout<<"\n"<<n<<" not found !!!";
}
void search(){
	int i,n;
	cout<<"\nEnter element to search in array : ";cin>>n;
	for(i=0;i<s;i++)
	{
		if(arr[i]==n)
		{
			cout<<"\n"<<arr[i]<<" Found at "<<i<<"th index. ";
			break;
		}
	}
	if(i==s)
		cout<<"\n"<<n<<" not found !!!";
}
void display(){
	cout<<"\nArray : ";
	for(int i=0;i<s;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main() {
	int ch;
	cout<<"\nEnter Array Size : ";cin>>s;
	arr=new int(s);
	cout<<"\nEnter Array Elements : ";
	for(int i=0;i<s;i++)
		cin>>arr[i];	
	do{
		cout<<"\n~~~\tMENU\t~~~\n1.Update\t2.Delete\t3.Search\t4.Display\t5.Exit\nEnter your choice";
		cin>>ch;
		switch(ch){
			case 1:update();break;
			case 2:Delete();break;
			case 3:search();break;
			case 4:display();break;
			case 5:cout<<"\n~~~ THANK YOU ~~~";break;
			defult:cout<<"\nInvalid Choice !!! Re-Enter Choice ";break;
		}
	}while(ch!=5);
	return 0;
}
