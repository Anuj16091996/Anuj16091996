#include <iostream>
#include<iomanip>

using namespace std;

string familyName[100], lastName[100];
int accountNumber[100];
double balance[100];
int options;
int index = 0;
int delCount = 0;
bool decide=true;
int accountLimit = 100;

void addAccount();
void deleteAccount(int accountToDelete);
void displayAccountDetails();
void deposit(int accNum);
void withdrawal(int accountNum);
void sortAndDisplay();
void displayEveryAccountDetails();
double averageBalanceValue();
double totalBalanceValue();




void addAccount() // enables the user to add an Account
{
 if(index<accountLimit)
	{
		cout << "What's your first name?" << endl;
		cin >> lastName[index];
		cout << "What's your family name?" << endl;
		cin >> familyName[index];
		cout << "Enter your 6 digit account number ranging from 100000-999999" << endl;
		cin >> accountNumber[index];
		

		while (accountNumber[index] < 100000 || accountNumber[index] > 999999)
		{
			cout << "You've entered an invalid input. Try Again!" << endl;
			cin >> accountNumber[index];
		}

		cout << "What's your initial balance?" << endl;
		cin >> balance[index];

		index++;
		cout << "Your Account has been created\n" << endl;
	}
 else
 {
	 cout << "Account limit has been exceeded!" << endl;
 }
}

void deleteAccount(int accountToDelete) // enables the user to delete an Account number using valid A/C number.
{
	bool cancel = true;

	cout << "We're sorry to see you go. Do you really want to continue with deleting this account? 1 for YES or 0 for NO" << endl;
	cin >> cancel;
	if (cancel == true)
	{
		for (int i = 0; i < index; i++)

		{

			if (accountNumber[i] == accountToDelete) //checking whether value is present
			{

				for (int j = i; j < index; j++)

				{
					accountNumber[j] = accountNumber[j + 1]; //re-writing the value
					familyName[j] = familyName[j + 1];
					lastName[j] = lastName[j + 1];
					balance[j] = balance[j + 1];

				}
				delCount++;

			}


		}

		if (delCount == 0)
		{
			cout << "The entered A/C Number doesn't exist in our records" << endl;
		}
		else
		{
			cout << "Your account has been deleted successfully\n" << endl;
		}
	}
	
}

void displayAccountDetails() // display Individual Account Details
{	
	int accNum;
	cout << "What is your Account Number?" << endl;
	cin >> accNum;
	int count = 0;

	for (int i = 0; i < index; i++)

	{

		if (accountNumber[i] == accNum)
		{
			cout << "Account Number is: " << accountNumber[i] << endl;
			cout << "Your Family Name is: " << familyName[i] << endl;
			cout << "Your Last Name is: " << lastName[i] << endl;
			cout << "Your balance is:$ " << balance[i] << endl;
			
			count++; 
		}
		
	}
	if (count == 0)
	{
		cout << "Try again! The entered account number doesn't match our records." << endl;
	}
}

void deposit(int accNumber) // allows user to deposit money on their account
{
	double money;
	int count = 0;
	
	for (int i = 0; i <index; i++)

	{

		if (accountNumber[i] == accNumber)
		{
			cout << "How much do you want to deposit?" << endl;
			cin >> money;

			cout << "Your old balance was:$ " << balance[i] << endl;
			balance[i] = balance[i] + money;
			cout << "Your new balance is:$\n" << balance[i];

			count++;
		}
		
	}
	if(count==0)
	{
		cout << "The entered A/C number doesn't match our records." << endl;
	}
	
}						

void withdrawal(int accountNum)
{
	double withdrawalAmount;
	int count = 0;

	for (int i = 0; i < index; i++)
	{

		if (accountNumber[i] == accountNum)
		{
			cout << "How much do you want to withdraw?" << endl;
			cin >> withdrawalAmount;
				if (withdrawalAmount > balance[i])
				{
					cout << "Sorry! You don't have sufficient balance to initiate this transaction.Try again" << endl;
					cin >> withdrawalAmount;
				}
			balance[i] = balance[i] - withdrawalAmount;
			cout << "Transcation Granted! Collect your cash!" << endl;
			cout << "Your new balance is: $" << balance[i]<<endl;

			count++;
		}
	}
	if (count == 0)
	{
		cout << "The entered A/C number doesn't match our records." << endl;
	}
}
						

