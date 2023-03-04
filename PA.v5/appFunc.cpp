#include "appHeader.hpp"



// Default Constructor
FitnessAppWrapper::FitnessAppWrapper() { }


// Destructor
FitnessAppWrapper::~FitnessAppWrapper() { }


// Run App
void FitnessAppWrapper::runApp(void) {

	dietPlan dpList[7] = {};
	exercisePlan epList[7] = {};


	bool running = true;

	bool dpLoaded = false, epLoaded = false;

	fstream dpFile;
	fstream epFile;

	while (running) {

		system("cls");
		displayMenu();

		int choice = 0;
		choice = getInt();

		switch (choice) {

		case 1:
			//Load weekly diet plan

			dpFile.open("dietPlans.txt");
			if (dpFile.is_open()) {
				system("cls");
				loadWeeklyPlan(dpFile, dpList);
				dpLoaded = true;
				cout << "Weekly diet plan loaded." << endl;
				dpFile.close();
			}

			else {
				system("cls");
				cout << "Error. Check file path." << endl;
			}

			system("pause");
			break;

		case 2:
			//Load weekly exercise plan

			epFile.open("exercisePlans.txt");
			if (epFile.is_open()) {
				system("cls");
				loadWeeklyPlan(epFile, epList);
				/// <summary>
				/// 
				/// </summary>
				/// <param name=""></param>
				epLoaded = true;
				cout << "Weekly exercise plan loaded." << endl;
				epFile.close();
			}

			else {
				system("cls");
				cout << "Error. Check file path." << endl;
			}

			system("pause");
			break;

		case 3:
			//Store weekly diet plan to file.

			dpFile.open("dietPlans.txt");
			if (dpFile.is_open()) {
				storeWeeklyPlan(dpFile, dpList);
				system("cls");
				cout << "Plan written to dietPlans.txt!" << endl;
				dpFile.close();
			}

			else {
				system("cls");
				cout << "Error. Check file path." << endl;
			}

			system("pause");
			break;

		case 4:
			//Store weekly exercise plan to file.

			epFile.open("exercisePlans.txt");
			if (epFile.is_open()) {
				storeWeeklyPlan(epFile, epList);
				system("cls");
				cout << "Plan written to exercisePlans.txt!" << endl;
				epFile.close();
			}

			else {
				system("cls");
				cout << "Error. Check file path." << endl;
			}

			system("pause");
			break;

		case 5:
			//Display weekly diet plan to screen.

			if (dpLoaded) {
				system("cls");
				displayWeeklyPlan(dpList);
			}

			else {
				system("cls");
				cout << "No diet plan has been loaded!" << endl;
			}

			system("pause");
			break;

		case 6:
			//Display weekly exercise plan to screen.

			if (epLoaded) {
				system("cls");
				displayWeeklyPlan(epList);
			}

			else {
				system("cls");
				cout << "No exercise plan has been loaded." << endl;
			}

			system("pause");
			break;

		case 7:
			//Edit daily diet plan.

			if (dpLoaded) {
				system("cls");
				int planNumber = chooseDailyPlanFromWeekly(dpList);
				dpList[planNumber].editGoal();
				displayDailyPlan(dpList[planNumber]);
			}

			else {
				system("cls");
				cout << "Cannot edit plan. Plan must be loaded prior to editing." << endl;
			}

			system("pause");
			break;

		case 8:
			//Edit daily exercise plan.

			if (epLoaded) {
				system("cls");
				int planNumber = chooseDailyPlanFromWeekly(epList);
				epList[planNumber].editGoal();
				displayDailyPlan(epList[planNumber]);
			}

			else {
				system("cls");
				cout << "Cannot edit plan. Plan must be loaded prior to editing." << endl;
			}

			system("pause");
			break;

		case 9:
			//Exit

			if (dpLoaded) {
				dpFile.open("dietPlans.txt");
				storeWeeklyPlan(dpFile, dpList);
				epFile.close();
			}

			if (epLoaded) {
				epFile.open("exercisePlans.txt");
				storeWeeklyPlan(epFile, epList);
				epFile.close();
			}


			//Close files if open
			if (epFile.is_open()) {
				epFile.close();
			}

			if (dpFile.is_open()) {
				dpFile.close();
			}

			running = false;
			break;

		default:
			system("cls");
			cout << "Enter a valid number." << endl;
		}
	}
}


