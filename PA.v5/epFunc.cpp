#include "appHeader.hpp"


//////////////////////////////////////////////////////////////////	EXERCISE PLAN	///////////////////////////////////////////////////////

// Default constructor
exercisePlan::exercisePlan() {
	goalSteps = 0;
	planName.clear();
	planDate.clear();
}


// Parameterized constructor
exercisePlan::exercisePlan(int steps, string name, string date) {
	goalSteps = steps;
	planName = name;
	planDate = date;
}


// Copy constructor
exercisePlan::exercisePlan(exercisePlan& old) {
	goalSteps = old.getGoalSteps();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}


// Destructor 
exercisePlan::~exercisePlan() {}


// Setters
void exercisePlan::setGoalSteps(int steps) {
	if (steps < 0) {
		goalSteps = 0;
	}
	else {
		goalSteps = steps;
	}
}
void exercisePlan::setPlanName(string plan) {
	planName = plan;
}
void exercisePlan::setPlanDate(string date) {
	planDate = date;
}



// Getters
int exercisePlan::getGoalSteps() {
	return goalSteps;
}
string exercisePlan::getPlanName() {
	return planName;
}
string exercisePlan::getPlanDate() {
	return planDate;
}


// Edit goal
void exercisePlan::editGoal(void) {
	system("cls");
	int newGoal = 0;
	cout << "How many steps is your new goal?: ";
	cin >> newGoal;
	setGoalSteps(newGoal);
}



string exercisePlan::toString(void) {
	return "Exercise Plan: " + planName + " | Date: " + planDate + " | Goal: " + std::to_string(goalSteps) + " steps";
}



// Overloaded stream extraction operator
fstream& operator >> (fstream& lhs, exercisePlan& rhs) {
	string name;
	getline(lhs, name);

	string strSteps;
	getline(lhs, strSteps);
	int steps = stoi(strSteps);

	string date;
	getline(lhs, date);

	string newline;
	getline(lhs, newline);

	rhs.setPlanName(name);
	rhs.setGoalSteps(steps);
	rhs.setPlanDate(date);
	return lhs;
}


// Overloaded stream insertion operator
ostream& operator << (ostream& lhs, exercisePlan& rhs) {
	lhs << "Exercise Plan: " << rhs.getPlanName() << " | Date: " << rhs.getPlanDate() << " | Goal: " << rhs.getGoalSteps() << " steps";
	return lhs;
}


// Overloaded stream insertion operator
fstream& operator << (fstream& lhs, exercisePlan& rhs) {
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoalSteps() << endl;
	lhs << rhs.getPlanDate() << endl;
	lhs << "\n";

	return lhs;
}


