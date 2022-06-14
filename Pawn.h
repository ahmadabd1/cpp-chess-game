

#ifndef _PAWN_H
#define	_PAWN_H

#include "BasePiece.h"

class Pawn : public BasePiece {

public:
    // Constructors
    Pawn(Color color, Position pos);
    virtual ~Pawn();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:
    // Indicates whether a double jump first move is available
    bool doubleJumpAvailable;
    
};

#endif	/* _PAWN_H */

