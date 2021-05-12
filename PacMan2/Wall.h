#pragma once
class Wall
{
public:
	Wall(int, int, int, int);
	Wall();
	int GetX();
	int GetY();
	int GetX_R();
	int GetY_D();
	void SetHeight(int);
	void SetWidht(int);
	void SetX(int);
	void SetY(int);
	void Set(int, int, int, int);
private:
	int x;
	int y;
	int height;
	int widht;
};

