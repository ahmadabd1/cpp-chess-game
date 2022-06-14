

#ifndef _BOARD_H
#define	_BOARD_H

#include "Square.h" // For Square Class
#include <string>
using namespace std;
class Board {
public:
    // Constructors
    Board();
    virtual ~Board();

    // Public Functions
    void Draw();
    bool MovePiece(Position fromPos, Position toPos, bool is_cast=false);
    void MySetPiece(Position piecePos , Color c, string st);
    bool CheckMovePiece(Position fromPos, Position toPos);
    BasePiece* GetPiece(Position piecePos);
    bool Insufficient(Color color);
    bool Stalemate(Color color);
    bool CheckMoveAnyPiece(Position fromPos);
    bool CheckMate(Color color);
    Position getKingPosition(Color c);
    
private:
    // Private Member Variables
    Square board[8][8];
    // Private Member Functions
    void InitializePieces();
    bool IsWithinBoard(Position pos);

};

#endif	/* _BOARD_H */

