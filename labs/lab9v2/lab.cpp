

#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

int main()
{
	int *Iarr = (int*)malloc(100*sizeof(int));
	double *Darr = (double*)malloc(100*sizeof(double));
	char *Carr = (char*)malloc(100*sizeof(char));
	string Sarr[100];
	string aString;
	int Icount = 0, Dcount = 0, Ccount = 0,Scount = 0;
	//int Dcount = 0;
	//int Ccount = 0;
	//int Scount = 0;
	 // ch = Carr[1][0]
	while(true)
	{
		cout<<"\nEnter your input: ";
		cin >> aString;
		std::stringstream ss;
		ss << aString;
		int n;
		double d;
		char c;
		char *ep = NULL;
		const char *cstr = aString.c_str();
		d = strtod (cstr, &ep);
		if (!ep || *ep || aString.find('.') == std::string::npos) 
		{
		// cout<<"If"<<endl;
			ss>>n;
			//cout << n << "\nINTEGER\n";
			if(ss.fail()) 
			{
			// cout<<"Df"<<endl;
				ss>>c;
				//cout << c << "\nCHARACTER\n";
				//Carr[Ccount++] = c;
				
				
				if(ss.fail()) 
				{
				//cout<<"Cf"<<endl;
					Sarr[Scount++] = aString;
					cout << aString << "\nSTRING\n";
				}
				else
				{
									cout << "doesn't hit else";

					Carr[Ccount++] = c;
					cout << c << "\nCHARACTER\n";
				}
				
			}
			else
			{
				//prints integer
				Iarr[Icount++] = n;
			}
		}
		else
		{
			Darr[Dcount++] = d;
		}

		cout<<"\nString List: ";
		for(int i=0;i<Scount;i++)
			cout<<Sarr[i]<<" ";
		
		cout<<"\nInteger List : ";
		for(int i=0;i<Icount;i++)
			cout<<Iarr[i]<<" ";
		
		cout<<"\nDouble List: ";
		for(int i=0;i<Dcount;i++)
			cout<<Darr[i]<<" ";
		
		cout<<"\nCharacter List: ";
		for(int i=0;i<Ccount;i++)
			cout<<Carr[i]<<" ";


	}
}

