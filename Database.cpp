#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;

namespace Records {
	Database::Database()
	{
		mNextEmployeeSlot = 0;
		mNextEmployeeNumber = kFirstEmployeeNumber;

		mNextPolicySlot = 0;
		mNextPolicyNumber = kFirstPolicyNumber;
		mNextClientSlot = 0;
		mNextClientNumber = kFirstClientNumber;
	}
	Database::~Database()
	{
	}
	Employee& Database::addEmployee(string inFirstName, string inLastName)
	{
		if (mNextEmployeeSlot >= kMaxEmployees) {
			cerr << "There is no more room to add the new employee!" << endl;
			throw exception();

		}
		Employee& theEmployee = mEmployees[mNextEmployeeSlot++];
		theEmployee.setFirstName(inFirstName);
		theEmployee.setLastName(inLastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.hire();
		return theEmployee;
	}
	Employee& Database::getEmployee(int inEmployeeNumber)
	{
		for (int i = 0; i < mNextEmployeeSlot; i++) {
			if (mEmployees[i].getEmployeeNumber() == inEmployeeNumber) {
				return mEmployees[i];
			}
		}
		cerr << "No employee with employee number " << inEmployeeNumber << endl;
		throw exception();
	}
	Employee& Database::getEmployee(string inFirstName, string inLastName)
	{
		for (int i = 0; i < mNextEmployeeSlot; i++) {
			if (mEmployees[i].getFirstName() == inFirstName &&
				mEmployees[i].getLastName() == inLastName) {
				return mEmployees[i];
			}
		}
		cerr << "No match with name " << inFirstName << " " << inLastName << endl;
		throw exception();
	}
	void Database::displayAllEmployees()
	{
		for (int i = 0; i < mNextEmployeeSlot; i++) {
			mEmployees[i].display();
		}
	}
	void Database::displayCurrentEmployees()
	{
		for (int i = 0; i < mNextEmployeeSlot; i++) {
			if (mEmployees[i].getIsHired()) {
				mEmployees[i].display();
			}
		}
	}
	void Database::displayFormerEmployees()
	{

		for (int i = 0; i < mNextEmployeeSlot; i++) {
			if (!mEmployees[i].getIsHired()) {
				mEmployees[i].display();
			}
		}
	}

	Policy& Database::addPolicy(string inStartingDate, string endingDate, float inCost, int inTypeId, int inEmployeeId)
	{
		if (mNextPolicySlot >= kMaxPolicies) {
			cerr << "There is no more room to add the new policy!" << endl;
			throw exception();

		}
		Policy& thePolicy = mPolicies[mNextPolicySlot++];
		thePolicy.setPolicyNumber(mNextPolicyNumber++);
		thePolicy.setStartingDate(inStartingDate);
		thePolicy.setEndingDate(endingDate);
		thePolicy.setCost(inCost);
		thePolicy.setPayout(0);
		thePolicy.setPolicyTypeId(inTypeId);
		thePolicy.setClientId(mNextClientNumber++);
		thePolicy.setEmployeeId(inEmployeeId);
		return thePolicy;
	}
	Policy& Database::getPolicy(int inPolicyNumber)
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (mPolicies[i].getPolicyNumber() == inPolicyNumber) {
				return mPolicies[i];
			}
		}
		cerr << "No policy with policy number " << inPolicyNumber << endl;
		throw exception();
	}
	void Database::displayAllPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			mPolicies[i].display();
		}
	}
	void Database::displayPaidPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (mPolicies[i].getIsPaid()) {
				mPolicies[i].display();
			}
		}
	}
	void Database::displayNotPaidPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (!mPolicies[i].getIsPaid()) {
				mPolicies[i].display();
			}
		}
	}
	void Database::displayExpiredPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (mPolicies[i].getIsExpired()) {
				mPolicies[i].display();
			}
		}
	}
	void Database::displayNotExpiredPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (!mPolicies[i].getIsExpired()) {
				mPolicies[i].display();
			}
		}
	}
}