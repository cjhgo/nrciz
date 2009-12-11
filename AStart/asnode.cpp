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


#include "asnode.h"



ASFinder::~ASFinder()
{
	TOpenList::iterator iter = open_list.begin();
	for (; iter != open_list.end(); ++iter)
		delete *iter;

	TCloseIndex::iterator i = closed_index.begin();
	for (; i != closed_index.end(); ++i)
		delete (*i).second;
}

ASNode* ASFinder::find(int x1, int y1, int x2, int y2, TCHECKMAPFUN fun)
{
	check_map_fun = fun;
	end_x = x2;
	end_y = y2;

	ASNode* start_node = new ASNode(x1, y1);
	TOpenList::iterator iter = open_list.insert(start_node);
	open_index[Index(x1, y1)] = iter;

	for (int i = 0; i < 200000 && !open_list.empty(); i++)
	{
		ASNode* node = *(open_list.begin());
		open_list.erase(open_list.begin());
		open_index.erase(Index(node->x, node->y));

		closed_index[Index(node->x, node->y)] = node;
		

		int x = node->x;
		int y = node->y;

		if (x == end_x && y == end_y)
			return node;

		// 測試八個鄰近child的屬性
		bool ret = false;
		for ( int f = 0; f < 8; f++)
		{
			ret |= check_child(x, y, f, node);
		}
// 		ret |= check_child(x, y - 1, node);     
// 		ret |= check_child(x + 2, y - 1, node);  
// 		ret |= check_child(x + 2, y, node);  
// 		ret |= check_child(x + 2, y + 1, node);  
// 		ret |= check_child(x, y + 1, node);  
// 		ret |= check_child(x - 2, y + 1, node);  
// 		ret |= check_child(x - 2, y, node);  
// 		ret |= check_child(x - 2, y - 1, node);  
		if (!ret)
		{
			TCloseIndex::iterator iter = closed_index.find(Index(node->x, node->y));
			if (iter != closed_index.end())
			{
				delete (*iter).second;
				closed_index.erase(iter);
			}
		}
	}

    return NULL;
}


bool ASFinder::check_child(int x, int y, int f, ASNode* parent)
{

	switch (f)
	{
	case 0:
		y--;
		break;
	case 1:
		x++;
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		x++;
		y++;
		break;
	case 4:
		y++;
		break;
	case 5:
		x--;
		y++;
		break;
	case 6:
		x--;
		break;
	case 7:
		x--;
		y--;
		break;
	}

	if (check_map_fun(x, y))
		return false;

	int g;   // 经你节点到达 (x, y) 处的代价
	
	if (parent->x != x && parent->y !=y )   
        g = parent->g + 14;   
    else    // 否则 child 和 parent 处于水平或垂直位置上
        g = parent->g + 10;   

	if (closed_index.end() != closed_index.find( Index(x, y) ))
		return false;

	TOpenIndex::iterator iter;
	if  ( open_index.end() == (iter = open_index.find( Index(x, y ) ) ) )
	{
		ASNode* new_node = new ASNode(x, y);
		new_node->g = g;   
        new_node->h = def_as_func(x, y, end_x, end_y);   
        new_node->f = new_node->g + new_node->h; 
		new_node->parent = parent;

		TOpenList::iterator iiter = open_list.insert(new_node);

		open_index[Index(x, y)] = iiter;
	}
	else
	{
		
		TOpenList::iterator iiter = (*iter).second;
		ASNode* p = *iiter;
		if (g < p->g)   
		{  
			p->parent = parent;   
			p->g = g;   
			p->f = p->g + p->h; 
			
			open_list.erase(iiter);
			iiter = open_list.insert(p);
			open_index[Index(x, y)] = iiter;
		}   
		
	}
	
	return true;
}
