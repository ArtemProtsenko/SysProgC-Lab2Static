#pragma once

#include <iostream>

namespace Records {
	class Policy
	{
	public:
		Policy();
		void markAsPaid();
		void markAsExpired();
		void display();
		// Accessors and setters
		void setPolicyNumber(int inPolicyNumber);
		int getPolicyNumber();
		void setStartingDate(std::string inStartingDate);
		std::string getStartingDate();
		void setEndingDate(std::string endingDate);
		std::string getEndingDate();
		void setCost(float inCost);
		float getCost();
		void setPayout(float inPayout);
		float getPayout();
		void setPolicyTypeId(int inTypeId);
		int getPolicyTypeId();
		void setClientId(int inClientId);
		int getClientId();
		void setEmployeeId(int inEmployeeId);
		int getEmployeeId();
		bool getIsPaid();
		bool getIsExpired();
	private:
		int mPolicyNumber;
		std::string mStartingDate;
		std::string mEndingDate;
		float mCost;
		float mPayout;
		int mTypeId;
		bool fPaid;
		bool fExpired;
		int mClientId;
		int mEmployeeId;
	};
}