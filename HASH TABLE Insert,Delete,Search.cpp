#include<iostream>
using namespace std;
int size,*hashArray;
int hashIndex(int key){	//function returns hass index for a particular hash key
	return key%size;
}
void insert(){
	int data,index;
	cout<<"\nENter data to insert in Hash table ";cin>>data;
	index=hashIndex(data);	//hash index for the data 
	while(hashArray[index]!=0 && index<size){	//check if hashindex is already occupied
		index=(index+1)%size;	//if hash index is occupied then move till either we get empty index or array ends
	}
	if(index==size)	
		cout<<"\nHASH TABLE is Full !!! ";
	else	//if found empty index then insert data at that position
	{
		hashArray[index]=data;
		cout<<"\n"<<hashArray[index]<<" added to HASH TABLE ";
	}
}
void search(){
	int data,index;
	cout<<"\nEnter data to be searched Hash table ";cin>>data;
	index=hashIndex(data);	//index take hash value to find at what index data may be inserted.
	while(hashArray[index]!=data && index<size){	//from hash index it serach data untill last index
		index=(index+1)%size;	
	}
	if(index==size)
		cout<<"\nData is not presentin HASH TABLE";
	else
		cout<<"\n"<<hashArray[index]<<" is present at "<<index<<"th Index of Hash function.";
}
void delet() {
	int data,index;
	cout<<"\nENter data to deleted from Hash table ";cin>>data;
	index=hashIndex(data);	//index take hash value to find at what index data may be inserted.
	while(hashArray[index]!=data && index<size){ //from hash index it serach data untill last index
		index=(index+1)%size;
	}
	if(index==size)
		cout<<"\nData is not presentin HASH TABLE";
	else
	{
		cout<<"\n"<<hashArray[index]<<" deleted ";
		hashArray[index]=0;	//when data is found it is replaced by 0.
	}
}
void display(){
	int i;
	cout<<"\nHASH TABLE : \n";
	cout<<"\nIndex\tValue\n";
	for(i=0;i<size;i++)
		cout<<i<<"\t\t"<<hashArray[i]<<"\n";
}
int main(){
	int choice;
	cout<<"\nEnter size of array ";cin>>size;
	hashArray=new int(size);
	do{
	cout<<"\n~~~	MENU	~~~\n1-> Insert\t2-> Delete\t3-> Display\t4-> Searching\t5-> Exit\nEnter your choice  ";
		cin>>choice;
		switch(choice){
			case 1:insert();break;
			case 2:delet();break;
			case 3:display();break;
			case 4:search();break;
			default:cout<<"Incorrect Choice !!! Please Re-Enter correct choice\n";break;
		}
	}while(choice!=5);
	return 0;
}
