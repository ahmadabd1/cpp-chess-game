
#include "Queen.h"
#include "Board.h" 
#include "Rook.h"
#include "Bishop.h"
using namespace std;
#include <iostream>
#include <cstdlib>
/**@summary Constructor
 * @color Color of this new piece
 * @pos Position of this new piece
 * 
 */
extern Board board;

Queen::Queen(Color color, Position pos) {
    this->type = "Q";
    this->color = color;
    this->pos = pos;
}


/**@summary Default Destructor
 */
Queen::~Queen() {

}
bool Queen::vlR(Position moveToPos){
	// Iniit variables
		bool validMove = true;
		//***********************  Move Validity Checks  **********************************

		// One square forward to empty square
		int x_dir = pos.xpos == moveToPos.xpos ? 0 : (pos.xpos < moveToPos.xpos ? 1 : -1);
		int y_dir = pos.ypos == moveToPos.ypos ? 0 : (pos.ypos < moveToPos.ypos ? 1 : -1);
		if ((abs(moveToPos.xpos - pos.xpos) != 0) && (abs(moveToPos.ypos - pos.ypos) != 0)) return false;
		int dist = (moveToPos.xpos - pos.xpos) + (moveToPos.ypos - pos.ypos);
		dist = dist < 0 ? -dist : dist;

		BasePiece* temp;
		for (int j = 1; j <= dist; j++) {
			int new_x = pos.xpos + j*x_dir;
			int new_y = pos.ypos + j*y_dir;
			// if newx or new_y out of bounds => problem

			Position p;
			p.xpos = new_x;
			p.ypos = new_y;
			temp = board.GetPiece(p);
			if (!temp) {
				continue;
			}
			if (color == temp->GetColor()) {
				validMove = false;
				break;
			}
			if (color != temp->GetColor() && (j < dist - 1)) {
				validMove = false;
				break;
			}
		}


		return validMove;

}
bool Queen::vlB(Position moveToPos){
	   bool validMove = true;

	    //***********************  Move Validity Checks  **********************************
	    int x_dir = pos.xpos < moveToPos.xpos ? 1 : -1;
	    int y_dir = pos.ypos < moveToPos.ypos ? 1 : -1;
        if (abs(moveToPos.xpos - pos.xpos) != abs(moveToPos.ypos - pos.ypos)) return false;
	    int dist = (moveToPos.xpos - pos.xpos);
	    dist = dist < 0 ? -dist : dist;

	    BasePiece* temp;
	    for (int j = 1; j <= dist; j++) {
	        int new_x = pos.xpos + j * x_dir;
	        int new_y = pos.ypos + j * y_dir;
	        // if newx or new_y out of bounds => problem

	        Position p;
	        p.xpos = new_x;
	        p.ypos = new_y;
	        temp = board.GetPiece(p);
	        if (!temp) {
	            continue;
	        }
	        if (color == temp->GetColor()) {
	            validMove = false;
	            break;
	        }
	        if (color != temp->GetColor() && (j < dist - 1)) {
	            validMove = false;
	            break;
	        }
	    }

	    // Return status flag from checks
	    return validMove;
}

/**@summary Validates that a possible move abides by this pieces move logic
 * @param moteToPos - Position of where this piece will move
 * @return bool - Success or Fail
 */
bool Queen::ValidateMove(Position moveToPos) {

    // Iniit variables
    bool validMove = true;

    //***********************  Move Validity Checks  **********************************

//    cout<<"vlR = "<<vlR(moveToPos)<<"  "<<"vlB = "<<vlB(moveToPos);

    if (( vlR(moveToPos)==false && vlB(moveToPos)==false)) {
//    	cout<<"vlR = "<<vlR(moveToPos)<<"  "<<"vlB = "<<vlB(moveToPos);
        validMove =false;
   }


    // Return status flag from checks
    return validMove;
}


