#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; --i)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody();
		++nSegments;
	}
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].Draw(brd,i );
	}
}

bool Snake::IsInTile(const Location& target) const
{
	// check if head matches any part of snake
	for (int i = 0; i < nSegments; ++i)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IsInTileExceptEnd(const Location& target) const
{
	// check if head matches any part of snake
	for (int i = 0; i < nSegments -1; ++i)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc; // will copy over data values .x .y
	c = Snake::headColor; // can access privte since inside of Snake
}

void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd, int i) const
{
	if (i > 0) {
		int k = i % 6;
		int red, green, blue;
		red = ( k <= 2 || k == 4 )? 255 : 0;
		green = ( k == 2 || k == 3 || k == 4 || k == 5 ) ? 255 : 0;
		blue = ( k == 5 || k == 6 ) ? 255 : 0;
		Color newc(red, green, blue);
		brd.DrawCell(loc, newc, i);
	} 
	else
	{
		brd.DrawCell(loc, c, i);
	}
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
