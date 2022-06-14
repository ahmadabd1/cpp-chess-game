
#include "Board.h"      // Board Class
#include "BasePiece.h"
// Base Chess Piece Class
#include <iostream>     // For Output and Input to screen
#include <stdlib.h>
#include <string>
#include <sstream>
#include "Square.h"
using namespace std; // declare namespace to eliminate need for std::



bool ValidateInput(string input1, string input2,string,string);

Position ConvertChessNotation(string move);

// Definition for our chess board. Only Global Var
Board board;

/******************************************
 *  @summary main method - program entry point
 *  @param arc - number of arguments
 *  @param argv - command line parameter array
 *  @return success flag
 ******************************************/
int entry=1;
int main() {

	bool WkingMoved=false,BkingMoved=false;
	bool WRightRookMove=false,WlefttRookMove=false;
	bool BRightRookMove=false,BlefttRookMove=false;
	bool stop_game = false;
    // ***** Variable Initialization ******
    string input1, input2,input3,extra,line; // Input from users temp variables
    Color turnColor = White; // the current color's turn
    bool moveSucceed = false; // control workflow flag
    Position moveFrom; // Position struct for source location
    Position moveTo; // Position struct for target location
    //*************************************


    // Main Game Loop
    /************************************************/
    while (!stop_game) {

        // Output a few carriage returns
//        cout << string(2, '\n');

        // Draws the board to the screen
        board.Draw();


        // Move Validation Loop
        do {

            // Display who's turn it is
            if (turnColor == White) {
                cout  <<entry<< ") White's turn, please enter a move:"<<endl;
            } else {
                cout  <<entry<< ") Black's turn, please enter a move:"<<endl;
            }

            // Input Retrieval and Validation Loop
            /****************************************************/
            do {
                // Read source piece location
            	getline(cin,line);
            	stringstream ss(line);
            	ss>>input1>>input2>>input3>>extra;




                // Validate the input, if invalid, loop to prompt for new input
            } while (input1 == "help" || !ValidateInput(input1, input2,input3,extra));
            /****************************************************/

            
            // Input must be valid, Convert Algebriac Notation into Cartesian based Coordinates
            moveFrom = ConvertChessNotation(input1);
            moveTo = ConvertChessNotation(input2);

            // Check that we selected the right colored piece for whos turn it is
            if (board.GetPiece(moveFrom)->GetColor() != turnColor) {

                cerr <<entry<<") Invalid input; please enter a move:"<<endl;
                moveSucceed = false;

            }
            else {

                // Attempt to move chess piece. Validation relating to specific chess
                // piece rules is made here.
            	bool Rplaycast = false, Lplaycast = false;
            	if (moveFrom.xpos == 4 && moveFrom.ypos == 0 && (moveTo.xpos == 6 || moveTo.xpos == 2)) { //tsre7a
            		if ( moveTo.ypos != 0)         cerr <<entry<<") Invalid input; please enter a move:"<<endl;
            		if ( moveTo.xpos == 6 ) { //right
            			Position posR1;
            			posR1.xpos = 5;
            			Position posR2;
            			posR2.xpos = 6;
            			if (turnColor == White) {
            				posR1.ypos = 0;
            				posR2.ypos = 0;
            			} else {
            				posR1.ypos = 7;
            				posR2.ypos = 7;
            			}
            			if (board.GetPiece(posR1) != NULL || board.GetPiece(posR2) != NULL)         cerr <<entry<<") Invalid input; please enter a move:"<<endl;
            			if (turnColor == White && !WkingMoved && !WRightRookMove) Rplaycast = true;
            			if (turnColor == Black && !BkingMoved && !BRightRookMove) Rplaycast = true;
            		} else {
            			Position posL1;
            			posL1.xpos = 1;
            			Position posL2;
            			posL2.xpos = 2;
            			Position posL3;
            			posL3.xpos = 3;
            			if (turnColor == White) {
            				posL1.ypos = 0;
            				posL2.ypos = 0;
            				posL3.ypos = 0;
            			} else {
            				posL1.ypos = 7;
            				posL2.ypos = 7;
            				posL3.ypos = 7;
            			}
            			if (board.GetPiece(posL1) != NULL || board.GetPiece(posL2) != NULL || board.GetPiece(posL3) != NULL) cerr << "Move Invalid" << endl;
            			if (turnColor == White && !WkingMoved && !WlefttRookMove) Lplaycast = true;
            			if (turnColor == Black && !BkingMoved && !BlefttRookMove) Lplaycast = true;
            		}

            	}

            	if (Rplaycast || Lplaycast){
            		moveSucceed = board.MovePiece(moveFrom, moveTo, true);
            		 if (Rplaycast) {
            		                	Position Rnewpos;
            		                	Position Roldpos;
            		                	Rnewpos.xpos = 5;
            		                	Roldpos.xpos = 7;
            		                	if (turnColor == White) {Rnewpos.ypos = 0;Roldpos.ypos = 0;}
            		                	else {Rnewpos.ypos = 7; Roldpos.ypos = 7;}
            		                	board.MovePiece(Roldpos, Rnewpos,true);
            		                }
            		                if (Lplaycast) {
            		                	Position Lnewpos;
            		                	Position Loldpos;
            		                	Lnewpos.xpos = 3;
            		                	Loldpos.xpos = 0;
            		                	if (turnColor == White) {Lnewpos.ypos = 0;Loldpos.ypos = 0;}
            		                	else {Lnewpos.ypos = 7; Loldpos.ypos = 7;}
            		                	board.MovePiece(Loldpos, Lnewpos,true);
            		                }
            		break;
            	}

            	if (!(board.CheckMate(turnColor))){
            		board.Draw();
            		if(turnColor==White){
            		cout<<"White"<<" wins with checkmate!"<<endl;
            		}else{
            			cout<<"Black"<<" wins with checkmate!"<<endl;
            		}
            		stop_game = true;
            		break;
            	}
            	if(!board.Stalemate(turnColor)){
            		board.Draw();
            		cout<<"The game is drawn due to stalemate!"<<endl;
            		stop_game = true;
            		break;
            	}

            	if(board.Insufficient(turnColor)) {
            		board.Draw();
            		cout<<"The game is drawn due to insufficient material!"<<endl;
            		stop_game = true;
            		break;
            	}

            	moveSucceed = board.MovePiece(moveFrom, moveTo);


            	if(input3.size()==1){
            		if(turnColor==Black && moveFrom.ypos==7&&moveTo.ypos==8){
            			delete	board.GetPiece(moveTo);
            			if (input3=="Q")
            				board.MySetPiece(moveTo, turnColor, "Q");
            			if (input3=="N")
            				board.MySetPiece(moveTo, turnColor, "N");
            			if (input3=="B")
            				board.MySetPiece(moveTo, turnColor, "B");
            			if (input3=="R")
            				board.MySetPiece(moveTo, turnColor, "R");
            		}else if(turnColor==White && moveFrom.ypos==7 && moveTo.ypos==8){
            			delete	board.GetPiece(moveTo);
            			if (input3=="Q")
            				board.MySetPiece(moveTo, turnColor, "q");
            			if (input3=="N")
            				board.MySetPiece(moveTo, turnColor, "n");
            			if (input3=="B")
            				board.MySetPiece(moveTo, turnColor, "b");
            			if (input3=="R")
            				board.MySetPiece(moveTo, turnColor, "r");

            		}
            	 }





                // Give feedback if move failed or not
                if (moveSucceed == false) {
                    cerr <<entry <<")Invalid input; please enter a move:"<<endl  ;
                }
                else {
                	//----
                	if (turnColor == White) {
                		if (moveFrom.xpos == 4 && moveFrom.ypos == 0 ) WkingMoved = true;
                		if (moveFrom.xpos == 7 && moveFrom.ypos == 0 ) WRightRookMove = true;
                		if (moveFrom.xpos == 0 && moveFrom.ypos == 0 ) WlefttRookMove = true;
                	} else if (turnColor == Black) {
                		if (moveFrom.xpos == 4 && moveFrom.ypos == 7 ) BkingMoved = true;
                		if (moveFrom.xpos == 7 && moveFrom.ypos == 7 ) BRightRookMove = true;
                		if (moveFrom.xpos == 0 && moveFrom.ypos == 7 ) BlefttRookMove = true;
                	}

                }
            }
            // If move failed, loop back without redrawing board

        } while (moveSucceed == false);
        entry+=1;
        // Move succeeded. Change whos turn it is.
        if (turnColor == White) {
            turnColor = Black;
        } else if (turnColor == Black) {
            turnColor = White;
        }

    }
    // End of Main Game Loop
    /***********************************************/

    return (EXIT_SUCCESS);
}



