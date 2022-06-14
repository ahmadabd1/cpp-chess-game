

#include "Board.h"      // Header file for this class
#include "BasePiece.h"  // For Base Piece Class
#include "Pawn.h"       // For Pawn Class
#include "Rook.h"       // For Rook Class
#include "Queen.h"      // For Queen Class
#include "Knight.h"     // For Knight Class
#include "King.h"       // For King Class
#include "Bishop.h"     // For Bishop Class
#include <iostream>     // FOr output to screen

using namespace std;    // declare namespace to eliminate need for std::

/**@summary Default Constructor
 */
Board::Board() {
    InitializePieces();
}

/**@summary Default Destructor
 */
Board::~Board() {
}

/**@summary Draws the 8x8 chess board on the screen
 * @return void
 */
void Board::Draw() {
    for (int row = 7; row >= 0; row--) {

        // Draws Vertical Row Divider and Chess Piece
        cout << row + 1 << " ";
        for (int col = 0; col < 8; col++) {
            
            BasePiece *currPiece = board[row][col].GetPiece();
            if (currPiece != NULL) {
                currPiece->Draw();
            } else {
                cout << ".";
            }
            cout << " ";
        }

        // Draws Divider for end of Row
        cout <<endl;

    }

    // Draws Letters on botton of board
    cout << "  ";
    for (int col = 0; col < 8; col++) {
        cout <<(char) (col + 65) << " ";
    }
    cout << endl << endl;

}

/**@summary Instantiates and sets chess pieces to where they should be on the board
 * @return void
 */
void Board::InitializePieces() {

    // ****** Initialize Board with Pieces *******

    // Pawns
    for (int col = 0; col < 8; col++) {
        Position blackPawnPos = {col,6};
        board[blackPawnPos.ypos][blackPawnPos.xpos].SetPiece(new Pawn(Black, blackPawnPos));

        Position whitePawnPos = {col,1};
        board[whitePawnPos.ypos][blackPawnPos.xpos].SetPiece(new Pawn(White, whitePawnPos));
    }

    
    // Rooks
    Position whiteRookPos = {0,0};
    board[whiteRookPos.ypos][whiteRookPos.xpos].SetPiece(new Rook(White, whiteRookPos));

    Position whiteRookPos2 = {7,0};
    board[whiteRookPos2.ypos][whiteRookPos2.xpos].SetPiece(new Rook(White, whiteRookPos2));
    
    Position blackRookPos = {0,7};
    board[blackRookPos.ypos][blackRookPos.xpos].SetPiece(new Rook(Black, blackRookPos));

    Position blackRookPos2 = {7,7};
    board[blackRookPos2.ypos][blackRookPos2.xpos].SetPiece(new Rook(Black, blackRookPos2));


    // Knights
    Position whiteKnightPos = {1,0};
    board[whiteKnightPos.ypos][whiteKnightPos.xpos].SetPiece(new Knight(White, whiteKnightPos));

    Position whiteKnightPos2 = {6,0};
    board[whiteKnightPos2.ypos][whiteKnightPos2.xpos].SetPiece(new Knight(White, whiteKnightPos2));

    Position blackKnightPos = {1,7};
    board[blackKnightPos.ypos][blackKnightPos.xpos].SetPiece(new Knight(Black, blackKnightPos));

    Position blackKnightPos2 = {6,7};
    board[blackKnightPos2.ypos][blackKnightPos2.xpos].SetPiece(new Knight(Black, blackKnightPos2));

    
    // Bishops
    Position whiteBishopPos = {2,0};
    board[whiteBishopPos.ypos][whiteBishopPos.xpos].SetPiece(new Bishop(White, whiteBishopPos));

    Position whiteBishopPos2 = {5,0};
    board[whiteBishopPos2.ypos][whiteBishopPos2.xpos].SetPiece(new Bishop(White, whiteBishopPos2));

    Position blackBishopPos = {2,7};
    board[blackBishopPos.ypos][blackBishopPos.xpos].SetPiece(new Bishop(Black, blackBishopPos));

    Position blackBishopPos2 = {5,7};
    board[blackBishopPos2.ypos][blackBishopPos2.xpos].SetPiece(new Bishop(Black, blackBishopPos2));

    
    // King
    Position whiteKingPos = {4,0};
    board[whiteKingPos.ypos][whiteKingPos.xpos].SetPiece(new King(White, whiteKingPos));

    Position blackKingPos = {4,7};
    board[blackKingPos.ypos][blackKingPos.xpos].SetPiece(new King(Black, blackKingPos));

    
    // Queens
    Position blackQueenPos = {3,7};
    board[blackQueenPos.ypos][blackQueenPos.xpos].SetPiece(new Queen(Black, blackQueenPos));

    Position blackQueenPos2 = {3,0};
    board[blackQueenPos2.ypos][blackQueenPos2.xpos].SetPiece(new Queen(White, blackQueenPos2));




}

