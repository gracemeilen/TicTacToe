//Grace Meilen 
#include "Header.h"

//  An enumerator to keep track of the possible colors of game pieces
enum piece_color{ red, black, white, no_color, invalid_color };

// A struct to store the relevant information about a piece for any given game
struct game_piece{
	game_piece(piece_color c, string n, string d);
	piece_color color_;
	string name_;
	string display_;
};

// The class that stores the TicTacToe game and contains the method that allow 
// for game play. 
class Game {
public:
	Game();
	friend ostream &operator<<(ostream &o, const Game &g);
	bool done();
	bool draw();
	int prompt(unsigned int &hor, unsigned int &vert);
	int turn();
	int play();
private:
	vector<game_piece> board;
	bool x_turn;
	int moves;
};
