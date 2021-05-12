#include "point.h"

point::point(int x, int y) {
	point::x = x;
	point::y = y;
	point::live = true;
}
point::point() {
	point::x = x;
	point::y = y;
	point::live = true;
}
void point::death(Pacman player) {
	if (point::x == player.GetX() && point::y == player.GetY() && point::live) {
		point::live = false;
	}
}
bool point::islive() {
	return point::live;
}
CircleShape point::draw(int r) {
	point::circle.setFillColor(Color(255, 255, 0));
	point::circle.setRadius(r);
	point::circle.setPosition(point::x * 40 + 13, point::y * 40 + 13);
	return point::circle;
}	
int point::GetX() {
	return point::x;
}
int point::GetY() {
	return point::y;
}
void point::SetX(int x) {
	point::x = x;
}
void point::SetY(int y) {
	point::y = y;
}