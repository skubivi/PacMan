#pragma once
#include"Pacman.h"
#include<vector>
#include"Node.h"

class Ghost
{
public:
	Ghost(std::string, int, int);
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
	int heuristic(int, int, int, int);
	int AStar(Pacman, Wall*);
	void move(Pacman, Wall*);
	Sprite draw();
	void death(Pacman);
	int GetK();
	void K_m();
	void SetLive();
private:
	int x;
	int y;
	bool live;
	int k;
	Sprite spr;
	Texture tex;
	Image img;
};

