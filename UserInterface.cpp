#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);
void doMakePolicy(Database& inDB);
void doPayout(Database& inDB);
void markAsExpired(Database& inDB);

int main(int argc, char** argv)
{
	Database DB;
	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			doHire(DB);
			break;
		case 2:
			doFire(DB);
			break;
		case 3:
			doPromote(DB);
			break;
		case 4:
			doDemote(DB);
			break;
		case 5:
			DB.displayAllEmployees();
			break;
		case 6:
			DB.displayCurrentEmployees();
			break;
		case 7:
			DB.displayFormerEmployees();
			break;

		case 8:
			doMakePolicy(DB);
			break;
		case 9:
			doPayout(DB);
			break;
		case 10:
			markAsExpired(DB);
			break;
		case 11:
			DB.displayAllPolicies();
			break;
		case 12:
			DB.displayPaidPolicies();
			break;
		case 13:
			DB.displayNotPaidPolicies();
			break;
		case 14:
			DB.displayExpiredPolicies();
			break;
		case 15:
			DB.displayNotExpiredPolicies();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command." << endl;
		}
	}
}
int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Employee and Policies Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) Demote an employee" << endl;
	cout << "5) List all employees" << endl;
	cout << "6) List all current employees" << endl;
	cout << "7) List all previous employees" << endl;
	cout << "8) Make a policy" << endl;
	cout << "9) Payout a policy" << endl;
	cout << "10) Mark as expired" << endl;
	cout << "11) List all policies" << endl;
	cout << "12) List all paid policies" << endl;
	cout << "13) List all not paid policies" << endl;
	cout << "14) List all expired policies" << endl;
	cout << "15) List all not expired policies" << endl;
	cout << "0) Quit" << endl;
	cout << endl;

	cout << "---> ";
	cin >> selection;
	return selection;
}
void doHire(Database& inDB)
{
	string firstName;
	string lastName;
	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;
	try {
		inDB.addEmployee(firstName, lastName);
	}
	catch (std::exception ex) {
		cerr << "Unable to add new employee!" << endl;
	}
}
void doFire(Database& inDB)
{
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;
	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << " has been terminated." << endl;
	}
	catch (std::exception ex) {
		cerr << "Unable to terminate employee!" << endl;
	}
}
void doPromote(Database& inDB)
{
	int employeeNumber;
	int raiseAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;
	try {

		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (...) {
		cerr << "Unable to promote employee!" << endl;
	}
}
void doDemote(Database& inDB)
{
	int employeeNumber;
	int demeritAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a demerit? ";
	cin >> demeritAmount;
	try {

		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.demote(demeritAmount);
	}
	catch (...) {
		cerr << "Unable to demote employee!" << endl;
	}
}
void doMakePolicy(Database& inDB)
{
	string inStartingDate;
	string inEndingDate;
	float inCost;
	int inTypeId;
	int inEmployeeNumber;
	cout << "Starting date? ";
	cin >> inStartingDate;
	cout << "Ending Date? ";
	cin >> inEndingDate;
	cout << "Cost? ";
	cin >> inCost;
	cout << "Policy type id? ";
	cin >> inTypeId;
	cout << "Employee number? ";
	cin >> inEmployeeNumber;
	try {
		inDB.addPolicy(inStartingDate, inEndingDate, inCost, inTypeId, inEmployeeNumber);
	}
	catch (std::exception ex) {
		cerr << "Unable to make policy!" << endl;
	}
}
void doPayout(Database& inDB)
{
	int policyNumber;
	float payout;
	cout << "Policy number? ";
	cin >> policyNumber;
	cout << "Payout amount? ";
	cin >> payout;
	try {

		Policy& pol = inDB.getPolicy(policyNumber);
		pol.setPayout(payout);
		pol.markAsPaid();
	}
	catch (...) {
		cerr << "Unable to payout!" << endl;
	}
}
void markAsExpired(Database& inDB)
{
	int policyNumber;
	float payout;
	cout << "Policy number? ";
	cin >> policyNumber;
	try {
		Policy& pol = inDB.getPolicy(policyNumber);
		if (pol.getIsExpired()){
			cout << "Already expired." << endl;
		}
		else{
			pol.markAsExpired();
		}
	}
	catch (...) {
		cerr << "Unable to do this!" << endl;
	}
}
