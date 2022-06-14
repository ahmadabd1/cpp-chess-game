

#include "Square.h"         // For Square Class
#include "BasePiece.h"      // For Base Class

/**@summary Default Constructor
 */
Square::Square() {
    chessPiece = NULL;
}

/**@summary Default Destructor
 */
Square::~Square() {
}

/**@summary Getter for chessPiece
 */
BasePiece* Square::GetPiece() {
    return chessPiece;
}

/**@summary Setter for chessPiece
 */
void Square::SetPiece(BasePiece *piece) {
    this->chessPiece = piece;
}

/**@summary Clears current square of any chess piece
 */
void Square::Clear() {
    this->chessPiece = NULL;
}
