

#ifndef _BASEPIECE_H
#define	_BASEPIECE_H

#include <string>       // Included for String return types

// Foward Decleration since Board will be defined in a later include
class Board;

// Enumeration for Color of pieces
enum Color {
    Black,
    White
};

// Struct defining Position of Pieces
typedef struct Coordinates {
    int xpos;
    int ypos;
} Position;

// Class definition
class BasePiece {


public:
    // Constructors
    BasePiece();
    virtual ~BasePiece();

    // Public functions
    void Draw();
    void SetPosition(Position pos);
    Position GetPosition();
    Color GetColor();
    virtual bool ValidateMove(Position moveToPosition) = 0;

	Color getColor() const {
		return color;
	}

	void setColor(Color color) {
		this->color = color;
	}

	const Position& getPos() const {
		return pos;
	}

	void setPos(const Position &pos) {
		this->pos = pos;
	}

	const std::string& getType() const {
		return type;
	}

	void setType(const std::string &type) {
		this->type = type;
	}

private:

protected:
    std::string type;
    Color color;
    Position pos;

};

#endif	/* _BASEPIECE_H */
