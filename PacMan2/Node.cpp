#include "Node.h"
Node::Node(int x, int y) {
	Node::x = x;
	Node::y = y;
	Node::f = 0;
	Node::g = 0;
	Node::h = 0;
	Node::x_p = -1;
	Node::y_p = -1;
}
Node::Node(Node parent, int x, int y) {
	Node::x = x;
	Node::y = y;
	Node::f = 0;
	Node::g = 0;
	Node::h = 0;
	Node::x_p = parent.x;
	Node::y_p = parent.y;
}
bool Node::check(Node other) {
	return (Node::x == other.x && Node::y == other.y);
}
int* Node::neighbours() {
	int arr[8];
	arr[0] = Node::x+1;
	arr[1] = Node::y;
	arr[2] = Node::x;
	arr[3] = Node::y+1;
	arr[4] = Node::x-1;
	arr[5] = Node::y;
	arr[6] = Node::x;
	arr[7] = Node::y-1;
	return arr;
}
Node::Node() {
	Node::x = -1;
	Node::y = -1;
	Node::f = 0;
	Node::g = 0;
	Node::h = 0;
	Node::x_p = -1;
	Node::y_p = -1;
}
void Node::copy(Node other) {
	Node::x = other.x;
	Node::y = other.y;
	Node::x_p = other.x_p;
	Node::y_p = other.y_p;
	Node::f = other.f;
	Node::h = other.h;
	Node::g = other.g;
}
int* Node::GetXY() {
	int arr[2];
	arr[1] = Node::x;
	arr[2] = Node::y;
	return arr;
}