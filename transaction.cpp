/**
 * File: transaction.cpp
 * Author: Ethan Randolph
 * Email: randolphe@student.vvc.edu
 * Description: The implementation of the interface in the header file transaction.h
 */
#include <iostream>
#include "transaction.h"
#include <string>

/**
 * Constructs a Transaction object, initializing the member variables m_day, m_amount, and m_description.
 */
Transaction::Transaction()
{
	m_day = 1;
	m_amount = 1000.0;
	m_description = "default";
}

/**
 * Constructs a Transaction object, with user-defined values.
 * @param day the day variable's value will become m_day's value.
 * @param amount the amount variable's value will become m_amount's value.
 * @param description the description variable's value will become m_description's value.
 */
Transaction::Transaction(unsigned int day, double amount, std::string description)
{
	m_day = day;
	m_amount = amount;
	m_description = description;
}

/**
 * Reads in the user-defined values and sets the member variables to those values.
 * @param day the day variable's value will become m_day's value.
 * @param amount the amount variable's value will become m_amount's value.
 * @param description the description variable's value will become m_description's value.
 */ 
void Transaction::read(unsigned int day, double amount, std::string description)
{
	m_day = day;
	m_amount = amount;
	m_description = description;
}

/**
 * Prints the values of the member variables in a format used in the main program.
 */
void Transaction::print() const
{
	std::cout << m_day << "\t\t" << m_amount << "\t\t" << m_description << std::endl;
}

/**
 * Prints the value of m_day.
 * @return the value of m_day.
 */
unsigned int Transaction::print_day() const
{
	return m_day;
}
	
/**
 * Prints the value of m_amount.
 * @return the value of m_amount.
 */
double Transaction::print_amount() const
{
	return m_amount;
}
