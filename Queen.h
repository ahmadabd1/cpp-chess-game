

#ifndef _QUEEN_H
#define	_QUEEN_H

#include "BasePiece.h"
#include "Rook.h"
#include "Bishop.h"
class Queen : public BasePiece {

public:
    // Constructors
    Queen(Color color, Position pos);
    virtual ~Queen();
    bool vlR(Position);
    bool vlB(Position);
    // Public functions
    bool ValidateMove(Position moveToPosition);

private:
    

};

#endif	/* _QUEEN_H */

