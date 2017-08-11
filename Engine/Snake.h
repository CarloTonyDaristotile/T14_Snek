#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody();  
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd, int i) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTile(const Location & target) const;
	bool IsInTileExceptEnd(const Location& target) const;
	int GetSnekMovePeriod() const
	{
		return snekMovePeriod;
	}
	int GetSnekMoveCounter() const
	{
		return snekMoveCounter;
	}
	void ResetMoveCounter()
	{
		snekMoveCounter = 0;
	}
	void IncreaseMoveCounter()
	{
		snekMoveCounter ++;
	}
	void DecreaseMovePeriod() {
		if (snekMovePeriod > 1) 
		{
			snekMovePeriod--;
		}
	}
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	int snekMovePeriod = 20;
	int snekMoveCounter = 0;
};