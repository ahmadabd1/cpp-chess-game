
#ifndef _BISHOP_H
#define	_BISHOP_H

#include "BasePiece.h"

class Bishop : public BasePiece {

public:
    // Constructors
    Bishop();
    Bishop(Color color, Position pos);
    virtual ~Bishop();

    // Public functions
    bool ValidateMove(Position moveToPosition);
private:

};

#endif	/* _BISHOP_H */

