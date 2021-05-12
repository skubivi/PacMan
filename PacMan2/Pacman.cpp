#include "Pacman.h"

Pacman::Pacman(std::string image) {
	Pacman::im.loadFromFile(image);
	Pacman::tex.loadFromImage(Pacman::im);
	Pacman::spr.setTexture(Pacman::tex);
	spr.setPosition(520, 1000);
	Pacman::score = 0;
	Pacman::vel_x = 0;
	Pacman::vel_y = 0;
	Pacman::x = 13;
	Pacman::y = 25;
	lives = 3;
	super = 0;
}

void Pacman::SetX(int x) {
	Pacman::x = x;
}

void Pacman::SetY(int y) {
	Pacman::y = y;
}

int Pacman::GetX() {
	return Pacman::x;
}

int Pacman::GetY() {
	return Pacman::y;
}
void Pacman::death() {
	lives--;
	x = 13;
	y = 25;
}

void Pacman::move() {
	if (Keyboard::isKeyPressed(Keyboard::A)) { Pacman::vel_x = -1; vel_y = 0; Pacman::spr.setRotation(180.0f);}
	else if (Keyboard::isKeyPressed(Keyboard::S)) { Pacman::vel_y = 1; vel_x = 0; Pacman::spr.setRotation(90.0f);}
	else if (Keyboard::isKeyPressed(Keyboard::W)) { Pacman::vel_y = -1; vel_x = 0; Pacman::spr.setRotation(270.0f);}
	else if (Keyboard::isKeyPressed(Keyboard::D)) { Pacman::vel_x = 1; vel_y = 0; Pacman::spr.setRotation(0.0f);};
	Pacman::x += vel_x;
	Pacman::y += vel_y;
	if (Pacman::x >= 28) {
		Pacman::x -= 28;
	}
	if (Pacman::x < 0) {
		Pacman::x += 28;
	}
}

void Pacman::check(Wall w) {
	if (Pacman::x == w.GetX() && vel_x == 1 && Pacman::y >= w.GetY() && Pacman::y <= w.GetY_D()) {
		Pacman::x--;
	}
	else if (Pacman::x == w.GetX_R() && vel_x == -1 && Pacman::y >= w.GetY() && Pacman::y <= w.GetY_D()) {
		x++;
	}
	else if (Pacman::y == w.GetY() && vel_y == 1 && Pacman::x >= w.GetX() && Pacman::x <= w.GetX_R()) {
		y--;
	}
	else if (Pacman::y == w.GetY_D() && vel_y == -1 && Pacman::x >= w.GetX() && Pacman::x <= w.GetX_R()) {
		y++;
	}
}

Sprite Pacman::draw() {
	
	if (vel_x == 1) {
		Pacman::spr.setPosition(x * 40, y * 40);
	}
	if (vel_x == -1) {
		Pacman::spr.setPosition(x * 40 + 40, y * 40 + 40);
	}
	if (vel_y == -1) {
		Pacman::spr.setPosition(x * 40, y * 40 + 40);
	}
	if (vel_y == 1) {
		Pacman::spr.setPosition(x * 40 + 40, y * 40);
	}
	return Pacman::spr;
}

void Pacman::plusscore(int x, int y, bool p) {
	if (Pacman::x == x && Pacman::y == y and p) {
		Pacman::score++;
	}
}

int Pacman::GetScore() {
	return Pacman::score;
}

int Pacman::GetLive() {
	return Pacman::lives;
}
void Pacman::b_super() {
	Pacman::super = 30;
}
int Pacman::GetSuper() {
	return Pacman::super;
}
void Pacman::SetSuper(int u) {
	Pacman::super = u;
}