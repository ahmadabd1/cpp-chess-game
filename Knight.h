

#ifndef _KNIGHT_H
#define	_KNIGHT_H

#include "BasePiece.h"

class Knight : public BasePiece {

public:
    // Constructors
    Knight(Color color, Position pos);
    virtual ~Knight();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _KNIGHT_H */