// get int from user
int FitnessAppWrapper::getInt(void) {
	int num = 0;
	cin >> num;
	return num;
}


// Load Daily Plan
void FitnessAppWrapper::loadDailyPlan(fstream& fs, dietPlan& plan) {
	fs >> plan;
}


// Load Daily Plan (overloaded)
void FitnessAppWrapper::loadDailyPlan(fstream& fs, exercisePlan& plan) {
	fs >> plan;
}


// Load Daily Plan (overloaded for list)
void FitnessAppWrapper::loadDailyPlan(fstream& fs, dietPlan* plan) {
	fs >> *plan;
}

//create one load daily for EP



// Load Weekly Plan
void FitnessAppWrapper::loadWeeklyPlan(fstream& fs, dietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fs, weeklyPlan[i]);
	}
}

// Load Weekly Plan (DP) - overloaded for list
void FitnessAppWrapper::loadWeeklyPlan(fstream& fs, list<dietPlan>* dpHead) {
	for (int i = 0; i < 7; i++) {

		dietPlan* dpPtr = new dietPlan;

		loadDailyPlan(fs, dpPtr);
	}

}

//create one for EP

// Load Weekly Plan - overloaded
void FitnessAppWrapper::loadWeeklyPlan(fstream& fs, exercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fs, weeklyPlan[i]);
	}
}


// Display Daily Plan
void FitnessAppWrapper::displayDailyPlan(dietPlan& plan) {
	cout << plan << endl;
}


// Display Daily Plan - overloaded for list
void FitnessAppWrapper::displayDailyPlan(dietPlan* plan) {
	cout << *plan << endl;
}

// Display Daily Plan - overloaded
void FitnessAppWrapper::displayDailyPlan(exercisePlan& plan) {
	cout << plan << endl;
}


// Display Weekly Plan
void FitnessAppWrapper::displayWeeklyPlan(dietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]);
	}
}


//// Display Weekly Plan - overloaded for list
//void FitnessAppWrapper::displayWeeklyPlan(dietPlan weeklyPlan[]) {
//	for (int i = 0; i < 7; i++) {
//		cout << i + 1 << ": ";
//		displayDailyPlan(weeklyPlan[i]);
//	}
//}


// Display Weekly Plan - overloaded
void FitnessAppWrapper::displayWeeklyPlan(exercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]);
	}
}


// Write Daily Plan To File
void FitnessAppWrapper::storeDailyPlan(fstream& fs, dietPlan& plan) {
	fs << plan;
}


// Write Daily Plan To File - overloaded
void FitnessAppWrapper::storeDailyPlan(fstream& fs, exercisePlan& plan) {
	fs << plan;
}


// Write Weekly Plan To File
void FitnessAppWrapper::storeWeeklyPlan(fstream& outfile, dietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(outfile, weeklyPlan[i]);
	}
}

// Write Weekly Plan To File - overloaded
void FitnessAppWrapper::storeWeeklyPlan(fstream& fs, exercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(fs, weeklyPlan[i]);
	}
}


// Choosing which plan to edit
int FitnessAppWrapper::chooseDailyPlanFromWeekly(dietPlan weeklyPlan[]) {
	bool choosing = true;
	int choice = 0;
	while (choosing) {
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "Which plan would you like to modify? (1-7): ";
		cin >> choice;
		if (choice > 0 && choice < 8) {
			choosing = false;
		}
	}
	return choice - 1;
}


// Choosing which plan to edit
int FitnessAppWrapper::chooseDailyPlanFromWeekly(exercisePlan weeklyPlan[]) {
	bool choosing = true;
	int choice = 0;
	while (choosing) {

		system("cls");
		displayWeeklyPlan(weeklyPlan);

		cout << "Which plan would you like to modify? Enter a number 1 to 7: ";
		cin >> choice;
		if (choice > 0 && choice < 8) {
			choosing = false;
		}
	}
	return choice - 1;
}

// Display Menu
void FitnessAppWrapper::displayMenu(void) {
	cout << "**************    MENU   *****************" << endl << endl;
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl << endl;

	cout << "Select an option: ";
}