

#ifndef _KING_H
#define	_KING_H

#include "BasePiece.h"

class King : public BasePiece {

public:
    // Constructors
    King(Color color, Position pos);
    virtual ~King();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _KING_H */

