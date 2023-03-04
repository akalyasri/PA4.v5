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


class exercisePlan {
public:
	// Default Constructor
	exercisePlan();


	// Parameterized Constructor
	exercisePlan(int steps, string name, string date);


	// Copy Constructor
	exercisePlan(exercisePlan& old);


	// Destructor 
	~exercisePlan();


	// Setters
	void setGoalSteps(int steps);
	void setPlanName(string plan);
	void setPlanDate(string date);


	// Getters
	int getGoalSteps();
	string getPlanName();
	string getPlanDate();


	// Edit Goal
	void editGoal(void);


	string toString(void);

private:

	int goalSteps;
	string planName;
	string planDate;

};


//nonmember overloaded stream extraction and insertion
fstream& operator >> (fstream& lhs, exercisePlan& rhs);
ostream& operator << (ostream& lhs, exercisePlan& rhs);
fstream& operator << (fstream& lhs, exercisePlan& rhs);