/**@summary Moves a chess piece from one position to another. Validates move.
 * @param fromPos - Starting Position
 * @param toPos - Ending Position
 * @return bool - Success or Failure
 */
Position Board::getKingPosition(Color c) {
	for (int row = 7; row >= 0; row--) {
		    for (int col = 0; col < 8; col++) {
		        BasePiece *currPiece = board[row][col].GetPiece();
		        if (currPiece != NULL) {
	                if (currPiece->GetColor() == c ){
	                	Position p;
	                	p.xpos = col;
	                	p.ypos = row;
	                	if (c == White && (currPiece->getType()=="k")) return p;
	                	if (c == Black && (currPiece->getType()=="K")) return p;
	                }
		        }
		    }
		}
	Position p;
	p.xpos = 0;
	p.ypos = 0;
	return p;
}
bool Board::CheckMate(Color color) {
	bool kingThreat = false;
	Position KingPos = getKingPosition(color);
	Color mateColor;
	if (color == White)
		mateColor=Black;
	else
		mateColor=White;

	for (int row = 7; row >= 0; row--) {
	    for (int col = 0; col < 8; col++) {
	        BasePiece *currPiece = board[row][col].GetPiece();
	        if (currPiece != NULL) {
                if (currPiece->GetColor() == mateColor){
                	Position p;
                	p.xpos = col;
                	p.ypos = row;
                	if (CheckMovePiece(p, KingPos)){
                		kingThreat = true;
                	}
                }
	        }
	    }
	}
	if(kingThreat){
		return true;
	} else{
		return false;
//	Position newKpos;
//	bool yescanscape=false;
//	newKpos.xpos = KingPos.xpos-1;
//	newKpos.ypos = KingPos.ypos;
//	if (CheckMovePiece(KingPos, newKpos)) yescanscape= true;
//
//
//	newKpos.xpos = KingPos.xpos+1;
//	newKpos.ypos = KingPos.ypos;
//	if (CheckMovePiece(KingPos, newKpos)) yescanscape= true;
//
//
//	newKpos.xpos = KingPos.xpos-1;
//	newKpos.ypos = KingPos.ypos-1;
//	if (CheckMovePiece(KingPos, newKpos)) yescanscape= true;
//
//
//	newKpos.xpos = KingPos.xpos+1;
//	newKpos.ypos = KingPos.ypos+1;
//	if (CheckMovePiece(KingPos, newKpos)) yescanscape= true;
//
//	newKpos.xpos = KingPos.xpos-1;
//	newKpos.ypos = KingPos.ypos+1;
//	if (CheckMovePiece(KingPos, newKpos)) yescanscape= true;
//
//	newKpos.xpos = KingPos.xpos+1;
//	newKpos.ypos = KingPos.ypos-1;
//	if (CheckMovePiece(KingPos, newKpos)) yescanscape= true;
//	if(yescanscape){
//		return false;
//	}else{
//		return true;
//	}

	}
}
bool Board::Stalemate(Color color){
	for (int row = 7; row >= 0; row--) {
		    for (int col = 0; col < 8; col++) {
		        BasePiece *currPiece = board[row][col].GetPiece();
		        if (currPiece != NULL) {
	                if (currPiece->GetColor() == color){
	                	Position p;
	                	p.xpos = col;
	                	p.ypos = row;
	                	if (CheckMoveAnyPiece(p)){
	                		return true;
	                	}
	                }
		        }
		    }
		}
return false;

}
bool Board::Insufficient(Color color){
	bool Wking = false;
	bool Bking = false;
	bool Wknight = false;
	bool Bknight = false;
	bool Wbishop = false;
	bool Bbishop = false;
	int counter = 0;
	for (int row = 7; row >= 0; row--) {
		    for (int col = 0; col < 8; col++) {
		        BasePiece *currPiece = board[row][col].GetPiece();
		        if (currPiece!=NULL){
		        	counter ++;
		        	if (currPiece->getType() == "b" && color == White) Wbishop = true;
		        	if (currPiece->getType() == "B" && color == Black) Bbishop = true;
		        	if (currPiece->getType() == "n" && color == White) Wknight = true;
		        	if (currPiece->getType() == "N" && color == Black) Bknight = true;
		        	if (currPiece->getType() == "k" && color == White) Wking = true;
		        	if (currPiece->getType() == "K" && color == Black) Bking = true;
		        }
		    }
	}
	if (counter > 2) return false;
	if (color == White && counter == 1 && Wking) return true;
	if (color == Black && counter == 1 && Bking) return true;
	if (color == White && counter == 1 && Wking && (Wknight || Wbishop)) return true;
	if (color == Black && counter == 1 && Bking && (Bknight || Bbishop)) return true;
	return false;


}
bool Board::CheckMovePiece(Position fromPos, Position toPos) {

    // Return status flag
    bool moveCompleted = false;

    // Get Piece from the square object array (board)
    BasePiece *origPiece = board[fromPos.ypos][fromPos.xpos].GetPiece();

    // Check if we can make this move. Is this a valid move and within the board
    if (origPiece != NULL && (origPiece->ValidateMove(toPos)) && IsWithinBoard(toPos)) {

        moveCompleted = true;
    }

    // Return move status
    return moveCompleted;
}

