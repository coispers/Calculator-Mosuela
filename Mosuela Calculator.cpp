	#include<iostream>
	#include<stdlib.h>
	#include<vector>
	#include<sstream>
	#include<math.h>
	using std::cout;
	using std::cin;
	using std::endl;
	int calculator();
	void show_history();
	void choice();
	int scientific();
	void schoice();
	std::vector<std::string>history;
	int main()
	{
		
		int x;
		cout<<"\t\t\t\tWhat do you want to do?\n\n";
		cout<<"\t\t\t\t[1] Standard calculator\n";
		cout<<"\t\t\t\t[2] Scientific Calculator\n";
		cout<<"\t\t\t\t[3] History\n";
		cout<<"\t\t\t\t[4] Exit\n\n\n\n";
		cout<<"\t\t\t\tChoice: ";
		cin>>x;
	
		switch(x)
		{
			case 1:
				calculator();
				break;
			case 2:
				scientific();
				break;
			case 3:
				show_history();
				break;
			case 4:
				cout<<"\n\n\nThank you for using my calculator!";
				exit(4);
				break;
		
			default:
				cout<<"Enter a correct choice";
				main();
		}
		
		
	}
	int calculator()
	{

	double x,y;
	float sum=0.0,dif=0.0,prod=1.0,quo=1.0;
	int i;
	char op, back;

		std::string calculations;
	do {
	
		
	system("CLS");
	cout<<"\t\t#CALCULATOR#"<<endl;
	cout<<endl<<endl;
	
	
	cout<<"Calculate 2 numbers: (example 1 + 1 or 2 * 2)\n";
	cin>>x>>op>>y;
	std::ostringstream calc_stream;

	switch (op){
	
	case'+':
	sum=x+y;
	calc_stream<<"The sum of "<<x<<" and "<<y<<" is "<<sum; 

	

	break;
	
	case'-':
	dif=x-y;
	calc_stream<<"The difference of "<<x<<" and "<<y<<" is "<<dif;
	
	break;
	
	case'*':
	prod=x*y;
	calc_stream<<"The product of "<<x<<" and "<<y<<" is "<<prod;
	
	break;
	
	case'/':
	if (y==0)
	calc_stream<<"Undefined";
	else
	quo=x/y;
	calc_stream<<"The quotient of "<<x<<" and "<<y<<" is "<<quo;
	break;
	
	default:
	cout<<"Invalid operator";
	break;
	
	}
	calculations = calc_stream.str();
	history.push_back(calculations);
	cout<<calculations;
	
	cout<<"\nContinue[Y/N]: ";
	cin>>back;
	cout<<endl<<endl;
	if (back!='Y'&&back!='y'&&back!='N'&&back!='n')
	{	
		cout<<"Please enter a correct choice"<<endl;
		choice();
	}
	else if (back=='N'||back=='n')
	{
	system("pause");
	system("CLS");
	main();
	
	}
	}
	while (back=='y'||back=='Y');
	cout<<"Thank you\n";
	system("pause");
	system("CLS");
	
	}
	
	
	
	
	
	void choice()
	{
	char c;
		do
		{	
		
		cout<<"Do you want to continue? [Y/y or N/n]"<<endl;
		cin>>c;
		
		if (c=='Y'||c=='y')
		calculator();
		else if (c=='N'||c=='n')
		{
		system("pause");
		system("cls");
		main();
	
	}
		else
		cout<<"Please enter a correct choice\n";
		choice();
	
		
	 }
	 while(c!='y'||c!='Y'||c!='N'||c!='n');
	 cout<<"Enter a correct choice";
	}
	
	
	
	void show_history()
	{
		char c;
		for (const auto& entry : history)
		cout<< entry <<"\n";
		cout<<"back to main menu? Y/y for yes N/n for no\n";
		cin>>c;
if (c=='Y'||c=='y')
{
	system("cls");
	main();
}

else if (c=='N'||c=='n')
{
	system("cls");
	cout<<"Thank you! for using my calculator\n";
}
else {

cout<<"Enter Y/y or N/n\n";
system("pause");
system("cls");
show_history();
}
}
int scientific()
{
	char q;
	int c;
	float a,b;
	float answer;
	std::string calculations;
	system("cls");
	cout<<"[1] for exponents\n";
	cout<<"[2] for sin\n";
	cout<<"[3] for cosin\n";
	cout<<"[4] for square root\n";
	cout<<"Choice: ";
	cin>>c;
	std::ostringstream calc_stream;
	switch(c)
	{
		case 1:
			{
				system("cls");
				cout<<"Enter the base number: ";
				cin>>a;
				cout<<"\nEnter the exponent: ";
				cin>>b;
				cout<<"\n\n";
				answer=pow(a,b);
				calc_stream<<"The power of "<<a<<" raise to "<<b<<" is "<<answer<<"\n";
				break;
			}
		case 2:
			{
				system("cls");
				cout<<"Enter the value of x in sin(x): ";
				cin>>a;
				cout<<"\n\n";
				answer=sin(a);
				calc_stream<<"The sine of "<<a<<" is "<<answer<<"\n";
				break;
			}
		case 3: 
		{
				system("cls");
				cout<<"Enter the value of x in cos(x): ";
				cin>>a;
				answer=cos(a);
				calc_stream<<"The cosine of "<<a<<" is "<<answer<<"\n";
				break;
		}
		case 4:
			{
				system("cls");
				cout<<"Enter the number insde the squre root: ";
				cin>>a;
				cout<<"\n\n";
				answer=sqrt(a);
				calc_stream<<"The square root of  "<<a<<" is "<<answer<<"\n";
				break;
			}
			
	}
	calculations = calc_stream.str();
	history.push_back(calculations);
	cout<<calculations;
	
schoice();
}

void schoice()
{
	char c;
	cout<<"Do you want to continue? Y/y for YES N/n for NO\n";
	cin>>c;
	
	switch (c)
	{
		case 'Y':
		case 'y':
		system("cls");
		scientific();
		break;
		case 'N':
		case 'n':
		system("cls");
		main();
		break;
		default:
		{
			cout<<"Please enter a correct choice!\n";
			system("pause");
			system("cls");
			schoice();
		}
	}
}


	
