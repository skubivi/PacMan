#include "Ghost.h"

Ghost::Ghost(std::string image_g, int x, int y) {
	Ghost::x = x;
	Ghost::y = y;
	Ghost::img.loadFromFile(image_g);
	Ghost::tex.loadFromImage(Ghost::img);
	Ghost::spr.setTexture(Ghost::tex);
	Ghost::live = true;
	Ghost::k = 0;
}
int Ghost::GetX() {
	return Ghost::x;
}
int Ghost::GetY() {
	return Ghost::y;
}
void Ghost::SetX(int x) {
	Ghost::x = x;
}
void Ghost::SetY(int y) {
	Ghost::y = y;
}
int Ghost::heuristic(int x1, int y1, int x2, int y2) {
	return(abs(x1 - x2) + abs(y1 - y2));
}
int Ghost::AStar(Pacman p, Wall* w) {
	std::vector<Node>list;
	std::vector<Node>visited;
	std::vector<Node>list1;
	std::vector<Node>list2;
	list.push_back(Node(Ghost::x, Ghost::y));
	int x1 = -1;
	int y1 = -1;
	int x2 = -1;
	int y2 = -1;
	while (true)
	{
		int min = 10000;
		int j = -1;
		for (int i = 0; i < list.size(); i++) {
			if (list[i].f < min) {
				min = list[i].f;
				j = i;
			}
		}
		Node current(list[j].x,list[j].y);
		current.x_p = list[j].x_p;
		current.y_p = list[j].y_p;
		current.f = list[j].f;
		current.g = list[j].g;
		current.h = list[j].h;

		visited.push_back(Node(current.x, current.y));
		visited[visited.size() - 1].f = current.f;
		visited[visited.size() - 1].g = current.g;
		visited[visited.size() - 1].h = current.h;
		visited[visited.size() - 1].x_p = current.x_p;
		visited[visited.size() - 1].y_p = current.y_p;
		if (current.x == p.GetX() && current.y == p.GetY()) {
			x1 = current.x_p;
			y1 = current.y_p;
			x2 = current.x;
			y2 = current.y;
			break;
		}
		for (int i = 0; i < j; i++) {
			list1.push_back(list[i]);
		}
		for (int i = j + 1; i < list.size(); i++) {
			list2.push_back(list[i]);
		}
		list.clear();
		for (int i = 0; i < list1.size(); i++) {
			list.push_back(list1[i]);
		}
		for (int i = 0; i < list2.size(); i++) {
			list.push_back(list2[i]);
		}
		list1.clear();
		list2.clear();

		for (int i = 0; i < 4; i++) {
			bool check = true;
			bool check2 = true;
			int neighbour1;
			int neighbour2;
			if (i == 0) {
				neighbour1 = current.x + 1;
				neighbour2 = current.y;
			}
			if (i == 1) {
				neighbour1 = current.x;
				neighbour2 = current.y + 1;
			}
			if (i == 2) {
				neighbour1 = current.x - 1;
				neighbour2 = current.y;
			}
			if (i == 3) {
				neighbour1 = current.x;
				neighbour2 = current.y - 1;
			}
			for (int j = 0; j < visited.size(); j++) {
				if (visited[j].x == neighbour1 && visited[j].y == neighbour2) {
					check = false;
					break;
				}
			}
			for (int j = 0; j < 46; j++) {
				if (neighbour1 >= w[j].GetX() && neighbour1 <= w[j].GetX_R()) {
					if (neighbour2 >= w[j].GetY() && neighbour2 <= w[j].GetY_D()) {
						check = false;
						break;
					}
				}
			}
			if (check) {
				for (int j = 0; j < list.size(); j++) {
					if (list[j].x == neighbour1 && list[j].y == neighbour2) {
						check2 = false;
						int k = j;
						break;
					}
				}
				if (check2) {
					list.push_back(Node(neighbour1, neighbour2));
					list[list.size() - 1].h = heuristic(neighbour1, neighbour2, p.GetX(), p.GetY());
					list[list.size() - 1].g = current.g + 1;
					list[list.size() - 1].f = list[list.size() - 1].g + list[list.size() - 1].h;
					list[list.size() - 1].x_p = current.x;
					list[list.size() - 1].y_p = current.y;
				}
				else {
					if (list[k].g > current.g + 1) {
						list[k].g = current.g + 1;
						list[k].f = list[k].g + list[k].h;
						list[k].x_p = current.x;
						list[k].y_p = current.y;
					}
				}
			}
		}
	}
	std::vector<Node>path(2);
	path[0].x = x2;
	path[0].x_p = x1;
	path[0].y = y2;
	path[0].y_p = y1;
	int k = 0;
	for (int i = 0; i < visited.size(); i++) {
		if (x1 == visited[i].x && y1 == visited[i].y) {
			path[1].x = x1;
			path[1].y = y1;
			path[1].x_p = visited[i].x_p;
			path[1].y_p = visited[i].y_p;
			k = i;
			break;
		}
	}
	while (true) {
		for (int i = 0; i < visited.size(); i++) {
			if (visited[k].x_p == visited[i].x && visited[k].y_p == visited[i].y) {
				path.push_back(visited[i]);
				path[path.size() - 1].x_p = visited[i].x_p;
				path[path.size() - 1].y_p = visited[i].y_p;
				k = i;
				break;
			}
		}
		if (visited[k].x_p == -1) {
			break;
		}
	}
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i].x_p);
	}
	visited.clear();
	list.clear();
	list1.clear();
	list2.clear();
	if (path[path.size() - 2].x == Ghost::x + 1 && path[path.size() - 2].y == Ghost::y) {
		path.clear();
		return 1;
	}
	else if (path[path.size() - 2].x == Ghost::x && path[path.size() - 2].y == Ghost::y + 1) {
		path.clear();
		return 2;
	}
	else if (path[path.size() - 2].x == Ghost::x - 1 && path[path.size() - 2].y == Ghost::y) {
		path.clear();
		return 3;
	}
	else if (path[path.size() - 2].x == Ghost::x && path[path.size() - 2].y == Ghost::y - 1) {
		path.clear();
		return 4;
	}
	else return 0;
}