bool Board::CheckMoveAnyPiece(Position fromPos) {

	for (int row = 7; row >= 0; row--) {
		    for (int col = 0; col < 8; col++) {
		        BasePiece *currPiece = board[row][col].GetPiece();
		        if (currPiece != NULL) {
	                	Position p;
	                	p.xpos = col;
	                	p.ypos = row;
	                	if (CheckMovePiece(fromPos,p)){
	                		return true;
	                	}

		        }
		    }
		}
	return false;
}


bool Board::MovePiece(Position fromPos, Position toPos, bool is_cast ) {

    // Return status flag
    bool moveCompleted = false;

    // Get Piece from the square object array (board)
    BasePiece *origPiece = board[fromPos.ypos][fromPos.xpos].GetPiece();

    // Check if we can make this move. Is this a valid move and within the board
    if (origPiece != NULL && (origPiece->ValidateMove(toPos) || is_cast) && IsWithinBoard(toPos)) {

        // Make the move
        origPiece->SetPosition(toPos);
        board[toPos.ypos][toPos.xpos].SetPiece(origPiece);
        board[fromPos.ypos][fromPos.xpos].Clear();

        moveCompleted = true;
    }

    // Return move status
    return moveCompleted;
}

/**@summary Getter for chessPiece
 * @param Board Position to retrieve piece from
 * @return Pointer to piece
 */
BasePiece* Board::GetPiece(Position piecePos) {
    return board[piecePos.ypos][piecePos.xpos].GetPiece();
}
void Board::MySetPiece(Position piecePos,Color c,string st) {
	if (st=="Q"){
		  board[piecePos.ypos][piecePos.xpos].SetPiece(new Queen(c, piecePos));
	}
	if (st=="R"){
			  board[piecePos.ypos][piecePos.xpos].SetPiece(new Rook(c, piecePos));
		}
	if (st=="N"){
			  board[piecePos.ypos][piecePos.xpos].SetPiece(new Knight(c, piecePos));
		}

	if (st=="B"){
			 board[piecePos.ypos][piecePos.xpos].SetPiece(new Bishop(c, piecePos));
		}

}

/**@summary Check if position is within board boundry
 * @param Piece Position
 * @return bool - Success or Failure
 */
bool Board::IsWithinBoard(Position pos) {

    // Check boundry
    if ((0 <= pos.xpos && pos.xpos <= 7) && (0 <= pos.ypos && pos.ypos <= 7)) {
        return true;
    }

    return false;
}
