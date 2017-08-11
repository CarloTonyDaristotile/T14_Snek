#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c, int i);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	void DrawBorder();
private:
	static constexpr int dimension = 20; // compile time constant
	static constexpr int width = 25;
	static constexpr int height = 25;
	static constexpr int left_padding = 13;
	static constexpr int top_padding = 7;
	Graphics& gfx; 
};