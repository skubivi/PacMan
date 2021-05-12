#include "Wall.h"
Wall::Wall(int x,int y,int widht,int height) {
	Wall::x = x;
	Wall::y = y;
	Wall::widht = widht;
	Wall::height = height;
}
Wall::Wall() {

}
void Wall::SetX(int x) {
	Wall::x = x;
}
void Wall::SetY(int y) {
	Wall::y = y;
}
int Wall::GetX() {
	return Wall::x;
}
int Wall::GetY() {
	return Wall::y;
}
void Wall::SetHeight(int height) {
	Wall::height = height;
}
void Wall::SetWidht(int widht) {
	Wall::widht = widht;
}
void Wall::Set(int x, int y, int widht, int height) {
	Wall::x = x;
	Wall::y = y;
	Wall::widht = widht;
	Wall::height = height;
}
int Wall::GetX_R() {
	return Wall::x + Wall::widht - 1;
}
int Wall::GetY_D() {
	return Wall::y + Wall::height - 1;
}