
#include "Pawn.h"       // For Pawn Class
#include "Board.h"      // For Board Class
#include <iostream>     // For outputting to screen

using namespace std;

extern Board board;     // Board is declared in Main. Extern lets compiler know this


/**@summary Constructor
 * @color Color of this new pawn
 * @pos Position of this new pawn
 */
Pawn::Pawn(Color color, Position pos) {
    this->type = "P";
    this->color = color;
    this->pos = pos;
    this->doubleJumpAvailable = true;
}

/**@summary Default Destructor
 */
Pawn::~Pawn() {

}

/**@summary Validates that a possible move abides by this pieces move logic
 *          This is an abstract function in the base class and is implemented here
 *          for each class to allow us a solid OO design.
 * @param moteToPos - Position of where this piece will move
 * @return bool - Success or Fail
 */

bool Pawn::ValidateMove(Position moveToPos) {
    Position pa;
   

    // Iniit variables
    bool validMove = false;
    int a1 = 1;
    int a2 = 2;

    // If Black piece, the movement is downwards on board. Adjust for this
    if (color == Black) {
        a1 = -1;
        a2 = -2;
    }
    pa.xpos = moveToPos.xpos;
    pa.ypos = moveToPos.ypos-a1;
    //***********************  Move Validity Checks  **********************************

    // One square forward to empty square
    if (moveToPos.ypos == pos.ypos + a1 && moveToPos.xpos == pos.xpos && board.GetPiece(moveToPos) == NULL) {
        validMove = true;

        // When this Validate move function evaluates true, the pawn will be moved. Here we
        // set the double jump avail variable to false, since the pawn can only double jump on opening move
        doubleJumpAvailable = false;

    }
    // Two squares forward to empty square. Only available on pawn's first move
    else if (doubleJumpAvailable == true && moveToPos.ypos == (pos.ypos + a2) && moveToPos.xpos == pos.xpos
            && board.GetPiece(moveToPos) == NULL && board.GetPiece(pa) == NULL)   {
        
        validMove = true;
    }
    // Diagonal left or right by one square. Must be another piece there to attack.
    else if (moveToPos.ypos == pos.ypos + a1 && (moveToPos.xpos == pos.xpos - a1 || moveToPos.xpos == pos.xpos + a1) ) {

        // Check if there is a piece in the diagonal position, if so, is it an opposite color
        if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() != this->color) )  {
            validMove = true;
        }
    }

    // Return status flag from checks
    return validMove;
}
