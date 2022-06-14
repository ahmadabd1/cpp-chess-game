
#ifndef _ROOK_H
#define	_ROOK_H

#include "BasePiece.h"

class Rook : public BasePiece {

public:
    // Constructors
    Rook();
    Rook(Color color, Position pos);
    virtual ~Rook();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:
  
};


#endif	/* _ROOK_H */

