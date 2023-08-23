#include <iostream>

using namespace std;

int main()
{
    //Initiate a permanent loop with do...while
    cout<<"Choose from these operators: \n";
    cout<<"'+' for Addition"<<endl<<"'-' for Subtraction"<<endl;
    cout<<"'*' or 'x' for Multiplication"<<endl<<"'/' for Division"<<endl;
	do {
		cout<<"\nEnter first number: ";
        double num1;
        cin>>num1;
        cout<<"\nEnter operator: ";
        char op;
        cin>>op;
        cout<<"\nEnter second number: ";
        double num2;
        cin>>num2;
        cout<<endl;
        
        //Specify different code for different cases with switch
        
        switch (op) {
            case '+' : cout<<num1<<" + "<<num2<< " = "<<num1+num2<<endl;
            break;
            
            case '-': cout<<num1<<" - "<< num2<< " = "<< num1-num2<<endl;
            break;
            
            case 'x': 
            case '*':
                cout<<num1<<" x "<<num2<<" = "<< num1*num2<<endl;
            break;
            
            case '/': cout<<num1<<" / "<<num2<<" = "<< num1/num2<<endl;
            break;
            
            default: cout<<"Enter valid operator\n\n";
        }
    cout<<"\n";
	} while (1); //Executes permanently

    return 0;
}
