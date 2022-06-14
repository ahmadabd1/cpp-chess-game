
#include "BasePiece.h"      // For BasePiece Class
#include <iostream>         // For writing to screen
#include <string>           // For string datatype
#include <algorithm>
#include <cctype>
#include <string>
#include "Board.h" 
using namespace std;        // declare namespace to eliminate need for std::

/**@summary Default Constructor
 */

BasePiece::BasePiece() : color(White) {
    type = " ";
}

/**@summary Default Destructor
 */
BasePiece::~BasePiece() {
}

/**@summary Draws the chess piece to the screen
 * @return void
 */
void BasePiece::Draw() {

    
    if (color == Black) {
        cout << type;
    }
    else {
            cout<<(char)tolower(type[0]);
        
    }
    
    
}

/**@summary Updates the position for the chess piece
 * @param pos - New posisition
 * @return void
 */
void BasePiece::SetPosition(Position pos) {

    this->pos = pos;
        
}

Position BasePiece::GetPosition()
{
    return Position();
}

/**@summary Gets the current color of piece
 * @return Color
 */
Color BasePiece::GetColor() {

		return color;
}
