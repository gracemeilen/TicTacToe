//Grace Meilen 
#include "stdafx.h";
#include "piece.h"
#include <sstream>
using namespace std;

// A construtor that takes in a piece_color, string and string 
// and creates a game piece with those values assigned to them. 
game_piece::game_piece(piece_color c, string n, string d)
: color_(c), name_(n), display_(d){};

// Overload the << operator so that when we call it on a Game object, it
// prints out the current status of the gane board. 
ostream& operator<<(ostream &o, const Game &g){
	if (g.board.size() == 5*5){
		// Print so lower left corner is 0,0 and top right is 4,4
		for (int i = 4; i >= 0; --i){
			for (int k = 0; k <= 4; ++k){
				// handles the edge cases so the board is numbered
				if (k == 0 ){
					if (i != 0){
						o << i << " ";
					}
					else{
						o << i << " ";
					}

				}
				else if (i == 0){
					o << k << " ";
				}
				else {
					o << g.board[(5 * i) + k].display_;
				}

			}
			o << endl;
		}
	}
	return o;
}

Game::Game(){
	// Constructor for Game. Fills the board with blank pieces.
	// Sets the game so it always starts out as Player X's turn. 
	// Initializes a counter of how many moves have been made to 0
	for (int i = 0; i < 5; i++){
		for (int k = 0; k < 5; k++){
			(*this).board.push_back(game_piece(no_color, "", "  "));
		}
	}
	(*this).x_turn = true;
	(*this).moves = 0;
}

// Iterates through the board in different orders to see if a player has made a 
// move that would win them the game. It has to check the horizontal, diagonoal 
// and vertical win cases. 
bool Game::done() {
	bool done = false;
	for (int i = 3; i >= 1; --i){
		for (int k = 1; k <= 3; k++){
			//check the horizontal cases
			if (k == 1){
				if ((*this).board[(5 * i) + k].display_.compare("  ") != 0){
					if ((*this).board[(5 * i) + k].display_.compare((*this).board[(5 * i) + k + 1].display_) == 0){
						if ((*this).board[(5 * i) + k].display_.compare((*this).board[(5 * i) + k + 2].display_) == 0){
							done = true;
						}
					}
				}
			}

			//check the vertical cases
			if (i == 3){
				if ((*this).board[(5 * i) + k].display_.compare("  ") != 0){
					if ((*this).board[(5 * i) + k].display_.compare((*this).board[((5 * (i - 1)) + k)].display_) == 0){
						if ((*this).board[(5 * i) + k].display_.compare((*this).board[((5 * (i - 2)) + k)].display_) == 0){
							done = true;
						}
					}
				}
			}

			// check the diagonal cases
			if (i == 2 && k == 2){
				// check left to right diagonal
				if ((*this).board[(5 * i) + k].display_.compare("  ") != 0){
					if ((*this).board[(5 * i) + k].display_.compare((*this).board[(5 * (i + 1)) + (k - 1)].display_) == 0){
						if ((*this).board[(5 * i) + k].display_.compare((*this).board[(5 * (i - 1)) + (k + 1)].display_) == 0){
							done = true;
						}
					}
				}
			
				//check right to left diagonal
				if ((*this).board[(5 * i) + k].display_.compare("  ") != 0){
					if ((*this).board[(5 * i) + k].display_.compare((*this).board[(5 * (i + 1)) + (k + 1)].display_) == 0){
						if ((*this).board[(5 * i) + k].display_.compare((*this).board[(5 * (i - 1)) + (k - 1)].display_) == 0){
							done = true;
						}
					}
				}

			}
		}
	}
	return done; 
} 

// Checks to see is all the valid moves have been made and the nobody has made
// a winning move. 
bool Game::draw(){
	bool moves_left = false;
	// Check if there are moves left
	for (int i = 3; i >= 1; --i){
		for (int k = 1; k <= 3; k++){
			if ((*this).board[(5 * i) + k].display_.compare("  ") == 0){
				moves_left = true;
			}
		}
	}
	// Check if someone has won.
	if (done()){
		return false;
	}
	else if (moves_left){
		return false;
	}
	else{
		return true;
	}
}

