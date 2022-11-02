/*
	Author: LeeTuah
	Word: Mainly
	Time: 12:23 P.M. IST
	Team Dillusioners
	For: League against Jonathan Alex, Titan, Ekectrodrags, King and Dillusioners
*/

# include <iostream>

// class declaration for the program
class MainlyAcademica{
	public:
		MainlyAcademica();
		void main();
		void english();
		void social_science();
		void science();
		int choice, qChoice, points;
};

// constructor initialised with welcome message and points
MainlyAcademica::MainlyAcademica(){
	std::cout <<"\n\n\t\t\tMainly Academia\n";
	std::cout << "This is a quiz-based game about some basic stuff.\nAnswering each question will obtain 2 mark and wrong answer will deduct 1 mark.\n";
	std::cout << "You can choose a specific subject to answer.";
	points = 0;
}

// quiz for subject english
void MainlyAcademica::english(){
	std::cout << "\t\t\nTopic chosen: English\n\n";

	std::cout << "Question 1.\nChoose the correct spelling:\n1. Otorhinoaryngologist\n2. Irregardless\n3. Pseudopseudohypoparathyroidism\n4. Floccinaucinihilipillification\n>> ";
	std::cin >> qChoice;

	if(qChoice == 3){std::cout << "Correct Answer! You gain two points.\n"; points += 2;std::cout << "Current points: " << points << '\n';}
	else{std::cout << "Wrong Answer! You lose one points.\n"; points--; std::cout << "Current points: " << points << '\n';}

	std::cout << "Question 2.\nWhich of these is a noun:\n1. Your mom\n2. Dogs\n3. Among Us\n4. Peak\n>> ";
	std::cin >> qChoice;
	std::cout << "You are wrong! All of them are nouns! You lose a point!\n";
	points--;
}

// quiz for subject social science
void MainlyAcademica::social_science(){
	std::cout << "\t\t\nTopic chosen: Social Studies\n\n";

	std::cout << "Question 1.\nChoose the correct birth year of your mum:\n1. 1991\n2. 2069\n3. 69 million B.C.E\n4. No mum\n>> ";
	std::cin >> qChoice;

	if(qChoice == 4){std::cout << "Correct Answer! You gain two points as you are adopted.\n"; points += 2;std::cout << "Current points: " << points << '\n';}
	else{std::cout << "Wrong Answer! You lose one points.\n"; points--; std::cout << "Current points: " << points << '\n';}

	std::cout << "Question 2.\nWhich of these is a fossil fuel:\n1. Coal\n2. Petrolium\n3. Natural Gas\n4. None of these\n>> ";
	std::cin >> qChoice;
	std::cout << "You are wrong! All of them are natural gases! You lose a point!\n" << "Current points: " << points << '\n';
	points--;
}

// quiz for science
void MainlyAcademica::science(){
	std::cout << "\t\t\nTopic chosen: Science\n\n";

	std::cout << "Question 1.\nWhat is the smallest building block:\n1. Brick\n2. Legos\n3. Atom\n4. Subatomic Particles\n>> ";
	std::cin >> qChoice;

	if(qChoice == 4){std::cout << "Correct Answer! You gain two points.\n"; points += 2;std::cout << "Current points: " << points << '\n';}
	else{std::cout << "Wrong Answer! You lose one points.\n"; points--; std::cout << "Current points: " << points << '\n';}

	std::cout << "Question 2.\nWhich of these is an element:\n1. La\n2. H\n3. Mc\n4. V\n>> ";
	std::cin >> qChoice;
	std::cout << "You are wrong! All of them are elements! You lose a point!\n" << "Current points: " << points << '\n';
	points--;
}

// main method for choosing the quiz
void MainlyAcademica::main(){
	bool running = 1;

	while(running){
		std::cout << "Which topic you want to choose?\n1. English\n2. Social Studies\n3. Science\n0. Exit\n>> ";
		std::cin >> choice;

		switch(choice){
			case 0:
				std::cout << "Thanks for checking out the program!\n";
				running = 0;
				break;
			case 1:
				MainlyAcademica::english();
				break;
			case 2:
				MainlyAcademica::social_science();
				break;
			case 3:
				MainlyAcademica::science();
				break;
		}
	}
}

int main(int argc, char const *argv[]){
	MainlyAcademica* game = new MainlyAcademica();
	// program is running
	game->main();
	return 0;
}
