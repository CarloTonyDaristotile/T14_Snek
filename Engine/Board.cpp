#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location & loc, Color c, int i)
{
	assert(loc.x >= 0  );
	assert(loc.x < width  );
	assert(loc.y >= 0  );
	assert(loc.y < height  );
	if (i >= dimension/3) {
		i = dimension/3 - 1;
	}
	gfx.DrawRectDimPadded((loc.x )*dimension + left_padding, (loc.y )*dimension + top_padding, dimension, dimension, c, i);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x >= 0   && loc.x < width  &&
		loc.y >= 0   && loc.y < height  ;
}

void Board::DrawBorder()
{
	for (int off = 1; off <= 5; off += 2) 
	{
		// top
		for (int x = left_padding - off; x < left_padding + width*dimension + off; ++x)
		{
			gfx.PutPixel(x, top_padding - off, Colors::Blue);
		}
		//botom
		for (int x = left_padding - off; x < left_padding + width*dimension + off; ++x)
		{
			gfx.PutPixel(x, top_padding + height*dimension + off, Colors::Blue);
		}
		//left
		for (int y = top_padding - off; y < top_padding + height*dimension + off; ++y)
		{
			gfx.PutPixel(left_padding - off, y, Colors::Blue);
		}
		//right
		for (int y = top_padding - off; y < top_padding + height*dimension + off; ++y)
		{
			gfx.PutPixel(left_padding + width*dimension + off, y, Colors::Blue);
		} 
	}
}
