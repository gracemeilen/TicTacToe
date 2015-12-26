//Grace Meilen
// lab2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "piece.h"
using namespace std;

// returns a message specifying the proper execution of this program. 
int usage_message(const string &program_name, const string &usage){
	cout << "usage: " << program_name << " " << usage << endl;
	return fail_proper_use;
}



int main(int argc, char* argv[])
{
	// all the argument values that will be used in checking whether the 
	// command line call was well formed or not. 
	const int proper_num_arguments = 2;
	const int index_of_program_name = 0;
	const int index_of_game_name = 1;

	// Check to make sure a parameter was passes in addition to the program name.
	if (argc != proper_num_arguments){
		const string &use = "TicTacToe";
		return usage_message(argv[index_of_program_name], use);
	}
	// Check to make sure that second parameter was "TicTacToe"
	string parameter = argv[index_of_game_name];
	if (parameter.compare("TicTacToe") != 0){
		const string &use = "TicTacToe";
		return usage_message(argv[index_of_program_name], use);
	}

	// Instantiate an object of the game and play away. 
	Game* ttt = new Game();
	int return_value = (*ttt).play();
	return return_value;
}

