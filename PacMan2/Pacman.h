#pragma once
#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include "Wall.h"

using namespace sf;

class Pacman {
public:
	Pacman(std::string);
	void move();
	void check(Wall);
	Sprite draw();
	void SetX(int);
	int GetX();
	void SetY(int);
	int GetY();
	void plusscore(int, int, bool);
	int GetScore();
	void death();
	int GetLive();
	void b_super();
	int GetSuper();
	void SetSuper(int);
	Sprite spr;
private:
	int super;
	int x;
	int y;
	int vel_x;
	int vel_y;
	int score;
	int lives;
	Image im;
	Texture tex;
};
