#pragma once

#include <iostream>
#include "Employee.h"
#include "Policy.h"

namespace Records {
	const int kMaxEmployees = 100;
	const int kFirstEmployeeNumber = 1000;
	const int kMaxPolicies = 1000;
	const int kFirstPolicyNumber = 0;
	const int kFirstClientNumber = 0;
	class Database
	{
	public:
		Database();
		~Database();
		Employee& addEmployee(std::string inFirstName, std::string inLastName);
		Employee& getEmployee(int inEmployeeNumber);
		Employee& getEmployee(std::string inFirstName, std::string inLastName);
		void displayAllEmployees();
		void displayCurrentEmployees();
		void displayFormerEmployees();
		
		Policy& addPolicy(std::string inStartingDate, std::string endingDate, float inCost, int inTypeId, int inEmployeeId);
		Policy& getPolicy(int inPolicyNumber);
		void displayAllPolicies();
		void displayPaidPolicies();
		void displayNotPaidPolicies();
		void displayExpiredPolicies();
		void displayNotExpiredPolicies();
	protected:
		Employee mEmployees[kMaxEmployees];
		int mNextEmployeeSlot;
		int mNextEmployeeNumber;

		Policy mPolicies[kMaxPolicies];
		int mNextPolicySlot;
		int mNextPolicyNumber;
		int mNextClientSlot;
		int mNextClientNumber;
	};
}