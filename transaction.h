/**
 * File: transaction.h
 * Author: Ethan Randolph
 * Email: randolphe@student.vvc.edu
 * Description: The interface for the class Transaction.
 */
#include<iostream>
#include<string>


/**
 * This class will createa a Transaction object that will store the day the transaction was performed, the amount that was involved with the transaction, and the description of the transaction.
 */
class Transaction
{
public:
	/**
	 * Constructs a Transaction object, initializing the member variables m_day, m_amount, and m_description.
	 */
	Transaction();
	/**
	 * Constructs a Transaction object, with user-defined values.
	 * @param day the day variable's value will become m_day's value.
	 * @param amount the amount variable's value will become m_amount's value.
	 * @param description the description variable's value will become m_description's value.
	 */
	Transaction(unsigned int day, double amount, std::string description);
	
	/**
	 * Reads in the user-defined values and sets the member variables to those values.
	 * @param day the day variable's value will become m_day's value.
	 * @param amount the amount variable's value will become m_amount's value.
	 * @param description the description variable's value will become m_description's value.
	 */ 
	void read(unsigned int day, double amount, std::string description);
	/**
	 * Prints the values of the member variables in a format used in the main program.
	 */
	void print() const;

	/**
	 * Prints the value of m_day.
	 * @return the value of m_day.
	 */
	unsigned int print_day() const;
	/**
	 * Prints the value of m_amount.
	 * @return the value of m_amount.
	 */
	double print_amount() const;

private:
	unsigned int m_day;
	double m_amount;
	std::string m_description;
};
