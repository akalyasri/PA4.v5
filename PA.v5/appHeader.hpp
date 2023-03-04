#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#pragma once

#include "dpHeader.hpp"
#include "epHeader1.hpp"


using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::fstream;
using std::ostream;
using std::getline;
using std::to_string;
using std::list;



class FitnessAppWrapper {
public:


	// Default Constructor.
	FitnessAppWrapper();


	// Destructor.
	~FitnessAppWrapper();


	// Run App
	void runApp(void);


	// Get int from user
	int getInt(void);


	// Load Daily Plan
	void loadDailyPlan(fstream& fileStream, dietPlan& plan);


	// Load Daily Plan - overloaded
	void loadDailyPlan(fstream& fs, exercisePlan& plan);


	// Load Daily Plan - overloaded for list
	void loadDailyPlan(fstream& fs, dietPlan* plan);


	// Load Weekly Plan
	void loadWeeklyPlan(fstream& fileStream, dietPlan weeklyPlan[]);


	// Load Weekly Plan - overloaded for list
	void loadWeeklyPlan(fstream& fileStream, list <dietPlan>* dpHead);


	// Load Weekly Plan - overloaded
	void loadWeeklyPlan(fstream& fileStream, exercisePlan weeklyPlan[]);


	// Display Daily Plan
	void displayDailyPlan(dietPlan& plan);


	// Display Daily Plan - overloaded for list
	void displayDailyPlan(dietPlan* plan);


	// Display Daily Plan - overloaded
	void displayDailyPlan(exercisePlan& plan);


	// Display Weekly Plan
	void displayWeeklyPlan(dietPlan weeklyPlan[]);


	// Display Weekly Plan - overloaded
	void displayWeeklyPlan(exercisePlan weeklyPlan[]);


	// Write Daily Plan To File
	void storeDailyPlan(fstream& outfile, dietPlan& plan);


	// Write Daily Plan To File - overloaded
	void storeDailyPlan(fstream& outfile, exercisePlan& plan);


	// Write Weekly Plan To File
	void storeWeeklyPlan(fstream& outfile, dietPlan weeklyPlan[]);


	// Write Weekly Plan To File - overloaded
	void storeWeeklyPlan(fstream& outfile, exercisePlan weeklyPlan[]);


	// Write Weekly Plan To File - overloaded for list
	void storeWeeklyPlan(fstream& outfile, list <exercisePlan>* ephead);


	// returns user choice of plan they want to edit.
	int chooseDailyPlanFromWeekly(dietPlan weeklyPlan[]);
	int chooseDailyPlanFromWeekly(exercisePlan weeklyPlan[]);


	// Display Menu
	void displayMenu(void);



private:

	list <dietPlan> dpHead;

	list <exercisePlan> epHead;

};

