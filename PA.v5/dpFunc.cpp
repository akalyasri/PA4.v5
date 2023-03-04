#include "appHeader.hpp"


/////////////////////////////////////////////////////////////	DIET PLAN	////////////////////////////////////////////////////////////////////


// Defualt constructor
dietPlan::dietPlan() {
	goalCalories = 0;
	planName.clear();
	planDate.clear();
}


//  Destructor
dietPlan::~dietPlan() {}


// Parameterized constructor
dietPlan::dietPlan(int goal, string name, string date) {
	goalCalories = goal;
	planName = name;
	planDate = date;
}


// Copy constructor
dietPlan::dietPlan(dietPlan& old) {
	goalCalories = old.getGoalCalories();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}


// Setters
void dietPlan::setGoalCalories(int goal) {
	if (goal < 0) {
		goalCalories = 0;
	}
	else {
		goalCalories = goal;
	}
}

void dietPlan::setPlanName(string plan) {
	planName = plan;
}

void dietPlan::setPlanDate(string date) {
	planDate = date;
}


// Getters
int dietPlan::getGoalCalories() {
	return goalCalories;
}

string dietPlan::getPlanName() {
	return planName;
}

string dietPlan::getPlanDate() {
	return planDate;
}



// Edit Goal 
void dietPlan::editGoal(void) {
	system("cls");
	int newGoal = 0;
	cout << "How many calories is your new goal?: ";
	cin >> newGoal;
	setGoalCalories(newGoal);
}



// Utility function that returns concatenated string of the instance of the dietPlan.
string dietPlan::toString(void) {
	return "Diet Plan Name: " + planName + " | Date: " + planDate + "| Goal: " + std::to_string(goalCalories) + " calories";
}


// Overloaded stream extraction operator DP
fstream& operator >> (fstream& lhs, dietPlan& rhs) {
	string name;
	getline(lhs, name);

	string strCalories;
	getline(lhs, strCalories);
	int calories = stoi(strCalories);

	string date;
	getline(lhs, date);

	string newline;
	getline(lhs, newline);

	rhs.setPlanName(name);
	rhs.setGoalCalories(calories);
	rhs.setPlanDate(date);
	return lhs;

	///
	//
	//

}


// Overloaded stream insertion operator DP
ostream& operator << (ostream& lhs, dietPlan& rhs) {
	lhs << "Diet Plan: " << rhs.getPlanName() << " |Date: " << rhs.getPlanDate() << " | Goal: " << rhs.getGoalCalories() << " calories";
	return lhs;
}


// Overloaded stream insertion operator DP
fstream& operator << (fstream& lhs, dietPlan& rhs) {
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoalCalories() << endl;
	lhs << rhs.getPlanDate() << endl;
	lhs << "\n";
	return lhs;
}

