#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::fstream;
using std::ostream;
using std::getline;
using std::to_string;


class dietPlan {
public:
	//  Default Constructor
	dietPlan();


	//  Default Destructor
	~dietPlan();


	//  Parameterized Constructor 
	dietPlan(int goal, string name, string date);


	// Copy Constructor
	dietPlan(dietPlan& old);


	// Setters
	void setGoalCalories(int goal);
	void setPlanName(string plan);
	void setPlanDate(string date);


	// Getters
	int getGoalCalories();
	string getPlanName();
	string getPlanDate();


	// Edit Goal
	void editGoal(void);


	string toString(void);

private:

	int goalCalories;
	string planName;
	string planDate;

};

//nonmember overloaded stream extraction and insertion
fstream& operator >> (fstream& lhs, dietPlan& rhs);
ostream& operator << (ostream& lhs, dietPlan& rhs);
fstream& operator << (fstream& lhs, dietPlan& rhs);

