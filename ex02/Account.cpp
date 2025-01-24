/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:10:34 by sadoming          #+#    #+#             */
/*   Updated: 2025/01/24 18:39:50 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*		 ## Init Vars ##		*/
int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
/*	## Init Vars END ##			*/

/*		 ## Init and Destroy classes ##		*/
Account::Account(void) {
	_accountIndex = _nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
/*	## Init and Destroy END ##	*/

/*		 ## GETTERS ##		*/
int		Account::getNbAccounts(void) {
	return _nbAccounts;
}
int		Account::getTotalAmount(void) {
	return _totalAmount;
}
int		Account::getNbDeposits(void) {
	return _totalNbDeposits;
}
int		Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}
/*	## GETTERS END ##	*/

/*		 ## ACTIONS ##		*/
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount(void) const {
	return _amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
/*	## ACTIONS END ##	*/

/*		 ## UTILITIES ##		*/
void	Account::_displayTimestamp(void) {
	time_t		now = time(0);
	tm			*ltm = localtime(&now);

	if (TIMESTAMP_PREVIOUS)
		std::cout << "[19920104_091532] ";
	else
	{
		std::cout << "[" << 1900 + ltm->tm_year;
		if (1 + ltm->tm_mon < 10)
			std::cout << "0";
		std::cout << 1 + ltm->tm_mon;
		if (ltm->tm_mday < 10)
			std::cout << "0";
		std::cout << ltm->tm_mday << "_";
		if (ltm->tm_hour < 10)
			std::cout << "0";
		std::cout << ltm->tm_hour;
		if (ltm->tm_min < 10)
			std::cout << "0";
		std::cout << ltm->tm_min;
		if (ltm->tm_sec < 10)
			std::cout << "0";
		std::cout << ltm->tm_sec << "] ";
	}
}
/*	## UTILITIES END ##	*/
