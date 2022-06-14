

#include "King.h"
#include "Board.h"
/**@summary Constructor
 * @color Color of this new piece
 * @pos Position of this new piece
 */

extern Board board;
King::King(Color color, Position pos) {
    this->type = "K";
    this->color = color;
    this->pos = pos;
}

/**@summary Default Destructor
 */
King::~King() {

}

/**@summary Validates that a possible move abides by this pieces move logic
 * @param moteToPos - Position of where this piece will move
 * @return bool - Success or Fail
 */
bool King::ValidateMove(Position moveToPos) {
    bool validMove = false;

    int allowableMove1 = 1;
    if (color == Black) {
       allowableMove1 = -1;
    }
   
    //***********************  Move Validity Checks  **********************************

   // One square forward to empty square
    if ((moveToPos.ypos == pos.ypos + allowableMove1 || moveToPos.ypos == pos.ypos - allowableMove1 || moveToPos.ypos == pos.ypos)
        && (moveToPos.xpos == pos.xpos || moveToPos.xpos == pos.xpos + allowableMove1 || moveToPos.xpos == pos.xpos - allowableMove1)
        && board.GetPiece(moveToPos) == NULL) {
        validMove = true;

    }else if (board.GetPiece(moveToPos) != NULL && (board.GetPiece(moveToPos)->GetColor() != this->color)) {
        validMove = true;
    }
    return validMove;
}