// Prompt the player whose turn it is to make a move. Keep prompting them until 
// they either (1) supply a well formed coordinate and make valid move or (2) they
// quit the game. 
int Game::prompt(unsigned int &hor, unsigned int &vert){
	bool valid_move = false;
	bool quit = false;
	string move; 
	string fail;
	// Just keep prompting
	while (!valid_move && !quit){
		cout << "Please enter the coordinates at which you want to move or the word quit. Correct formation is _,_. Remember that your coordinates must be between 1 and 3" << endl;
		cout << endl;
		cin >> move;
		if (move.compare("quit") == 0){
			// quit the program
			return quit_game;
		}
		else{
			// Replace the comma in the arugement with a space so we can 
			// use an extraction operator and an istringstream.
			for (string::iterator it = move.begin(); it != move.end(); it++){
				if ((*it) == ','){
					(*it) = ' ';
				}
			}
			istringstream iss(move);
			if (iss >> hor){
				if (iss >> vert){
					if (!(iss >> fail)){
						if (hor < 4 && vert < 4){
							if (hor > 0 && vert > 0){
								if ((*this).board[(5 * vert) + hor].display_.compare("  ") == 0){
									valid_move = true;
								}
								else{
									cout << "There is already a piece there!" << endl;
								}
							}
							// make sure that the coordinates are in the correct range. 
							else {
								cout << "Invalid Coordinates" << endl;
							}
						}
						// make sure that the coordinates are in the correct range.  
						else {
							cout << "Invalid Coordinates" << endl;
						}
					}
				}
			}
		}
	}
	if (valid_move){
		return success;
	}
	else {
		return quit_game;
	}
}

// Informs the players whose turn it is and prompts that player to enter a move
// If the player quits, the method passes that along, if they make a move, 
// it creates a new game piece and places it in the board and prints out the 
// board including that move as well as a list of of the moves that player has 
// made. 
int Game::turn() {
	// Whose turn is it?
	if ((*this).x_turn){
		cout << "It is Player X's turn" << endl;
	}
	else {
		cout << "It is Player O's turn" << endl;
	}
	unsigned int hor = 0;
	unsigned int vert = 0;
	unsigned int& horizontal = hor;
	unsigned int& vertical = vert;
	// get the user to make a move
	int turn = prompt(horizontal, vertical);
	if (turn == 1){
		return quit_game;
	}
	// create the game piece corresponding to that move. 
	else {
		if ((*this).x_turn){
			game_piece current(no_color, "X", "X ");
			(*this).board[(5 * vert) + hor] = current;
		}
		else {
			game_piece current(no_color, "O", "O ");
			(*this).board[(5 * vert) + hor] = current;
		}
		cout << (*this) << endl;
		// Print all the moves the current player has ever made. And updates the
		// tracker of whose turn it is. 
		if ((*this).x_turn){
			(*this).x_turn = false;
			cout << "Player X: ";
			for(int i = 3; i >= 1; --i){
				for (int k = 1; k <= 3; k++){
					if ((*this).board[(5 * i) + k].display_.compare("X ") == 0){
						cout << ", " << k << ", " << i;
					}
				}
			}
		}
		else {
			(*this).x_turn = true;
			cout << "Player O: ";
			for (int i = 3; i >= 1; --i){
				for (int k = 1; k <= 3; k++){
					if ((*this).board[(5 * i) + k].display_.compare("O ") == 0){
						cout << ", " << k << ", " << i;
					}
				}
			}
		}
		// Increment the number of moves made. 
		(*this).moves++;
		cout << endl;
		return success;
	}
}


// Ties all the previous methods together and actually handles the whole game
// until someone quits or a win/draw is reached. 
int Game::play(){
	cout << "Begin Play" << endl;
	// print out board initially 
	cout << (*this) << endl;
	bool over = false;
	int playing;
	// keep playing until someone quits or the game ends. 
	while (!over){
		playing = turn();
		// Did someone win?
		if (done()){
			if ((*this).x_turn){
				cout << "Player O has won" << endl;
			}
			else{
				cout << "Player X has won" << endl;
			}
			over = true;
			return success;
		}
		// Is there a draw?
		if (draw()){
			cout << "There is a draw! " << (*this).moves << " moves were played" << endl;
			over = true;
			return there_is_a_draw;
		}
		// Did someone quit?
		if (playing == 1){
			over = true;
			cout << "A player has quit the game. There were " << (*this).moves << " turns played" << endl; 
			return game_over_player_quit;
		}

	}
	// This should never be reached, the method should always return before this.
	// But the build process warned me that not all paths lead to a return value 
	// so I added this. 
	return never;
}