//Grace Meilen
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//all the return values used throughout the program. 
enum exceptions{ success, quit_game, game_over_player_quit, there_is_a_draw, fail_proper_use, never};

// Prints a usage message to the console that specifies how the progam should be 
// run if there was an error in its execution. Returns the value 6, which indicates 
// failure of proper use. 
int usage_message(const string &program_name, const string &usage);




