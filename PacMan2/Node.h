#pragma once
class Node
{
public:
	Node();
	Node(int, int);
	Node(Node, int, int);
	bool check(Node);
	int x_p;
	int y_p;
	int x;
	int y;
	int g;
	int h;
	int f;
	int* neighbours();
	void copy(Node);
	int* GetXY();
};

