#include<iostream.h>
#include<conio.h>
#define SIZE 7
class CQUEUE
{
	private:
		int cq[SIZE],f,r;
	public:
		CQUEUE()
		{
			f=r=-1; // initial condition
		}
		void insert(int);
		void disp();
		int del();
};

void CQUEUE:: insert(int e)
{
	if((f==0 && r==SIZE-1) || (r==f-1))
	{
		cout<<"\nCircular queue is overflown!";
	}
	else
	{
		if(r==-1)   // check if the element is the first element
		{
			f=r=0;  // f++;r++;
		}
		else if(r==SIZE-1)   // circular effect
		{
			r=0;
		}
		else
		{
			r++;
		}
		cq[r]=e;
	}



}
int CQUEUE :: del()
{
	int n=-999;

	if(f==-1)
	{
		return n;

	}
	else
	{
		n=cq[f];
		if(f==r)
		{
			f=r=-1;  // reset condition.
		}
		else if(f==(SIZE-1))  // circular effect
		{
			f=0;
		}
		else
		{
			f++;
		}






	}

	return n;

}



void CQUEUE :: disp()
{
	int i=0;
	if(f==-1 && r==-1)
	{
		cout<<"CQ is empty!";
		return;
	}

	if(f<=r)   // normal queue.
	{
		for(i=f;i<=r;i++)
		{
			cout<<cq[i]<<" ";
		}

	}
	else
	{
		for(i=f;i<SIZE;i++)
		{
			cout<<cq[i]<<" ";
		}
		for(i=0;i<=r;i++)
		{
			cout<<cq[i]<<" ";
		}
	}

}



void main()
{
	CQUEUE q1;
	int n,ch;
	clrscr();
	do
	{
		cout<<"\nEnter 1 to insert\n2 to delete\n3 to disp\n4 to exit\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the ele to be inserted:";
				cin>>n;
				q1.insert(n);
				break;
			case 2:
				n=q1.del();
				if(n==-999)
				{
					cout<<"\nQueue is underflown!";
				}
				else
				{
					cout<<"\nThe deleted ele="<<n;
				}
				break;
			case 3:
				cout<<"\nQueue contents\n";
				q1.disp();

		}
	}while(ch!=4);
	getch();
}