void sortAndDisplay() 
{

	for (int i = 0; i < index; i++) {

		for (int j = i+1; j < index; j++) {

			if (balance[j] > balance[i]) {

				double tempbal = balance[j];
				balance[j] = balance[i];
				balance[i] = tempbal;

				string tempfam = familyName[j];
				familyName[j] = familyName[i];
				familyName[i] = tempfam;

				string templast = lastName[j];
				lastName[j] = lastName[i];
				lastName[i] = templast;

				int tempacc = accountNumber[j];
				accountNumber[j] = accountNumber[i];
				accountNumber[i] = tempacc;
			}
		}

	}

	displayEveryAccountDetails();

}

void displayEveryAccountDetails()
{
	if (delCount == 0)
	{
		for (int i = 0; i < index; i++)
		{
			cout << "Account Number is: " << accountNumber[i] << endl;
			cout << "Your Family Name is: " << familyName[i] << endl;
			cout << "Your Last Name is: " << lastName[i] << endl;
			cout << "Your balance is:$ " << balance[i] << endl << endl << endl;

		}
	}
	else
	{
		for (int i = 0; i < index-delCount; i++)
		{
			cout << "Account Number is: " << accountNumber[i] << endl;
			cout << "Your Family Name is: " << familyName[i] << endl;
			cout << "Your Last Name is: " << lastName[i] << endl;
			cout << "Your balance is:$ " << balance[i] << endl << endl << endl;

		}
	}
}

double averageBalanceValue()
{
	double average;
	average = totalBalanceValue() / index;

	return average;

}


double totalBalanceValue(){

	double sum=0;
	for (int i = 0; i < index; i++) 
	{

		sum = sum + balance[i];

	}
	
	return sum;
}





int main()
{
	do {

		cout << "------------------Welcome To The ABC Bank------------------\n" << endl;

		cout << "Select one of the options from the Menu:\n" << endl;

		cout << "1.Add a Bank Account" << endl;
		cout << "2.Remove Bank Account(By Account Number)" << endl;
		cout << "3.Display Account Details" << endl;
		cout << "4.Make a Deposit" << endl;
		cout << "5.Apply for a Withdrawal" << endl;
		cout << "6.Sort and Display Accounts" << endl;
		cout << "7.Average Balance Value of Accounts" << endl;
		cout << "8.Total Balance Value of Accounts\n" << endl;

		cout << "9.Exit" << endl;
		cin >> options;

		switch (options)
		{
		case 1:
		{
			addAccount();
			break;
		}
		case 2:
		{	
			int accountToDelete;
			cout << "What's the account number do you want to delete?" << endl;
			cin >> accountToDelete;
			deleteAccount(accountToDelete);
			break;
		}
		case 3:
		{	
			displayAccountDetails();
			break;
		}
		case 4:
		{	
			int accNumber;
			cout << "What's your account number?" << endl;
			cin >> accNumber;

			deposit(accNumber);

			break;
		}
		case 5:
		{	
			int accountNum;
			cout << "What's your A/C number?" << endl;
			cin >> accountNum;

			withdrawal(accountNum);

			break;
		}
		case 6:
		{	
			sortAndDisplay();
			break;
		}
		case 7:
		{
			double resultAverage = averageBalanceValue();
			cout << "Average balance value of all the accounts is: $" <<resultAverage<< endl;

			break;
		}
		case 8:
		{	
			double result=totalBalanceValue();
			cout << "The Networth of all the accounts is:$ " << result << endl;

			break;
		}
		case 9:
		{
			cout << "Thanks for choosing ABC Bank. Spend Less. Save More." << endl;
			return 0;
			break;
		}

		default: 
		{
			cout << "Please enter a valid input" << endl;
		}

		}
		cout << "Do you want to continue? 1 for Yes and 0 for No" << endl;
		cin >> decide;

	} while (decide);


	system("pause");
	return 0;
}