/******************************************
 *  @summary Validates the user move input and displays a friendly message
 *  @param input1 - User input string
 *  @param input2 - User input string
 *  @return bool - True if there are any input errors
 ******************************************/
bool ValidateInput(string input1, string input2,string input3,string extra) {


    // Check if input is right size
    if (extra.size()!=0 || input3.size()>1 || input1.size() != 2 || input2.size() != 2 || !(isupper(input1[0]))|| !(isupper(input2[0]))){
//    	cout<< "input1.size() = " << input1.size() << endl;
//    	cout<< "input2.size() = " << input2.size() << endl;
//    	cout<< "isupper(input1[0]) = " << isupper(input1[0]) << endl;
//    	cout<< "isupper(input2[0]) = " << isupper(input2[0]) << endl;
        cerr <<entry<<") Invalid input; please enter a move:"<<endl;
    } else {


        // Convert Algebriac Notation into Cartesian based Coordinates
        Position moveFrom = ConvertChessNotation(input1);
        Position moveTo = ConvertChessNotation(input2);

        if(input3.size()==1){
        	if(board.GetPiece(moveFrom)->getType() !="P" && board.GetPiece(moveFrom)->getType()!="p"){
        		cerr <<entry<< ") Invalid input; please enter a move:"<<endl;
        		return false;

        	}
        	if(input3!="Q"||input3!="R"||input3!="B"||input3!="N"){
        		cerr <<entry<< ") Invalid input; please enter a move:"<<endl;
        		return false;
        	}
//
         }
        // Check if x or y Position from the source location falls outside of the chess board
        if (moveFrom.xpos < 0 || moveFrom.xpos > 7 || moveFrom.ypos < 0 || moveFrom.ypos > 7 ||board.GetPiece(moveFrom)==NULL) {
            cerr <<entry<< ") Illegal move; please enter a move:"<<endl ;
        // Check if x or y Position from the target location falls outside of the chess board
        } else if (moveTo.xpos < 0 || moveTo.xpos > 7 || moveTo.ypos < 0 || moveTo.ypos > 7) {
            cerr <<entry<< ") Illegal move; please enter a move:"<<endl;
        } else  {

            return true;
        }
    }

    return false;
}

/** 
 **  These are Cartesian coordinates and 0 based starting at bottom left corner of board
 */
Position ConvertChessNotation(string moveInputStr) {

    Position movePosition;

    // Index first character , cast to an int, and subtract 65 to make acii
    // letter based, 0 based
    movePosition.xpos = (int) moveInputStr[0] - 65;
    // Convert numeric char to a number. Subtract 1 to make 0 based
    movePosition.ypos = atoi(&moveInputStr[1]) - 1;

    // Return 0 based Cartesion position information
    return movePosition;
}