void Ghost::move(Pacman p, Wall* w) {
	if (Ghost::live) {
		int i = Ghost::AStar(p, w);
		if (i == 1 && p.GetSuper() == 0) {
			Ghost::x++;
		}
		else if (i == 1 && p.GetSuper() > 0) {
			bool check = 1;
			bool check2 = 1;
			for (int j = 0; j < 46; j++) {
				if (Ghost::x-1 == w[j].GetX_R() && Ghost::y >= w[j].GetY() && Ghost::y <= w[j].GetY_D()) {
					check = 0;
					break;
				}
			}
			if (check) {
				Ghost::x--;
			}
			else {
				for (int j = 0; j < 46; j++) {
					if (Ghost::y-1 == w[j].GetY_D() && Ghost::x >= w[j].GetX() && Ghost::x <= w[j].GetX_R()) {
						check2 = 0;
						break;
					}
				}
				if (check2) {
					Ghost::y--;
				}
				else {
					Ghost::y++;
				}
			}
		}
		if (i == 2 && p.GetSuper() == 0) {
			Ghost::y++;
		}
		else if (i == 2 && p.GetSuper() > 0) {
			bool check = 1;
			bool check2 = 1;
			for (int j = 0; j < 46; j++) {
				if (Ghost::y-1 == w[j].GetY_D() && Ghost::x >= w[j].GetX() && Ghost::x <= w[j].GetX_R()) {
					check = 0;
					break;
				}
			}
			if (check) {
				Ghost::y--;
			}
			else {
				for (int j = 0; j < 46; j++) {
					if (Ghost::x-1 == w[j].GetX_R() && Ghost::y >= w[j].GetY() && Ghost::y <= w[j].GetY_D()) {
						check2 = 0;
						break;
					}
				}
				if (check2) {
					Ghost::x--;
				}
				else {
					Ghost::x++;
				}
			}
		}
		if (i == 3 && p.GetSuper() == 0) {
			Ghost::x--;
		}
		else if (i == 3 && p.GetSuper() > 0) {
			bool check = 1;
			bool check2 = 1;
			for (int j = 0; j < 46; j++) {
				if (Ghost::x+1 == w[j].GetX() && Ghost::y >= w[j].GetY() && Ghost::y <= w[j].GetY_D()) {
					check = 0;
					break;
				}
			}
			if (check) {
				Ghost::x++;
			}
			else {
				for (int j = 0; j < 46; j++) {
					if (Ghost::y-1 == w[j].GetY_D() && Ghost::x >= w[j].GetX() && Ghost::x <= w[j].GetX_R()) {
						check2 = 0;
						break;
					}
				}
				if (check2) {
					Ghost::y--;
				}
				else {
					Ghost::y++;
				}
			}
		}
		if (i == 4 && p.GetSuper() == 0) {
			Ghost::y--;
		}
		else if (i == 4 && p.GetSuper() > 0) {
			bool check = 1;
			bool check2 = 1;
			for (int j = 0; j < 46; j++) {
				if (Ghost::y+1 == w[j].GetY() && Ghost::x >= w[j].GetX() && Ghost::x <= w[j].GetX_R()) {
					check = 0;
					break;
				}
			}
			if (check) {
				Ghost::y++;
			}
			else {
				for (int j = 0; j < 46; j++) {
					if (Ghost::x-1 == w[j].GetX_R() && Ghost::y >= w[j].GetY() && Ghost::y <= w[j].GetY_D()) {
						check2 = 0;
						break;
					}
				}
				if (check2) {
					Ghost::x--;
				}
				else {
					Ghost::x++;
				}
			}
		}
	}
}

void Ghost::death(Pacman p) {
	if (p.GetSuper() > 0 && p.GetX() == Ghost::x && p.GetY() == Ghost::y) {
		k = 30;
		live = false;
	}
}

Sprite Ghost::draw() {
	spr.setPosition(Ghost::x * 40, Ghost::y * 40);
	return spr;
}

int Ghost::GetK() {
	return Ghost::k;
}

void Ghost::K_m() {
	k--;
}

void Ghost::SetLive() {
	Ghost::live = true;
}