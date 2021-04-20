#include<string>
#include<iostream> 
#include<fstream>
#include<map>
#include<vector>
#include"Answer.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::map;
using std::vector;


int mainMenu();
void menuDecision(int);
void startGame(string, string);
void mainGame(vector<Answer*>, string&, string&);
void setAnswers(string&, string&);
void saveGame(int, string&);
void selectSaveSlot();
void emptySlot(int);
void hasProgress(int);
void selectProgressFile(int,int,int);
map<string, int> generateMap(vector<Answer*>);
void printFile(string&);
void deleteProgressFile(int, int, int);
void deleteFile(string&,string&);


//Overload of operator that takes an ofstream object and writes ans object answer
ofstream& operator << (ofstream& gameFile, Answer& currentAnswer) {

		gameFile << currentAnswer.getParagraph();
		gameFile << "\n";
		gameFile << currentAnswer.getFirstAnswer();
		gameFile << "\n";
		gameFile << currentAnswer.getSecondAnswer();
		gameFile << "\n";
		gameFile << "\n";

		return gameFile;
}




//Contains the main menu, basicaly it shows the user the instructios he can do
int mainMenu() {

	int menuAction{ 0 };

	cout << "********** MAIN MENU **********" << endl << endl;
	cout << "Choose an action: " << endl;
	cout << "1) New game" << endl;
	cout << "2) Load game" << endl;
	cout << "3) Delete a file" << endl;
	cout << "4) Quit game" << endl;

	cin >> menuAction;

	return menuAction;
}



//Makes sure that the file that the user wants to use is available
void emptySlot(int slotSelection) {

	ifstream newGame;
	bool isEmpty{false};
	int couter{ 0 };
	string auxiliar{ "" };

	//This switch check if there's content written on a file, if there's nothing in the file, starts the game as a new game
	switch (slotSelection)
	{
	case 1: {
		newGame.open("save_slot_1.txt");

		if (newGame.bad())
		{
			cout << "ERROR: canot access to save slot 1" << endl;
		}
		else {
			while (!newGame.eof()) {
				getline(newGame, auxiliar);
				couter++;
			}
			if (couter > 1)
			{
				newGame.close();
				cout << "This file has a progress" << endl;
				selectSaveSlot();
			}

			else {
				newGame.close();
				startGame("save_slot_1.txt", "save_slot_1_progress.txt");
			}
		}

		break;
	}

	case 2: {

		newGame.open("save_slot_2.txt");

		if (newGame.bad())
		{
			cout << "ERROR: canot access to save slot 2" << endl;
		}
		else {
			while (!newGame.eof()) {
				getline(newGame, auxiliar);
				couter++;
			}
			if (couter > 1)
			{
				newGame.close();
				cout << "This file has a progress" << endl;
				selectSaveSlot();
			}

			else {
				newGame.close();
				startGame("save_slot_2.txt", "save_slot_2_progress.txt");
			}
		}

		break;
	}

	case 3: {

		newGame.open("save_slot_3.txt");

		if (newGame.bad())
		{
			cout << "ERROR: canot access to save slot 3" << endl;
		}
		else {
			while (!newGame.eof()) {
				getline(newGame, auxiliar);
				couter++;
			}
			if (couter > 1)
			{
				newGame.close();
				cout << "This file has a progress" << endl;
				selectSaveSlot();
			}

			else {
				newGame.close();
				startGame("save_slot_3.txt", "save_slot_3_progress.txt");
			}
		}

		break;
	}
	default: {
		cout << "Not valid option" << endl;
		break;
	}
	}

}




//Prints the progress on the story of the file
void printFile(string& story) {

	ifstream gameFile;
	string printLine{ "" };

	gameFile.open(story);

	if (gameFile.bad())
	{
		cout << "ERROR: canot access to this file" << endl;
	}
	else {
		while (!gameFile.eof())
		{
			getline(gameFile, printLine);
			cout << printLine << endl;
		}
	}

}




//Deletes the progress of a file
void deleteFile(string& gameFile, string& gameFileSave) {

	int menu{ 0 };
	ofstream file;

	file.open(gameFile);
	file.close();
	file.open(gameFileSave);
	if (file.bad()) {
		cout << "Something wrong happen..." << endl;
	}
	else {
		file << "0";
	}
	file.close();

	cout << "The file progress was deleted" << endl;
	menu = mainMenu();
	menuDecision(menu);
}





