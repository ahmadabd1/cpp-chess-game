
#ifndef _SQUARE_H
#define	_SQUARE_H

#include "BasePiece.h"  // For Base Class

class Square {
public:
    // Constructors
    Square();
    virtual ~Square();

    // Public functions
    BasePiece* GetPiece();
    void SetPiece(BasePiece *piece);
    void Clear();
    
private:
    // Each Square has a pointer to a chess piece
    BasePiece *chessPiece;
};

#endif	/* _SQUARE_H */

