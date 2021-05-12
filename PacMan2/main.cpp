#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "point.h"
#include "Ghost.h"

using namespace sf;

bool isinarr(int arr[300], int e) {
	for (int i = 0; i < sizeof(arr); i++) {
		if (arr[i] == e) {
			return true;
		}
	}
	return false;
}

int main() {
	Clock clock;
	Pacman player("images/Pacman.png");
	Image live_image;
	live_image.loadFromFile("images/Pacman.png");
	Texture live_texture;
	live_texture.loadFromImage(live_image);
	Sprite live_spr1;
	Sprite live_spr2;
	Sprite live_spr3;
	live_spr1.setTexture(live_texture);
	live_spr2.setTexture(live_texture);
	live_spr3.setTexture(live_texture);
	live_spr1.setPosition(1120, 40);
	live_spr2.setPosition(1120, 80);
	live_spr3.setPosition(1120, 120);
	Ghost ghost1("images/Ghost1.png", 11, 13);
	Ghost ghost2("images/Ghost2.png", 16, 13);
	Ghost ghost3("images/Ghost3.png", 11, 17);
	Ghost ghost4("images/Ghost4.png", 16, 17);
	point point_s[240];
	for (int i = 0; i < 240; i++) {
		if (i >= 0 && i <= 11) {
			point_s[i].SetX(i + 1);
			point_s[i].SetY(1);
		}
		else if (i >= 12 && i <= 23) {
			point_s[i].SetX(i+3);
			point_s[i].SetY(1);
		}

		else if (i >=24 && i<= 26) {
			point_s[i].SetX(1);
			point_s[i].SetY(i-22);
		}
		else if (i >= 27 && i <= 29) {
			point_s[i].SetX(6);
			point_s[i].SetY(i - 25);
		}
		else if (i >= 30 && i <= 32) {
			point_s[i].SetX(12);
			point_s[i].SetY(i - 28);
		}
		else if (i >= 33 && i <= 35) {
			point_s[i].SetX(15);
			point_s[i].SetY(i - 31);
		}
		else if (i >= 36 && i <= 38) {
			point_s[i].SetX(21);
			point_s[i].SetY(i - 34);
		}
		else if (i >= 39 && i <= 41) {
			point_s[i].SetX(26);
			point_s[i].SetY(i - 37);
		}
		else if (i >= 42 && i <= 67) {
			point_s[i].SetX(i-41);
			point_s[i].SetY(5);
		}

		else if (i >= 68 && i <= 69) {
			point_s[i].SetX(1);
			point_s[i].SetY(i - 62);
		}
		else if (i >= 70 && i <= 71) {
			point_s[i].SetX(6);
			point_s[i].SetY(i - 64);
		}
		else if (i >= 72 && i <= 73) {
			point_s[i].SetX(9);
			point_s[i].SetY(i - 66);
		}
		else if (i >= 74 && i <= 75) {
			point_s[i].SetX(18);
			point_s[i].SetY(i - 68);
		}
		else if (i >= 76 && i <= 77) {
			point_s[i].SetX(21);
			point_s[i].SetY(i - 70);
		}
		else if (i >= 78 && i <= 79) {
			point_s[i].SetX(26);
			point_s[i].SetY(i - 72);
		}

		else if (i >= 80 && i <= 85) {
			point_s[i].SetX(i - 79);
			point_s[i].SetY(8);
		}
		else if (i >= 86 && i <= 89) {
			point_s[i].SetX(i - 77);
			point_s[i].SetY(8);
		}
		else if (i >= 90 && i <= 93) {
			point_s[i].SetX(i - 75);
			point_s[i].SetY(8);
		}
		else if (i >= 94 && i <= 99) {
			point_s[i].SetX(i - 73);
			point_s[i].SetY(8);
		}

		else if (i >= 100 && i <= 112) {
			point_s[i].SetX(6);
			point_s[i].SetY(i - 91);
		}
		else if (i >= 113 && i <= 125) {
			point_s[i].SetX(21);
			point_s[i].SetY(i - 104);
		}

		else if (i >= 126 && i <= 137) {
			point_s[i].SetX(i-125);
			point_s[i].SetY(22);
		}
		else if (i >= 138 && i <= 149) {
			point_s[i].SetX(i-123);
			point_s[i].SetY(22);
		}

		else if (i >= 150 && i <= 151) {
			point_s[i].SetX(1);
			point_s[i].SetY(i-127);
		}
		else if (i >= 152 && i <= 153) {
			point_s[i].SetX(6);
			point_s[i].SetY(i - 129);
		}
		else if (i >= 154 && i <= 155) {
			point_s[i].SetX(12);
			point_s[i].SetY(i - 131);
		}
		else if (i >= 156 && i <= 157) {
			point_s[i].SetX(15);
			point_s[i].SetY(i - 133);
		}
		else if (i >= 158 && i <= 159) {
			point_s[i].SetX(21);
			point_s[i].SetY(i - 135);
		}
		else if (i >= 160 && i <= 161) {
			point_s[i].SetX(26);
			point_s[i].SetY(i - 137);
		}

		else if (i >= 162 && i <= 164) {
			point_s[i].SetX(i-161);
			point_s[i].SetY(25);
		}
		else if (i >= 165 && i <= 180) {
			point_s[i].SetX(i - 159);
			point_s[i].SetY(25);
		}
		else if (i >= 181 && i <= 183) {
			point_s[i].SetX(i - 157);
			point_s[i].SetY(25);
		}

		else if (i >= 184 && i <= 186) {
			point_s[i].SetX((i - 183) * 3);
			point_s[i].SetY(26);
		}
		else if (i >= 187 && i <= 189) {
			point_s[i].SetX((i - 186) * 3 + 15);
			point_s[i].SetY(26);
		}
		else if (i >= 190 && i <= 195) {
			point_s[i].SetX(i - 189);
			point_s[i].SetY(27);
		}
		else if (i >= 196 && i <= 199) {
			point_s[i].SetX(i - 187);
			point_s[i].SetY(27);
		}
		else if (i >= 200 && i <= 203) {
			point_s[i].SetX(i - 185);
			point_s[i].SetY(27);
		}
		else if (i >= 204 && i <= 209){
			point_s[i].SetX(i - 183);
			point_s[i].SetY(27);
		}
		else if (i == 210) {
			point_s[i].SetX(1);
			point_s[i].SetY(28);
		}
		else if (i == 211) {
			point_s[i].SetX(12);
			point_s[i].SetY(28);
		}
		else if (i == 212) {
			point_s[i].SetX(15);
			point_s[i].SetY(28);
		}
		else if (i == 213) {
			point_s[i].SetX(26);
			point_s[i].SetY(28);
		}
		else if (i >= 214) {
			point_s[i].SetX(i - 213);
			point_s[i].SetY(29);
		}
	}

	Wall w[46];
	w[0].Set(2, 2, 4, 3);
	w[1].Set(7, 2, 5, 3);
	w[2].Set(13, 1, 2, 4);
	w[3].Set(16, 2, 5, 3);
	w[4].Set(22, 2, 4, 3);
	w[5].Set(2, 6, 4, 2);
	w[6].Set(7, 6, 2, 8);
	w[7].Set(10, 6, 8, 2);
	w[8].Set(19, 6, 2, 8);
	w[9].Set(22, 6, 4, 2);
	w[10].Set(9, 9, 3, 2);
	w[11].Set(13, 8, 2, 3);
	w[12].Set(16, 9, 3, 2);
	w[13].Set(1, 9, 5, 6);
	w[14].Set(22, 9, 5, 6);
	w[15].Set(10, 12, 1, 7);
	w[16].Set(11, 12, 2, 1);
	w[17].Set(15, 12, 2, 1);
	w[18].Set(17, 12, 1, 7);
	w[19].Set(11, 18, 6, 1);
	w[20].Set(1, 16, 5, 6);
	w[21].Set(22, 16, 5, 6);
	w[22].Set(7, 17, 2, 5);
	w[23].Set(19, 17, 2, 5);
	w[24].Set(10, 20, 8, 2);
	w[25].Set(13, 22, 2, 3);
	w[26].Set(2, 23, 4, 2);
	w[27].Set(4, 25, 2, 2);
	w[28].Set(7, 23, 5, 2);
	w[29].Set(16, 23, 5, 2);
	w[30].Set(22, 23, 4, 2);
	w[31].Set(22, 25, 2, 2);
	w[32].Set(1, 26, 2, 1);
	w[33].Set(25, 26, 2, 1);
	w[34].Set(2, 28, 10, 1);
	w[35].Set(16, 28, 10, 1);
	w[36].Set(7, 26, 2, 2);
	w[37].Set(19, 26, 2, 2);
	w[38].Set(10, 26, 8, 1);
	w[39].Set(13, 27, 2, 2);
	w[40].Set(0, 0, 31, 1);
	w[41].Set(0, 30, 31, 1);
	w[42].Set(0, 1, 1, 14);
	w[43].Set(0, 16, 1, 14);
	w[44].Set(27, 1, 1, 14);
	w[45].Set(27, 16, 1, 14);


	Image bg;
	bg.loadFromFile("images/bg.png");

	Texture bg_texture;
	bg_texture.loadFromImage(bg);

	Sprite bg_sprite;
	bg_sprite.setTexture(bg_texture);
	
	RenderWindow window(VideoMode(1160, 1240), "Pacman");
	Time TIME = seconds(0.125f);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}

		}
		player.move();
		for (int i = 0; i < 46; i++) {
			player.check(w[i]);
		}
		for (int i = 0; i < 240; i++) {
			player.plusscore(point_s[i].GetX(), point_s[i].GetY(), point_s[i].islive());
		}

		ghost1.move(player, w);
		ghost2.move(player, w);
		ghost3.move(player, w);
		ghost4.move(player, w);

		for (int i = 0; i < 240; i++) {
			if (point_s[i].islive() && player.GetX() == point_s[i].GetX() && player.GetY() == point_s[i].GetY() && (i == 25 || i == 40 || i == 151 || i == 161)) {
				player.b_super();
			}
			point_s[i].death(player);
		}
		if (player.GetSuper() > 0) {
			player.spr.setColor(Color(255, 0, 0));
		}

		if (ghost1.GetX() == player.GetX() && ghost1.GetY() == player.GetY() && player.GetSuper() == 0 && ghost1.GetK() == 0) {
			player.death();
			ghost1.SetX(11);
			ghost1.SetY(13);
			ghost2.SetX(16);
			ghost2.SetY(13);
			ghost3.SetX(11);
			ghost3.SetY(17);
			ghost4.SetX(16);
			ghost4.SetY(17);
		}
		if (ghost2.GetX() == player.GetX() && ghost2.GetY() == player.GetY() && player.GetSuper() == 0 && ghost2.GetK() == 0) {
			player.death();
			ghost1.SetX(11);
			ghost1.SetY(13);
			ghost2.SetX(16);
			ghost2.SetY(13);
			ghost3.SetX(11);
			ghost3.SetY(17);
			ghost4.SetX(16);
			ghost4.SetY(17);
		}
		if (ghost3.GetX() == player.GetX() && ghost3.GetY() == player.GetY() && player.GetSuper() == 0 && ghost3.GetK() == 0) {
			player.death();
			ghost1.SetX(11);
			ghost1.SetY(13);
			ghost2.SetX(16);
			ghost2.SetY(13);
			ghost3.SetX(11);
			ghost3.SetY(17);
			ghost4.SetX(16);
			ghost4.SetY(17);
		}
		if (ghost4.GetX() == player.GetX() && ghost4.GetY() == player.GetY() && player.GetSuper() == 0 && ghost4.GetK() == 0) {
			player.death();
			ghost1.SetX(11);
			ghost1.SetY(13);
			ghost2.SetX(16);
			ghost2.SetY(13);
			ghost3.SetX(11);
			ghost3.SetY(17);
			ghost4.SetX(16);
			ghost4.SetY(17);
		}
		if (player.GetLive() == 0 || player.GetScore() == 240) {
			window.close();
		}

		ghost1.death(player);
		ghost2.death(player);
		ghost3.death(player);
		ghost4.death(player);



		window.clear();
		window.draw(bg_sprite);
		if (ghost1.GetK() == 0) {
			window.draw(ghost1.draw());
		}
		if (ghost2.GetK() == 0) {
			window.draw(ghost2.draw());
		}
		if (ghost3.GetK() == 0) {
			window.draw(ghost3.draw());
		}
		if (ghost4.GetK() == 0) {
			window.draw(ghost4.draw());
		}
		if (player.GetLive() == 3) {
			window.draw(live_spr1);
			window.draw(live_spr2);
			window.draw(live_spr3);
		}
		if (player.GetLive() == 2) {
			window.draw(live_spr1);
			window.draw(live_spr2);
		}
		if (player.GetLive() == 1) {
			window.draw(live_spr1);
		}
		window.draw(player.draw());
		for (int i = 0; i < 240; i++) {
			if (point_s[i].islive()) {
				if (i == 25) { window.draw(point_s[i].draw(10)); }
				else if (i == 40) { window.draw(point_s[i].draw(10)); }
				else if (i == 151) { window.draw(point_s[i].draw(10)); }
				else if (i == 161) { window.draw(point_s[i].draw(10)); }
				else window.draw(point_s[i].draw(5));
			};
		}
		window.display();
		if (player.GetSuper() > 0) {
			player.SetSuper(player.GetSuper() - 1);
		}
		if (player.GetSuper() == 0) {
			player.spr.setColor(Color(255, 255, 255));
		}
		if (ghost1.GetK() > 0) {
			ghost1.K_m();
			if (ghost1.GetK() == 0) {
				ghost1.SetLive();
				ghost1.SetX(11);
				ghost1.SetY(13);
			}
		}
		if (ghost2.GetK() > 0) {
			ghost2.K_m();
			if (ghost2.GetK() == 0) {
				ghost2.SetLive();
				ghost2.SetX(16);
				ghost2.SetY(13);
			}
		}
		if (ghost3.GetK() > 0) {
			ghost3.K_m();
			if (ghost3.GetK() == 0) {
				ghost3.SetLive();
				ghost3.SetX(11);
				ghost3.SetY(17);
			}
		}
		if (ghost4.GetK() > 0) {
			ghost4.K_m();
			if (ghost4.GetK() == 0) {
				ghost4.SetLive();
				ghost4.SetX(16);
				ghost4.SetY(17);
			}
		}
		sleep(TIME);
	}
	std::cout << player.GetScore();
	TIME = seconds(2.0f);
	sleep(TIME);
	return 0;

}