//Shows the user the saveslots he can use
void selectSaveSlot() {

	int SaveSlotSelection{ 0 };

	cout << "Choose the file where tou would like to play remember: to exit the game just type 'quit' " << endl;
	cout << "Save slot 1" << endl;
	cout << "Save slot 2" << endl;
	cout << "Save slot 3" << endl << endl;

	cin >> SaveSlotSelection;

	emptySlot(SaveSlotSelection);
}





//Print the files that contains a progress so it can delete it
void deleteProgressFile(int slot1, int slot2, int slot3) {
	int selection{ 0 };
	cin >> selection;
	string gameFile{ "" }, gameFileSave{ "" };


	//This swtich makes sure that the slot that user selects is a valid one
	switch (selection)
	{
	case 1: {
		if (slot1 == 0)
		{
			cout << "Not a valid slot" << endl << endl;
			hasProgress(1);
		}
		else {
			gameFile = "save_slot_1.txt";
			gameFileSave = "save_slot_1_progress.txt";
			deleteFile(gameFile,gameFileSave);
		}

		break;
	}

	case 2: {
		if (slot2 == 0)
		{
			cout << "Not a valid slot" << endl << endl;
			hasProgress(1);
		}
		else {
			gameFile = "save_slot_2.txt";
			gameFileSave = "save_slot_2_progress.txt";
			deleteFile(gameFile,gameFileSave);
		}
		break;
	}

	case 3: {
		if (slot3 == 0)
		{
			cout << "Not a valid slot" << endl << endl;
			hasProgress(1);
		}
		else {
			gameFile = "save_slot_3.txt";
			gameFileSave = "save_slot_3_progress.txt";
			deleteFile(gameFile,gameFileSave);
		}
		break;
	}

	default: {
		cout << "Not a valid slot" << endl << endl;
		hasProgress(1);
		break;
	}

	}
}





//Print files that contains a progress so it can be loaded to play
void selectProgressFile(int slot1, int slot2, int slot3) {

	int selection{ 0 };
	cin >> selection;
	string gameFile{ "" }, gameFileSave{ "" };


	//This switch makes sure that the slot that the user selects is a valid one
	switch (selection)
	{
	case 1: {
		if (slot1 == 0)
		{
			cout << "Not a valid slot" << endl<<endl;
			hasProgress(2);
		}
		else {
			gameFile = "save_slot_1.txt";
			gameFileSave = "save_slot_1_progress.txt";
			printFile(gameFile);
			setAnswers(gameFileSave,gameFile);
		}

		break;
	}

	case 2: {
		if (slot2 == 0)
		{
			cout << "Not a valid slot" << endl<<endl;
			hasProgress(2);
		}
		else {
			gameFile = "save_slot_2.txt";
			gameFileSave = "save_slot_2_progress.txt";
			printFile(gameFile);
			setAnswers(gameFileSave, gameFile);
		}
		break;
	}

	case 3: {
		if (slot3 == 0)
		{
			cout << "Not a valid slot" << endl<<endl;
			hasProgress(2);
		}
		else {
			gameFile = "save_slot_3.txt";
			gameFileSave = "save_slot_3_progress.txt";
			printFile(gameFile);
			setAnswers(gameFileSave, gameFile);
		}
		break;
	}

	default: {
		cout << "Not a valid slot" << endl<<endl;
		hasProgress(2);
		break;
	}

	}
}




