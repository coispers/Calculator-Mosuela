#include<iostream>
using namespace std;
char back;
double num1, num2, ans;
char operation;
void add();
void subt();
void mult();
void div();
const int max_value=100;
struct array_history{
	double num1, num2, ans;
    char operation;
};
array_history history[max_value];
int history_count = 0;

void print_history()
{
	cout << "\nCalculation History:\n";
    for (int i = 0; i < history_count; i++) 
        cout << history[i].num1 << " " << history[i].operation << " " << history[i].num2 << " = " << history[i].ans<<" "<<(history + i) << endl;
    

}
int choice()
{
do
{	
	cout<<"\nDo you want to continue?[Y/N]\n";
	cin>>back;
	if (back=='Y'||back=='y')
	{
		return back;
	}
	else if(back=='N'||back=='n')
	{
		system("cls");
		cout<<"THANK YOU FOR USING THE CALCULATOR\n";
return back;
	}
	else
	cout<<"Please enter a correct choice";
}
while (back!='Y'||back!='y'||back!='N'||back!='n');
}
int main()
{
	
	do 
    {
        system("cls");
        cout<<"\t\t#CALCULATOR#\n\n\n";
        cout<<"Enter your equation please use [+ - * /] for your operators]\n\n";
             while (true){
        cin>>num1>>operation>>num2;
		if (cin.fail())
		{
			cout<<"PLEASE ENTER A NUMBER OR INTEGER!\n Enter a new equation: ";
			cin.clear();
			cin.ignore(100,'\n');	
				}
		else {
			break;
		}
		}
        history[history_count].num1 = num1;
		 history[history_count].num2 = num2;
		 history[history_count].operation = operation;
        switch(operation)
        {
            case '+':
            add();
            break;
            
            case '-':
			subt();
            break;
    
            case '*':
			mult();
            break;
            
            case '/':
			div();
            break;
            default:
            cout<<"INVALID OPERATOR PLEASE TRY AGAIN!";
            break;
        }
    history[history_count].ans = ans;
    history_count++;
    print_history();
	choice();
    }
    while (back=='y'||back=='Y');
return 0;
}

void add()
{
	ans=num1+num2;
	cout<<num1<<" + "<<num2<<" = "<<ans;
}
void subt()
{
	ans = num1 - num2;
    cout<<num1<<" - "<<num2<<" = "<<ans;
}
void mult()
{
	ans = num1 * num2;
    cout<<num1<<" * "<<num2<<" = "<<ans;
}
void div()
{
    if (num2==0&&num1!=0)
    {
    cout<<"UNDEFINED!";
	}
	else if (num1==0&&num2==0)
	{
	cout<<"INDETERMINATE";
	}
	else
	{
			
    ans = num1 / num2;
    cout<<num1<<"/"<<num2<<"="<<ans;
    }
}
