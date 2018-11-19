#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void add_random(int *T,int size);
void print(int *msg,int size);
int** Make_Table(int *R_array,int r,int *temp,int size);
void R_temp(int *R_array,int *temp, int x);
int R_Bits(int size);
int* sender(int *msg, int size, int r, int x);
int receiver(int *final_array, int x);

void add_random(int *T,int size)
{
	int bit,pos;
	srand(time(0));
	
		bit=(rand()%2);
		pos=(rand()%size);
		
		cout<<"Random number :"<<bit<<" ";
		cout<<"random position :"<<pos<<" "<<endl;
		
		T[pos]=bit;	
}

void print(int *msg,int size)
{
	cout<<"Message :";
	for(int i=0; i<size; i++)
		cout<<msg[i]<<" ";
		
	cout<<endl;
}

int** Make_Table(int *R_array,int r,int *temp,int size)
{
	int x=size+r;

	int **b=new int*[size+1];
	for(int i=0; i<size+1; i++)
	{
		b[i]=new int[r+1];
	}
	b[0][0]=0;
	for(int i=1; i<r+1; i++)
	{
		b[0][i]=R_array[i-1];
	}

	for(int i=1; i<size+1; i++)
	{
			b[i][0]=temp[i-1];
	}
	
	for(int i=1; i<size+1; i++)
	{
		for(int j=1; j<r+1; j++)
		{
			b[i][j]=0;
		}
	}
	
	int k=1;
	int sum=0;
	for(int i=1; i<=size; i++)
	{
		for(int j=r; j>0; j--)
		{
			if((sum+=b[0][j])<=b[i][0])
			{
				b[k][j]=1;
			}
			else
			{
				sum-=b[0][j];
			}
		}
		k++;
		sum=0;
	}
	cout<<"2-d array..."<<endl;
	for(int i=0; i<size+1; i++)
	{
		for(int j=0; j<r+1; j++)
		{
			cout<<setw(4)<<b[i][j];
		}
		cout<<endl;
	}
	return b;
}
void R_temp(int *R_array,int *temp, int x)
{
	int j=0,fill=0,put=0;
	for(int i=0; i<x; i++)
	{
		if(i==pow(2,j)-1)
		{
			R_array[fill++]=i+1;
			j++;
		}
		else
		{
			temp[put++]=i+1;
		}
	}
}

int R_Bits(int size)
{
	int r=0;
	while((size+r+1)>pow(2,r))
	{
		r++;
	}
	return r;
}

int* sender(int *msg, int size, int r, int x)
{
	int *temp=new int[size];
	int *R_array=new int[r];
	
	R_temp(R_array,temp,x);
	
	int k=2;
	int put=0;
	int *final_array=new int[x];
	final_array[0]=final_array[1]=0;
	for(int i=2; i<x; i++)
	{
		if(i==R_array[k]-1)
		{
			final_array[i]=0;
			k++;
		}
		else
		{
			final_array[i]=msg[put++];
		}
	}
	cout<<"Message without redundent bits."<<endl;
	print(final_array,x);
	
	int **b=Make_Table(R_array,r,temp,size);
	
	int sum=0;
	cout<<endl<<endl;
	for(int i=1; i<r+1; i++)
	{
		for(int j=1; j<size+1; j++)
		{
			if(b[j][i]==1)
			{
				sum+=final_array[b[j][0]-1];
			}
		}
		if(sum%2!=0)
		{
			final_array[b[0][i]-1]=1;
		}
		else
		{
			final_array[b[0][i]-1]=0;
		}
		sum=0;
	}
	cout<<"final ";
	print(final_array,x);
	
	return final_array;
}

int receiver(int *final_array, int x)
{
	int j=0,r=0,size=0;
	for(int i=0; i<x; i++)
	{
		if(i==pow(2,j)-1)
		{
			r++;
			j++;
		}
		else
		{
			size++;
		}
	}
	
	int *R_array=new int[r];
	int *temp=new int[size];
	
	R_temp(R_array,temp,x);
	
	int **b=Make_Table(R_array,r,temp,size);
	
	cout<<endl<<"check ";
	print(final_array,x);
	
	int sum=0;
	cout<<endl<<endl;
	int counter=0;
	cout<<"size+1 :"<<size+1<<" r+1 :"<<r+1<<endl;
	for(int i=1; i<r+1; i++)
	{
		for(int j=1; j<size+1; j++)
		{
			if(b[j][i]==1)
				sum+=final_array[b[j][0]-1];
		}
		cout<<i<<":"<<sum<<","<<counter;
		int p=sum%2;
		int index=b[0][i];
		int q=final_array[index-1];
		cout<<","<<p<<",index :"<<index<<","<<q;
		if(p!=q)
		{
			counter+=R_array[i-1];
		}
					cout<<","<<counter<<endl;
		sum=0;
	}
	return counter;
}
int main()
{
	int size;
	cout<<"Enter the size of msg :";
	cin>>size;     
	int *msg=new int[size];
	
	cout<<"Enter msg :";
	for(int i=0; i<size; i++)
		cin>>msg[i];
	
	print(msg,size);
	int r=R_Bits(size);
	
	int x=size+r;
	int *final_array=sender(msg,size,r,x);
	
	add_random(final_array,x);
	
	int counter=receiver(final_array,x);
		
	if(counter!=0)
	{
		cout<<"Message received is incorrect."<<endl;
		cout<<"Error bit is :"<<counter<<endl;
		
		cout<<"Incorrect ";
		print(final_array,x);
		if(final_array[counter-1]==0)
			final_array[counter-1]=1;
		else
			final_array[counter-1]=0;
		
		cout<<"Corrected ";
		print(final_array,x);
	}
	else
	{
		cout<<"Received message is correct."<<endl;
		print(final_array,x);
	}
	return 0;
}
