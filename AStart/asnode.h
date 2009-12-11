/*
 *
 *  Portions Copyright (C) 2009 wind (xihels@gmail.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef _ASNODE_H_
#define _ASNODE_H_

#include <stdio.h>
#include <set>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

struct Index {
	Index(int x_, int y_): x(x_), y(y_){}
	bool operator == (const Index& other) const { return x == other.x && y == other.y; }
	int x;
	int y;
};

struct hash_index {
	size_t operator() (const Index& o) const { return (o.x << 16 | o.y); }
};

struct ASNode {
	ASNode() : parent(0), x(0), y(0), f(0), g(0), h(0) {}
	ASNode(int _x, int _y) : parent(0), x(_x), y(_y), f(0), g(0), h(0) {}
	//TOpenList::iterator iter;
	ASNode* parent;
	int x;
	int y;

	int f;
	int g;
	int h;
};


struct ASNodeFComp : binary_function <const ASNode*, const ASNode*, bool> {
	bool operator () (const ASNode* p1, const ASNode* p2) const  { return p1->f < p2->f;}
};

typedef multiset<ASNode*, ASNodeFComp> TOpenList;


typedef unordered_map<Index, ASNode*, hash_index> TCloseIndex;
typedef unordered_map<Index, TOpenList::iterator, hash_index> TOpenIndex;
class ASFinder {
public:
	~ASFinder(); 
	typedef bool (*TCHECKMAPFUN)(int x, int y);
	ASNode* find(int x1, int y1, int x2, int y2,  TCHECKMAPFUN fun);
protected:
	int def_as_func(int x1, int y1, int x2, int y2) { return abs( x2 - x1 ) * 8 + abs( y2 - y1 ) * 16;  }
	bool check_child(int x, int y, int f, ASNode* parent);
private:
	TCHECKMAPFUN check_map_fun;

	TOpenList	open_list; 
	TOpenIndex  open_index;
	TCloseIndex	closed_index; 
	int end_x;
	int end_y;
};

#endif // _ASNODE_H_
