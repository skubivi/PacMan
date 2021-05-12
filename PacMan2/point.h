#pragma once
#include "Pacman.h"
#include <SFML/Graphics.hpp>

class point
{
public:
	point(int, int);
	point();
	void death(Pacman);
	CircleShape draw(int);
	bool islive();
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
private:
	int x;
	int y;
	bool live;
	CircleShape circle;
};