//Looks for the files that contains progress so it can be deleted or loaded
void hasProgress(int decision) {
	ifstream progressFile;
	string auxiliar{ "" };
	int counter{ 0 };
	int slot1{ 0 }, slot2{0}, slot3{ 0 };

	cout << "The files that has progress are:" << endl<<endl;

	//This sequence reads a file to know if there's content on it
	progressFile.open("save_slot_1.txt");

	if (progressFile.bad())
	{
		cout << "ERROR: canot access to save slot 1" << endl;
	}
	else {
		while (!progressFile.eof()) {
			getline(progressFile, auxiliar);
			counter++;
		}
		if (counter > 1)
		{
			progressFile.close();
			slot1 = 1;
			cout << "Save slot 1" << endl;
		}
		else {
			progressFile.close();
		}
	}

	counter = 0;

	//This sequence reads a file to know if there's content on it
	progressFile.open("save_slot_2.txt");

	if (progressFile.bad())
	{
		cout << "ERROR: canot access to save slot 1" << endl;
	}
	else {
		while (!progressFile.eof()) {
			getline(progressFile, auxiliar);
			counter++;
		}
		if (counter > 1)
		{
			progressFile.close();
			cout << "Save slot 2" << endl;
			slot2 = 2;
		}
		else {
			progressFile.close();
		}
	}

	counter = 0;

	//This sequence reads a file to know if there's content on it
	progressFile.open("save_slot_3.txt");

	if (progressFile.bad())
	{
		cout << "ERROR: canot access to save slot 1" << endl;
	}
	else {
		while (!progressFile.eof()) {
			getline(progressFile, auxiliar);
			counter++;
		}
		if (counter > 1)
		{
			progressFile.close();
			cout << "Save slot 3" << endl;
			slot3 = 1;
		}
		else {
			progressFile.close();
		}
	}

	counter = 0;

	//This if check which function wants to be executed
	if (decision == 2)
	{
		selectProgressFile(slot1, slot2, slot3);
	}
	else if (decision == 3)
	{
		deleteProgressFile(slot1, slot2, slot3);
	}
}






//It handles with the input that the user entered in the mainMenu() function
void menuDecision(int mAction) {

	string fileName{ "" };
	string currentFile{ "" };
	string loadFile{ "" };
	bool onlyLetters{ false };
	int newDecision{ 0 };

	//This switch checks the decision that was made on the main menu and execute it
	switch (mAction)
	{
	case 1: {
		selectSaveSlot();
		break;
	}

	case 2: {
		hasProgress(2);


		break;
	}

	case 3: {
		hasProgress(3);

		break;
	}

	case 4: {


		break;
	}

	default: {
		cout << "Not valid comand" << endl;
		cout << "Try again:" << endl;
		cin >> newDecision;
		menuDecision(newDecision);

		break;
	}
	}

}





//It opens the file the user load or create and starts the main game
void startGame(string chosenFile, string saveSlot) {

	ofstream game;

	game.open(saveSlot);

	if (game.bad())
	{
		cout << "Something went wrong with the file" << endl;
	}
	else
	{
		//set the number zero because it will be a new game
		game << "0";
		game.close();
		setAnswers(saveSlot, chosenFile);
	}
		
}




//Returns the map that contains the story and decisions
map<string, int> generateMap(vector<Answer*> scenarios) {

	map<string, int> decisionsLine;
	decisionsLine[scenarios[0]->getFirstAnswer()] = 1;
	decisionsLine[scenarios[0]->getSecondAnswer()] = 2;

	decisionsLine[scenarios[2]->getFirstAnswer()] = 4;
	decisionsLine[scenarios[2]->getSecondAnswer()] = 3;

	decisionsLine[scenarios[3]->getFirstAnswer()] = 7;
	decisionsLine[scenarios[3]->getSecondAnswer()] = 6;

	decisionsLine[scenarios[4]->getFirstAnswer()] = 5;
	decisionsLine[scenarios[4]->getSecondAnswer()] = 6;

	decisionsLine[scenarios[5]->getFirstAnswer()] = 11;
	decisionsLine[scenarios[5]->getSecondAnswer()] = 11;

	decisionsLine[scenarios[6]->getFirstAnswer()] = 7;
	decisionsLine[scenarios[6]->getSecondAnswer()] = 11;

	decisionsLine[scenarios[7]->getFirstAnswer()] = 9;
	decisionsLine[scenarios[7]->getSecondAnswer()] = 8;

	decisionsLine[scenarios[9]->getFirstAnswer()] = 9;
	decisionsLine[scenarios[9]->getSecondAnswer()] = 8;

	decisionsLine[scenarios[10]->getFirstAnswer()] = 11;
	decisionsLine[scenarios[10]->getSecondAnswer()] = 11;

	decisionsLine[scenarios[11]->getFirstAnswer()] = 12;
	decisionsLine[scenarios[11]->getSecondAnswer()] = 13;

	decisionsLine[scenarios[12]->getFirstAnswer()] = 14;
	decisionsLine[scenarios[12]->getSecondAnswer()] = 15;

	decisionsLine[scenarios[14]->getFirstAnswer()] = 16;
	decisionsLine[scenarios[14]->getSecondAnswer()] = 17;

	return decisionsLine;

}





