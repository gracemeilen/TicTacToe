
Lab number:Lab2
Graded by:Yilong Hu   (hu.yilong@wustl.edu)
Score: 99/ 100 (99+ 0 extra credit )
Comments:

Great job!

-1 Please print out how many turns it took when one player won in addition to listing them out

----------------------------------------

Grace Meilen
Lab2

I ran into an error early on where the << operator that I redefined was messing up a cout<<"string "; This ended up
being because I had failed to #include string.

After building my program, I ran it using a series of both well formed and poorly formed commands and inputs. 
Below are the commands and the program's return message.
lab2.exe			usage: lab2.exe TicTacToe
lab2.exe TicTacToe Please	usage: lab2.exe TicTacToe
lab2.exe TicTacToe		Begin Play
				4
				3
				2
				1
				0 1 2 3 4
				It is Player X's turn
				Please enter the coordinates at which you want to move or the word quit. Correct
				formation is _,_ Remember that your coordinates must be between 1 and 3.

These are the different moves I tried to make and what the program returned:
1,1 				4
				3
				2
				1 X
				0 1 2 3 4
				Player X: 1, 1
				It is Player O's turn
				Please enter the coordinates at which you want to move or the word quit. Correct
				formation is _,_ Remember that your coordinates must be between 1 and 3.


1,23				Please enter the coordinates at which you want to move or the word quit. Correct
				formation is _,_ Remember that your coordinates must be between 1 and 3.

1,2,3				Invalid Coordinates
				Please enter the coordinates at which you want to move or the word quit. Correct
				formation is _,_ Remember that your coordinates must be between 1 and 3.

1, two				Please enter the coordinates at which you want to move or the word quit. Correct
				formation is _,_ Remember that your coordinates must be between 1 and 3.

1, 2				Please enter the coordinates at which you want to move or the word quit. Correct
				formation is _,_ Remember that your coordinates must be between 1 and 3.

quit				A player has quit the game. There were 1 turns played


All of these return messages are expected behavoir. 
