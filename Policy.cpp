#include <iostream>
#include <string>
#include "Policy.h"

using namespace std;

namespace Records {
	Policy::Policy()
	{
        mPolicyNumber = -1;
        mStartingDate = "00.00.0000";
        mEndingDate = "00.00.0000";
        mCost = 0;
        mPayout = 0;
        mTypeId = -1;
        fPaid = false;
        fExpired = false;
        mClientId = -1;
        mEmployeeId = -1;
	}

    void Policy::markAsPaid() {
        fPaid = true;
    }

    void Policy::markAsExpired() {
        fExpired = true;
    }

    void Policy::display()
    {
        std::cout << "Policy Number: " << mPolicyNumber << endl;
        std::cout << "Start Date: " << mStartingDate << endl;
        std::cout << "End Date: " << mEndingDate << endl;
        std::cout << "Cost: $" << mCost << endl;
        std::cout << "Payout Amount: $" << mPayout << endl;
        std::cout << "Policy Type Code: " << mTypeId << endl;
        std::cout << "Client Code: " << mClientId << endl;
        std::cout << "Employee Code: " << mEmployeeId << endl;
        std::cout << "Status: " << (fPaid ? "Paid" : "Not Paid") << ", " << (fExpired ? "Expired" : "Active") << endl;
        cout << endl;
    }

    void Policy::setPolicyNumber(int inPolicyNumber) {
        mPolicyNumber = inPolicyNumber;
    }
    int Policy::getPolicyNumber() {
        return mPolicyNumber;
    }

    void Policy::setStartingDate(string inStartingDate) {
        mStartingDate = inStartingDate;
    }
    std::string Policy::getStartingDate() {
        return mStartingDate;
    }

    void Policy::setEndingDate(string inEndDate) {
        mEndingDate = inEndDate;
    }
    std::string Policy::getEndingDate() {
        return mEndingDate;
    }

    void Policy::setCost(float inCost) {
        mCost = inCost;
    }
    float Policy::getCost() {
        return mCost;
    }

    void Policy::setPayout(float inPayout) {
        mPayout = inPayout;
    }
    float Policy::getPayout() {
        return mPayout;
    }

    void Policy::setPolicyTypeId(int inTypeId) {
        mTypeId = inTypeId;
    }
    int Policy::getPolicyTypeId() {
        return mTypeId;
    }

    void Policy::setClientId(int inClientId) {
        mClientId = inClientId;
    }
    int Policy::getClientId() {
        return mClientId;
    }

    void Policy::setEmployeeId(int inEmployeeId) {
        mEmployeeId = inEmployeeId;
    }
    int Policy::getEmployeeId() {
        return mEmployeeId;
    }

    bool Policy::getIsPaid() {
        return fPaid;
    }

    bool Policy::getIsExpired() {
        return fExpired;
    }

}