//It's were all tha main logic of the game happens
void mainGame(vector<Answer*> scenarios, string& saveSlot, string& chosenFile) {

	string answer{ "" };
	int actualDecision{ 0 };
	string saveAux{ "" };
	ifstream savedGame;
	ofstream writeStory;

	//Open the file that contains the part of the story that the player was when he saved his progress and store that in
	//a variable so it can be used by the program
	savedGame.open(saveSlot);

	if (savedGame.bad())
	{
		cout << "Oh no" << endl;
	}
	else {
		getline(savedGame, saveAux);
		actualDecision = stoi(saveAux);
		savedGame.close();
	}

	//Here we obtain the map that contains all the story
	map<string, int> decisionsLine1 = generateMap(scenarios);

	cin.ignore();

	//Prints the index of the map that belongs to the last decision that the user was after saving his progress
	cout << endl << scenarios[actualDecision]->getParagraph() << endl;
	cout << endl << scenarios[actualDecision]->getFirstAnswer() << endl;
	cout << endl << scenarios[actualDecision]->getSecondAnswer() << endl<<endl;


	//Opens the file that will contain the record of the story in append mode
	writeStory.open(chosenFile, std::ios_base::app);

	if (writeStory.bad())
	{
		cout << "Error: canot open the file" << endl;
	}
	else {
		//checks the answer entered by the user
		while (answer != "quit")
		{
			getline(cin, answer);

			//checks the answer entered by the user
			if (answer != "quit" && answer != scenarios[actualDecision]->getFirstAnswer() && answer != scenarios[actualDecision]->getSecondAnswer())
			{
				cout << "Not a valid comand" << endl;
			}
			else {
				if (answer == "quit")
				{
					writeStory.close();
					saveGame(actualDecision, saveSlot);
				}
				else {
					//the actual scenario is written on the current file
					writeStory << *scenarios[actualDecision];

					//prints the actual scenario on console
					cout << endl << scenarios[decisionsLine1[answer]]->getParagraph() << endl;
					cout << scenarios[decisionsLine1[answer]]->getFirstAnswer() << endl << endl;
					cout << scenarios[decisionsLine1[answer]]->getSecondAnswer() << endl << endl;


					//Now the new scenario will be the one that belongs to one of the answers last scenario
					actualDecision = decisionsLine1[answer];
				}

			}

		}

	}
}





//Updates the files so it can be loaded latter
void saveGame(int progress, string& saveSlot) {

	ofstream changeProgress;
	string toString{ "" };

	toString = std::to_string(progress);

	changeProgress.open(saveSlot);

	if (changeProgress.bad())
	{
		cout << "Oh no" << endl;
	}
	else {

		changeProgress << toString;
		changeProgress.close();

	}
}





//Separates a .txt file and store the content in an array
void setAnswers(string& saveSlot, string& chosenFile) {
	
	ifstream story;
	vector<Answer*> scenarios;
	string aux{ "" }, answer{ "" };

	//This file contains the hole story
	story.open("story.txt");

	if (story.bad())
	{
		cout << "Oh no";
	}

	else {

		//Separate the .txt files into pieces and make answers objects from it, then those objects
		//are stores on an array
		while (!story.eof()) {

			Answer* actualScenario = new Answer();
		
			for (int i = 1; i <= 3; i++)
			{
				getline(story, aux);

				answer = answer + aux + "\n";
			}

			actualScenario->setParagraph(answer);
			answer = "";

			for (int i = 1; i <= 2; i++)
			{
				getline(story, aux);

				switch (i)
				{
				case 1: {
					actualScenario->setFirstAnswer(aux);
					break;
				}

				case 2: {
					actualScenario->setSecondAnswer(aux);
					break;
				}


				default:
					break;
				}
			}

			scenarios.push_back(actualScenario);
		
		}


	}

	mainGame(scenarios, saveSlot, chosenFile);

}






//This is the main
int main() {
	int menuAction { 0 };

	menuAction = mainMenu();

	if (menuAction == 4) {

		return 0;

	}
	else {

		menuDecision(menuAction);

	}

}