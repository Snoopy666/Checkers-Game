#ifndef CHECKERSSTATE_H
#define CHECKERSSTATE_H

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstdint>
#include <stdint.h>

typedef unsigned char uint8;
typedef unsigned int uint;

enum checker {
    WHITE = 1,
    BLACK = 2,
    WHITEKING = 3,
    BLACKKING = 4,
    WHITECELL = 10,

    MOVEDFROM = 20,
    MOVEDTO = 21,
    MOVEDTHROUGH = 22,
    DELETED = 23,
    MARKDELETED = 24,
    TOKING = 25
};

class point {
public:
	point() {
		x=0; y=0; type=0;
	}
	point(int x, int y, int type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}
    int x;
    int y;
    int type;
bool operator == (const point & p ) {
		if( x==p.x && y==p.y && type==p.type )
			return true;
		return false;
	}
};

class CheckersState
{
public:
    CheckersState();
    CheckersState(int size);
	~CheckersState();
	CheckersState(const CheckersState &source);
	CheckersState(const CheckersState *source);

    CheckersState * genNextState(std::vector <point> & v);	// 从当前产生新状态
                                                            // 接受向量作为参数
	void setParent(CheckersState * parent);
    //void calcCounts();										// 计数
	std::vector <uint8> & counts();
	CheckersState * parent();
	std::vector < CheckersState * > & childs();
	std::vector < point > & move();
    int & deletedAtMove();									//
	int & score();
	void print();
	uint8 size();
	uint8 & at(uint8 i, uint8 j);
	uint8 color(uint i, uint j);
	bool isWhite(uint8 i, uint8 j);
	bool isBlack(uint8 i, uint8 j);
	bool isKing(uint8 i, uint8 j);
	bool isNull(uint8 i, uint8 j);
private:
	CheckersState * p;
	std::vector < CheckersState * > xchilds;
    std::vector < point > xmove;								// 移动描述
    std::vector < uint8 > xcounts;								// 不同类型数量
	void allocate(uint8 size);
	uint8 ** data;
	uint8 n;
	uint8 tmp;
	int xscore;
	int deletedatmove;
};

#endif // CHECKERSSTATE_H
