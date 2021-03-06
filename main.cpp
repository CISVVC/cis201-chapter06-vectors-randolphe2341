/**
 * File: main.cpp
 * Author: Ethan Randolph
 * Email: randolphe@student.vvc.edu
 * Description: This program will use the Transaction class and create user-defined transactions. Those transactions will be added to form the total balance (with interest applied), average daily balance (with interest applied), and the minimum daily balance. The transactions and the values mentioned in the previous sentence will be printed on-screen.
 */
#include <iostream>
#include "transaction.h"
#include <vector>
/**
 * This function will create a Transaction object and 
 * @return it will return the Transaction object with user-defined variables.
 */
Transaction creation()
{
	Transaction temporal;
	unsigned int temp_day;
	double temp_amount;
	std::string temp_description;

	std::cout << "Please enter the day number: ";
	std::cin >> temp_day;
	std::cout << "Please enter the amount of the transaction: ";
	std::cin >> temp_amount;
	std::cin.ignore();
	std::cout << "Please enter the description of the transaction: ";
	getline(std::cin, temp_description);
	temporal.read(temp_day, temp_amount, temp_description);
	return temporal;
}

/**
 * This function will prompt the user and read in 'y' or 'n'. If it is neither of those, the prompt will ask again.
 * @param message the message parameter is the question the prompt will ask.
 * @return it will return a boolean value, true of 'y', false for 'n'.
 */
bool prompt(std::string message)
{
	char answer;
	std::cout << message;
	std::cin >> answer;
	if (answer == 'y')
		return true;
	else if (answer == 'n')
		return false;
	else
	{
		std::cout << "Invalid answer; try again." << std::endl;
		return prompt(message);
	}
}
/**
 * This will create the daily balance of one day of the vector<Transaction> variable. 
 * @param transaction the transaction object is the vector of transaction objects that the daily balance will read from.
 * @param index the index variable is reference for the sake of for loops and will be altered if there are more than one transaction during a day.
 * @return daily_balance the daily_balance of one day.
 */
double daily_balance(const std::vector<Transaction> transaction, int& index)
{
	double daily_balance = transaction[index].print_amount();
	while (transaction[index].print_day() == transaction[index+1].print_day())
	{
		daily_balance += transaction[index+1].print_amount();
		index++;
	}
	return daily_balance;
}
/**
 * This function will calculate the average daily balance of the total balance provided.
 * @param total the total is the total balance.
 * @param days the number of days the total_balance is composed of.
 * @return the total balance divied by the number of days.
 */
double average_daily_balance (double total, int days)
{
	return total / days;
}
/**
 * This function will calculate which daily_balance is the lowest out of all of them
 * @param daily_balance the daily_balance vector contains all the daily balances neeeded for this operation.
 * @return minimum returns the minimum daily balance.
 */
double minimum_daily_balance(const std::vector<double> daily_balance)
{
	double minimum = daily_balance[0];
	for (int i = 0; i < daily_balance.size(); i++)
	{
		if (daily_balance[i] < minimum)
			minimum = daily_balance[i];
	}
	return minimum;
}

const int MONTH = 30;
/*
 * The main function will gather all the information (transactions, fee, minimum daily balance, average daily balance, and print out the information.
 * @return 0 It is the main function.
 */
int main()
{
	//All variables that will be used in this function.
	std::vector<Transaction> transactions;
	std::vector<double> db(MONTH);
	double interest = 0.0;
	bool cont = true;
	double total_balance = 0.0;
	
	//Will ask the user for a interest rate
	std::cout << "Please enter interest (in percentage form): ";
	std::cin >> interest;
	interest = interest / 100;

	//This loop will ask for all the transactions for the month.
	while (cont)
	{
		transactions.push_back(creation());
		cont = prompt("Do you wish to add another transaction?(y/n) ");
	}

	//This loop will combine the transactions of each day into the daily balance vector.
	for (int i = 0; i < transactions.size();i++)
		db[transactions[i].print_day()-1] = daily_balance(transactions, i);

	//This loop will calculate the total balance.
	for (int i = 0; i < db.size(); i++)
		total_balance += db[i];

	//The rest will print the values of the transactions and the total balance with interest, average daily balance with interest, and the minimum daily balance.
	std::cout << "\n-------------------------------------------------------" << std::endl;	
	std::cout << "Day\t\tAmount\t\tDescription" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	for (int i = 0; i < db.size(); i++)
	{
		for (int j = 0; j < transactions.size(); j++)
		{
			if (i == transactions[j].print_day()-1)
			{
				transactions[j].print();
				while (transactions[j].print_day() == transactions[j+1].print_day())
				{
				transactions[j+1].print();
				j++;
				}
				std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;		
			}
		}
	}
	
	total_balance += interest*total_balance;
	std::cout << "Total Balance with interest: " << total_balance << std::endl;	
	//If the average daily balance is positive, then it will add a plus sign to the value.
	if (average_daily_balance > 0)
		std::cout << "Average daily balance with interest: +" << average_daily_balance(total_balance, MONTH) << " each day for " << MONTH << " days." << std::endl;
	else
		std::cout << "Average daily balance with interest: " << average_daily_balance(total_balance, MONTH) << " each day for " << MONTH << " days." << std::endl;
		
	std::cout << "Minimum daily balance: " << minimum_daily_balance(db) << std::endl;
	
	return 0;
}
