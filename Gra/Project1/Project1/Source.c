
#include "allegro5\allegro.h"
#include "allegro5\allegro_primitives.h"
#include "allegro5\keyboard.h"
#include "allegro5\mouse.h"
#include "allegro5\timer.h"
#include "allegro5\allegro_native_dialog.h"
#include "allegro5\allegro_font.h"
#include "allegro5\allegro_ttf.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_acodec.h"
#include <stdlib.h>

enum KEYS { UP, DOWN, LEFT, RIGHT, W, S, A, D };

int main(void)
{
	
	int widht = 1000;
	int height = 700;

	bool done = false;
	bool draw = true;
	int pos_x = NULL;
	int pos_y = NULL;

	float czas = 0;

	//  Wgranie
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *gameo = NULL;
	ALLEGRO_BITMAP *fondo1 = NULL;
	ALLEGRO_BITMAP *fondo2 = NULL;
	ALLEGRO_BITMAP *fondo3 = NULL;
	ALLEGRO_BITMAP *fondo4 = NULL;
	ALLEGRO_BITMAP *fondo5 = NULL;
	ALLEGRO_BITMAP *cursor = NULL;
	ALLEGRO_BITMAP *gracz = NULL;
	ALLEGRO_BITMAP *ranking = NULL;
	ALLEGRO_BITMAP *gracz0 = NULL;
	ALLEGRO_BITMAP *gracz1 = NULL;
	ALLEGRO_BITMAP *gracz2 = NULL;
	ALLEGRO_BITMAP *mur = NULL;
	ALLEGRO_BITMAP *grafikaopcja = NULL;
	ALLEGRO_BITMAP *grafikaopcja2 = NULL;
	ALLEGRO_BITMAP *grafikaopcja3 = NULL;
	ALLEGRO_BITMAP *grafikainstrukcja = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_BITMAP *informacja1 = NULL;
	ALLEGRO_BITMAP *informacja2 = NULL;

	const int FPS = 60;


	bool keys[8] = { false, false, false, false, false, false, false, false };

	if (!al_init())
		return -1;


	display = al_create_display(widht, height);
	timer = al_create_timer(1.0 / FPS);

	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();
	al_install_mouse();

	al_reserve_samples(1);

	sample = al_load_sample("music1.ogg");

	event_queue = al_create_event_queue();


	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
	
	ALLEGRO_FONT * czcionka = al_load_ttf_font("do.ttf", 16, 0); 

	// Bitmapy
	fondo1 = al_load_bitmap("grafiki/menu/menu.bmp");
	al_convert_mask_to_alpha(fondo1, al_map_rgb(255, 0, 255));
	fondo2 = al_load_bitmap("grafiki/menu/menu1.bmp");
	al_convert_mask_to_alpha(fondo2, al_map_rgb(255, 0, 255));
	fondo3 = al_load_bitmap("grafiki/menu/menu2.bmp");
	al_convert_mask_to_alpha(fondo3, al_map_rgb(255, 0, 255));
	fondo4 = al_load_bitmap("grafiki/menu/menu3.bmp");
	al_convert_mask_to_alpha(fondo4, al_map_rgb(255, 0, 255));
	fondo5 = al_load_bitmap("grafiki/menu/menu4.bmp");
	al_convert_mask_to_alpha(fondo5, al_map_rgb(255, 0, 255));
	cursor = al_load_bitmap("cursor.bmp");
	al_convert_mask_to_alpha(cursor, al_map_rgb(255, 0, 255));
	gracz = al_load_bitmap("grafiki/postacie/postacprzod.png");
	al_convert_mask_to_alpha(gracz, al_map_rgb(255, 0, 255));
    gracz0 = al_load_bitmap("grafiki/postacie/postacprawo.png");
	al_convert_mask_to_alpha(gracz0, al_map_rgb(255, 0, 255));
    gracz1 = al_load_bitmap("grafiki/postacie/postactyl.png");
	al_convert_mask_to_alpha(gracz1, al_map_rgb(255, 0, 255));
    gracz2 = al_load_bitmap("grafiki/postacie/postaclewo.png");
	al_convert_mask_to_alpha(gracz2, al_map_rgb(255, 0, 255));
	mur = al_load_bitmap("grafika\\bloczki\\mur.pcx");

	grafikaopcja = al_load_bitmap("grafiki/menu/opcje.bmp");
	al_convert_mask_to_alpha(fondo1, al_map_rgb(255, 0, 255));
	grafikaopcja2 = al_load_bitmap("grafiki/menu/opcje2.bmp");
	al_convert_mask_to_alpha(fondo1, al_map_rgb(255, 0, 255));
	grafikaopcja3 = al_load_bitmap("grafiki/menu/opcje3.bmp");
	al_convert_mask_to_alpha(fondo1, al_map_rgb(255, 0, 255));
	grafikainstrukcja = al_load_bitmap("grafiki/menu/instrukcja.bmp");
	al_convert_mask_to_alpha(grafikainstrukcja, al_map_rgb(255, 0, 255));

	informacja1 = al_load_bitmap("grafiki/menu/info1.bmp");
	al_convert_mask_to_alpha(informacja1, al_map_rgb(255, 0, 255));
	informacja2 = al_load_bitmap("grafiki/menu/info2.bmp");
	al_convert_mask_to_alpha(informacja2, al_map_rgb(255, 0, 255));
	ranking = al_load_bitmap("grafiki/menu/ranking.bmp");
	al_convert_mask_to_alpha(ranking, al_map_rgb(255, 0, 255));



	//al_hide_mouse_cursor(display); // usuwa kursor komputera

	///////////////////////////////////////////////////// Menu////////////////////////////////////////////
	
	
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		int opcja = -1;

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{

			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;

		}
		if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (ev.mouse.button & 2) {
				done = true;
			} // robi za escape (sprawdzenie czy dziala tylko)
			else if (ev.mouse.button & 1) {
				if (pos_x > 77 && pos_x < 372 && pos_y> 265 && pos_y < 318) {
					opcja = 5;
				}
				else if (pos_x > 77 && pos_x < 412 && pos_y> 349 && pos_y < 401) {

					opcja=3;
				}
				else if (pos_x > 75 && pos_x < 249 && pos_y> 431 && pos_y < 486) {

					opcja = 4;
				}

				else if (pos_x > 73 && pos_x < 279 && pos_y> 514 && pos_y < 568) {
                    done = true;
				}

				
				              
			}


		}
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{

			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		if (pos_x > 77 && pos_x < 372 && pos_y> 265 && pos_y < 318) {

			al_draw_bitmap(fondo2, 0, 0, 0);

		}
		else if (pos_x > 77 && pos_x < 412 && pos_y> 349 && pos_y < 401) {

			al_draw_bitmap(fondo3, 0, 0, 0);
			
		}
		else if (pos_x > 75 && pos_x < 249 && pos_y> 431 && pos_y < 486) {

			al_draw_bitmap(fondo4, 0, 0, 0);
		}
		else if (pos_x > 73 && pos_x < 279 && pos_y> 514 && pos_y < 568) {

			al_draw_bitmap(fondo5, 0, 0, 0);
		}
		else {

			al_draw_bitmap(fondo1, 0, 0, 0);
		}

		if (draw) {




			
			al_draw_bitmap(cursor, pos_x, pos_y, NULL);
			//al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 0, 255));
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}

		
		//////////////////////////////////////////// petla gry//////////////////////////////////////////////////////////
		float tablica;
        tablica = rand() % (32);

		float kluczyk;
		kluczyk = 0;
		float prezencik;
		prezencik = 0;
		

		
		switch (opcja)
		{


		case 0:

		{
			gra:

			bool ekrangry = false;
			while (!ekrangry) {

				//Usuwa muzyke
				


				ALLEGRO_FONT *font24 = al_create_builtin_font();



				float hp;
				int poz_kostka = 32;
				bool kostka_ruch = false;

				int poz_kostka2 = 330;
				bool kostka_ruch2 = false;

				int poz_kostka3 = 150;
				bool kostka_ruch3 = false;

				int poz_kostka4 = 672;
				bool kostka_ruch4 = false;

				int poz_kostka5 = 672;
				bool kostka_ruch5 = false;

				int poz_kostka6 = 352;
				bool kostka_ruch6 = false;
				hp = 100;


				

				ALLEGRO_BITMAP *mur = NULL;
				mur = al_load_bitmap("grafiki/bloki/mur1.png");
				ALLEGRO_BITMAP *podloga = NULL;
				podloga = al_load_bitmap("grafiki/bloki/podloga2.jpg");
				ALLEGRO_BITMAP *dol = NULL;
				dol = al_load_bitmap("grafiki/menu/info/dol.jpg");
				ALLEGRO_BITMAP *bok = NULL;
				bok = al_load_bitmap("grafiki/menu/info/bok.jpg");
				ALLEGRO_BITMAP *zycie10 = NULL;
				zycie10 = al_load_bitmap("grafiki/menu/info/zycie10.jpg");
				ALLEGRO_BITMAP *zycie9 = NULL;
				zycie9 = al_load_bitmap("grafiki/menu/info/zycie9.jpg");
				ALLEGRO_BITMAP *zycie8 = NULL;
				zycie8 = al_load_bitmap("grafiki/menu/info/zycie8.jpg");
				ALLEGRO_BITMAP *zycie7 = NULL;
				zycie7 = al_load_bitmap("grafiki/menu/info/zycie7.jpg");
				ALLEGRO_BITMAP *zycie6 = NULL;
				zycie6 = al_load_bitmap("grafiki/menu/info/zycie6.jpg");
				ALLEGRO_BITMAP *zycie5 = NULL;
				zycie5 = al_load_bitmap("grafiki/menu/info/zycie5.jpg");
				ALLEGRO_BITMAP *zycie4 = NULL;
				zycie4 = al_load_bitmap("grafiki/menu/info/zycie4.jpg");
				ALLEGRO_BITMAP *zycie3 = NULL;
				zycie3 = al_load_bitmap("grafiki/menu/info/zycie3.jpg");
				ALLEGRO_BITMAP *zycie2 = NULL;
				zycie2 = al_load_bitmap("grafiki/menu/info/zycie2.jpg");
				ALLEGRO_BITMAP *zycie1 = NULL;
				zycie1 = al_load_bitmap("grafiki/menu/info/zycie1.jpg");
				ALLEGRO_BITMAP *zycie0 = NULL;
				zycie0 = al_load_bitmap("grafiki/menu/info/zycie0.jpg");
				ALLEGRO_BITMAP *przeszkoda = NULL;
				przeszkoda = al_load_bitmap("grafiki/bloki/blokdodatkowy.png");

				ALLEGRO_BITMAP *broken = NULL;
				broken = al_load_bitmap("grafiki/items/broken.png");
				ALLEGRO_BITMAP *klucz = NULL;
				klucz = al_load_bitmap("grafiki/items/klucz.png");
				ALLEGRO_BITMAP *drzwi = NULL;
				drzwi = al_load_bitmap("grafiki/items/drzwi.png");
				ALLEGRO_BITMAP *prezent = NULL;
				prezent = al_load_bitmap("grafiki/items/prezent.png");

				ALLEGRO_BITMAP *zield = NULL;
				zield = al_load_bitmap("grafiki/menu/zield.bmp");
				ALLEGRO_BITMAP *zielm = NULL;
				zielm = al_load_bitmap("grafiki/menu/zielm.bmp");
				ALLEGRO_BITMAP *czed = NULL;
				czed = al_load_bitmap("grafiki/menu/czed.bmp");
				ALLEGRO_BITMAP *czem = NULL;
				czem = al_load_bitmap("grafiki/menu/czem.bmp");



				bool mury[25][20];


				for (int i = 0; i < 25; i++)
					for (int j = 0; j < 20; j++)
					{
						mury[i][j] = false;

					}

				// Mapa œwiata

				for (int i = 0; i < 25; i++)
					for (int j = 0; j < 20; j++)
					{
						if (i == 0 || i == 24 || j == 0 || j == 19)
							mury[i][j] = true; mury[1][3] = true; mury[2][3] = true; mury[3][3] = true; mury[4][3] = true; mury[5][3] = true; mury[8][1] = true; mury[8][2] = true; mury[8][3] = true; mury[9][3] = true; mury[10][3] = true; mury[11][3] = true;  mury[13][3] = true; mury[14][3] = true; mury[15][3] = true; mury[15][2] = true; mury[15][1] = true; mury[15][4] = true; mury[15][5] = true; mury[15][6] = true; mury[15][7] = true; mury[15][8] = true; mury[15][9] = true; mury[15][10] = true; mury[15][11] = true; mury[14][11] = true; mury[13][11] = true; mury[12][11] = true; mury[11][11] = true; mury[10][11] = true; mury[3][6] = true; mury[3][7] = true; mury[3][8] = true; mury[3][9] = true; mury[3][10] = true; mury[3][11] = true; mury[3][12] = true; mury[3][13] = true; mury[4][13] = true; mury[5][13] = true;  mury[5][14] = true; mury[5][15] = true; mury[5][16] = true; mury[5][17] = true; mury[5][18] = true; mury[1][15] = true; mury[2][15] = true; mury[5][6] = true; mury[4][6] = true; mury[6][6] = true; mury[7][6] = true; mury[8][6] = true; mury[9][6] = true; mury[10][6] = true; mury[11][6] = true; mury[12][6] = true; mury[12][7] = true; mury[12][8] = true; mury[11][8] = true;   mury[10][8] = true; mury[9][8] = true; mury[8][8] = true; mury[7][8] = true; mury[7][9] = true; mury[7][10] = true; mury[7][11] = true; mury[7][12] = true; mury[7][13] = true; mury[7][14] = true; mury[8][14] = true; mury[9][14] = true; mury[10][14] = true; mury[11][14] = true; mury[12][14] = true; mury[13][14] = true; mury[14][14] = true; mury[15][14] = true; mury[16][14] = true; mury[17][14] = true; mury[18][14] = true; mury[18][13] = true; mury[18][12] = true; mury[18][11] = true; mury[18][10] = true; mury[18][9] = true; mury[18][8] = true; mury[18][7] = true; mury[18][6] = true; mury[18][3] = true; mury[19][3] = true; mury[20][3] = true; mury[21][3] = true; mury[21][4] = true; mury[21][5] = true; mury[21][6] = true; mury[20][6] = true; mury[19][6] = true; mury[21][3] = true; mury[19][10] = true; mury[20][10] = true; mury[21][10] = true; mury[22][8] = true; mury[23][8] = true; mury[21][11] = true; mury[21][12] = true; mury[21][13] = true; mury[21][14] = true; mury[21][15] = true; mury[21][16] = true; mury[10][15] = true; mury[10][16] = true; mury[10][17] = true; mury[10][18] = true; mury[11][15] = true;  mury[20][16] = true; mury[13][15] = true; mury[14][15] = true; mury[14][16] = true; mury[14][17] = true;  mury[15][17] = true; mury[19][16] = true; mury[19][17] = true; mury[18][17] = true; mury[17][17] = true; mury[16][17] = true;

					}





				int gracz_x = 96, gracz_y = 512;
				int mur_x = 0, mur_y = 0;
				int wspmur_x[25][20], wspmur_y[25][20];

				for (int k = 0; k < 20; k++)
					for (int l = 0; l < 15; l++)
					{
						wspmur_x[k][l] = 0;
						wspmur_y[k][l] = 0;
					}


				ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
				al_register_event_source(event_queue, al_get_keyboard_event_source());
				al_register_event_source(event_queue, al_get_timer_event_source(timer));

				bool yyy;
				yyy = false;

				bool prezentt;
				prezentt = false;


				bool zamknij = false;
				bool kolizja = false;
				bool ruch = true, ruch1 = true, ruch2 = true, ruch3 = true, ruch4 = true, ruch5 = true;

				al_start_timer(timer);
				while (!zamknij)
				{
					ALLEGRO_EVENT ev;
					al_wait_for_event(event_queue, &ev);
					if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
					{
						switch (ev.keyboard.keycode)
						{
						case ALLEGRO_KEY_UP:
							keys[UP] = true;
							break;
						case ALLEGRO_KEY_DOWN:
							keys[DOWN] = true;
							break;
						case ALLEGRO_KEY_LEFT:
							keys[LEFT] = true;
							break;
						case ALLEGRO_KEY_RIGHT:
							keys[RIGHT] = true;
							break;
						case ALLEGRO_KEY_W:
							keys[W] = true;
							break;
						case ALLEGRO_KEY_S:
							keys[S] = true;
							break;
						case ALLEGRO_KEY_A:
							keys[A] = true;
							break;
						case ALLEGRO_KEY_D:
							keys[D] = true;
							break;
						case ALLEGRO_KEY_ESCAPE:
							zamknij = true;
							break;
						}
					}
					else if (ev.type == ALLEGRO_EVENT_KEY_UP)
					{
						switch (ev.keyboard.keycode)
						{
						case ALLEGRO_KEY_UP:
							keys[UP] = false;
							break;
						case ALLEGRO_KEY_DOWN:
							keys[DOWN] = false;
							break;
						case ALLEGRO_KEY_LEFT:
							keys[LEFT] = false;
							break;
						case ALLEGRO_KEY_RIGHT:
							keys[RIGHT] = false;
							break;
						case ALLEGRO_KEY_W:
							keys[W] = false;
							break;
						case ALLEGRO_KEY_S:
							keys[S] = false;
							break;
						case ALLEGRO_KEY_A:
							keys[A] = false;
							break;
						case ALLEGRO_KEY_D:
							keys[D] = false;
							break;
						}
					}
					else if (ev.type == ALLEGRO_EVENT_TIMER)
					{

						czas++;

						if (ruch)
						{
							gracz_y -= keys[UP] * 2;
							gracz_y += keys[DOWN] * 2;
							gracz_x -= keys[LEFT] * 2;
							gracz_x += keys[RIGHT] * 2;
						}

						if (!kostka_ruch)// pierwsza przeszkoda
						{
							poz_kostka = poz_kostka + 1; if (poz_kostka == 96) { kostka_ruch = true; }
						}
						if (kostka_ruch) { poz_kostka = poz_kostka - 1; if (poz_kostka == 0) { kostka_ruch = false; } }


						if (!kostka_ruch2)//druga przeszkoda
						{
							poz_kostka2 = poz_kostka2 + 1; if (poz_kostka2 == 428) { kostka_ruch2 = true; }
						}
						if (kostka_ruch2) { poz_kostka2 = poz_kostka2 - 1; if (poz_kostka2 == 330) { kostka_ruch2 = false; } }

						if (!kostka_ruch3)//trzecia przeszkoda
						{
							poz_kostka3 = poz_kostka3 + 1; if (poz_kostka3 == 266) { kostka_ruch3 = true; }
						}
						if (kostka_ruch3) { poz_kostka3 = poz_kostka3 - 1; if (poz_kostka3 == 150) { kostka_ruch3 = false; } }

						if (!kostka_ruch4)//czwarta przeszkoda
						{
							poz_kostka4 = poz_kostka4 + 1; if (poz_kostka4 == 768) { kostka_ruch4 = true; }
						}
						if (kostka_ruch4) { poz_kostka4 = poz_kostka4 - 1; if (poz_kostka4 == 672) { kostka_ruch4 = false; } }

						if (!kostka_ruch5)//piata przeszkoda
						{
							poz_kostka5 = poz_kostka5 + 1; if (poz_kostka5 == 768) { kostka_ruch5 = true; }
						}
						if (kostka_ruch5) { poz_kostka5 = poz_kostka5 - 1; if (poz_kostka5 == 672) { kostka_ruch5 = false; } }

						if (!kostka_ruch6)//szosta przeszkoda
						{
							poz_kostka6 = poz_kostka6 + 1; if (poz_kostka6 == 448) { kostka_ruch6 = true; }
						}
						if (kostka_ruch6) { poz_kostka6 = poz_kostka6 - 1; if (poz_kostka6 == 352) { kostka_ruch6 = false; } }

					}




					if (!kolizja)
					{
						for (int k = 0; k < 25; k++)
							for (int l = 0; l < 20; l++)
							{
								if (mury[k][l]) { al_draw_bitmap(mur, k * 32, l * 32, 0); wspmur_x[k][l] = k * 32; wspmur_y[k][l] = l * 32; }
							}

						for (int i = 0; i < 25; i++)
							for (int j = 0; j < 20; j++)
							{
								if (mury[i][j] == false) { al_draw_bitmap(podloga, i * 32, j * 32, 0); }
							}


						al_draw_bitmap(bok, 800, 0, 0);
						al_draw_bitmap(dol, 0, 640, 0);
						al_draw_bitmap(broken, 32, 32, 0);
						al_draw_bitmap(drzwi, 384, 480, 0);


						if (!yyy) {

							al_draw_bitmap(klucz, 288, 32, 0);
						}

						if (!prezentt) {

							al_draw_bitmap(prezent, 608, 128, 0);
						}


						if (gracz_x < 32)                               // warunki na ograniczenie przez okno
							gracz_x = 32;
						else if (gracz_x > al_get_display_width(display) - al_get_bitmap_width(gracz) - 32)
							gracz_x = al_get_display_width(display) - al_get_bitmap_width(gracz) - 32;
						if (gracz_y < 32)
							gracz_y = 32;
						else if (gracz_y > al_get_display_height(display) - al_get_bitmap_height(gracz) - 32)
							gracz_y = al_get_display_height(display) - al_get_bitmap_height(gracz) - 32;




						if (gracz_x >= 32 && gracz_x <= 64 && gracz_y >= 32 && gracz_y < 64) {

							if (tablica <= 10) {
								hp = hp - 0.02;
							}
							else if (tablica > 10 && tablica < 20) {
								hp = hp - 5;
							}
							else if (tablica >= 20)
							{
								hp = hp + 10;
							}
						}

						if (gracz_x >= 288 && gracz_x <= 320 && gracz_y >= 32 && gracz_y < 40) {

							kluczyk++;
						}

						if (gracz_x >= 608 && gracz_x <= 640 && gracz_y >= 128 && gracz_y < 150) {

							prezencik++;
						}
						if (poz_kostka == gracz_x && gracz_y >= 322 && gracz_y <= 384) {
							hp = hp - 15;
						}
						if (poz_kostka2 == gracz_x && gracz_y >= 66 && gracz_y <= 128) {
							hp = hp - 15;
						}
                        if (poz_kostka3 == gracz_x && gracz_y >= 66 && gracz_y <= 128) {
							hp = hp - 15;
						}
                        if (poz_kostka4 == gracz_x && gracz_y >= 128 && gracz_y <=194) {
							hp = hp - 15;
						}

						if (poz_kostka5 == gracz_x && gracz_y >= 480 && gracz_y <=546) {
							hp = hp - 15;
						}

						if (poz_kostka6 == gracz_y && gracz_x >= 386 && gracz_x <= 445) {
							hp = hp - 15;
						}




						// zycie
						if (hp <= 100 && hp >= 90) { al_draw_bitmap(zycie10, 320, 660, 0); }
						if (hp < 90 && hp >= 80) { al_draw_bitmap(zycie9, 320, 660, 0); }
						if (hp < 80 && hp >= 70) { al_draw_bitmap(zycie8, 320, 660, 0); }
						if (hp < 70 && hp >= 60) { al_draw_bitmap(zycie7, 320, 660, 0); }
						if (hp < 60 && hp >= 50) { al_draw_bitmap(zycie6, 320, 660, 0); }
						if (hp < 50 && hp >= 40) { al_draw_bitmap(zycie5, 320, 660, 0); }
						if (hp < 40 && hp >= 30) { al_draw_bitmap(zycie4, 320, 660, 0); }
						if (hp < 30 && hp >= 20) { al_draw_bitmap(zycie3, 320, 660, 0); }
						if (hp < 20 && hp >= 10) { al_draw_bitmap(zycie2, 320, 660, 0); }
						if (hp < 10 && hp >= 1) { al_draw_bitmap(zycie1, 320, 660, 0); }
						if (hp < 0) { al_draw_bitmap(zycie0, 320, 660, 0); }


						if (keys[LEFT])
							al_draw_bitmap(gracz2, gracz_x, gracz_y, 0); if (keys[RIGHT]) al_draw_bitmap(gracz0, gracz_x, gracz_y, 0); if (keys[UP])al_draw_bitmap(gracz1, gracz_x, gracz_y, 0); if (keys[DOWN])al_draw_bitmap(gracz, gracz_x, gracz_y, 0); if (!keys[LEFT] && !keys[RIGHT] && !keys[UP] && !keys[DOWN])al_draw_bitmap(gracz, gracz_x, gracz_y, 0);

					}

					for (int k = 0; k < 25; k++)
						for (int l = 0; l < 20; l++)
						{
							if ((wspmur_x[k][l] < gracz_x + al_get_bitmap_width(gracz)) && (wspmur_x[k][l] > gracz_x - al_get_bitmap_width(gracz)) && (wspmur_y[k][l] < gracz_y + al_get_bitmap_height(gracz)) && (wspmur_y[k][l] > gracz_y - al_get_bitmap_height(gracz)))
								ruch = false;


						}



					if (!ruch)
					{
						if (keys[LEFT]) gracz_x += 2; if (keys[RIGHT]) gracz_x -= 2; if (keys[UP]) gracz_y += 2; if (keys[DOWN]) gracz_y -= 2;
						ruch = true;
					}



					bool poziom = true;

					al_start_timer;

					if (poziom) {
						al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 230, ALLEGRO_ALIGN_CENTRE, "x=%d y=%d h=%f ", gracz_x, gracz_y, hp);
						al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 260, ALLEGRO_ALIGN_CENTRE, "t=%f  ", tablica);
						al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 280, ALLEGRO_ALIGN_CENTRE, "klucz=%f ", kluczyk);
						al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 360, ALLEGRO_ALIGN_CENTRE, "prezent=%f ", prezencik);
						al_draw_textf(czcionka, al_map_rgb(0, 255, 0), 900, 90, ALLEGRO_ALIGN_CENTRE, "czas=%f ", czas);


						if (kluczyk > 1) {

							al_draw_bitmap(zielm, 876, 640, 0);
							yyy = true;
						}
						else {
							al_draw_bitmap(czem, 876, 640, 0);
						}

						if (prezencik > 1) {
							al_draw_bitmap(zield, 876, 659, 0);
							prezentt = true;
						}
						else {
							al_draw_bitmap(czed, 876, 659, 0);
						}
						if (prezencik > 1 && kluczyk > 1) {
							al_draw_bitmap(zield, 876, 680, 0);
						}
						else {
							al_draw_bitmap(czed, 876, 680, 0);
						}



					}


					if (prezencik > 1 && kluczyk > 1) {
						if (gracz_x == 384 && gracz_y == 480) {


							//al_draw_filled_rectangle(300, 300, 600, 600, al_map_rgb(255, 0, 0));
							goto gra1;
							//al_flip_display;
						}
					}

					al_draw_bitmap(przeszkoda, poz_kostka, 352, 0);
					al_draw_bitmap(przeszkoda, poz_kostka2, 96, 0);
					al_draw_bitmap(przeszkoda, poz_kostka3, 96, 0);
					al_draw_bitmap(przeszkoda, poz_kostka4, 162, 0);
					al_draw_bitmap(przeszkoda, poz_kostka5, 512, 0);
					al_draw_bitmap(przeszkoda, 416, poz_kostka6, 0);
























					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
				}

				al_destroy_bitmap(gracz);
				al_destroy_font(font24);
				al_destroy_font(czcionka);
				al_destroy_display(display);
				return 0;







			}

			//

		}

		break;

		case 1:
		{
		
			bool opcje = false;
			while (!opcje) {

				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);

				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (ev.keyboard.keycode)
					{

					case ALLEGRO_KEY_ESCAPE:
						opcje = true;
						break;
					}
				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					pos_x = ev.mouse.x;
					pos_y = ev.mouse.y;

				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 2) {
						opcje = true;
					} // robi za escape (sprawdzenie czy dziala tylko)
					else if (ev.mouse.button & 1) {

						if (pos_x > 71 && pos_x < 342 && pos_y> 240 && pos_y < 279) {

							al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);

						}
						else if (pos_x > 71 && pos_x < 366 && pos_y> 275 && pos_y < 401) {

							al_stop_samples(sample);

						}

						else if (pos_x > 73 && pos_x < 279 && pos_y> 514 && pos_y < 567) {

							opcje = true;

						}




					}
				}

				if (pos_x > 71 && pos_x < 342 && pos_y> 240 && pos_y < 279) {

					al_draw_bitmap(grafikaopcja2, 0, 0, 0);

				}
				else if (pos_x > 71 && pos_x < 366 && pos_y> 275 && pos_y < 401) {

					al_draw_bitmap(grafikaopcja3, 0, 0, 0);

				}

				else {

					al_draw_bitmap(grafikaopcja, 0, 0, 0);
				}



				al_flip_display();
			}


		}
		break;

		case 2:
		{

			bool opcje = false;
			while (!opcje) {

				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);

				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (ev.keyboard.keycode)
					{

					case ALLEGRO_KEY_ESCAPE:
						opcje = true;
						break;
					}
				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					pos_x = ev.mouse.x;
					pos_y = ev.mouse.y;

				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 2) {
						opcje = true;
					} // robi za escape (sprawdzenie czy dziala tylko)
					else if (ev.mouse.button & 1) {

						if (pos_x > 73 && pos_x < 279 && pos_y> 514 && pos_y < 567) {

							opcje = true;

						}




					}
				}

				if (pos_x > 0 && pos_x < 1000 && pos_y> 0 && pos_y < 700) {

					al_draw_bitmap(grafikainstrukcja, 0, 0, 0);

				}




				al_flip_display();
			}


		}
		break;

		// biegne

		case 5:
		{
			al_destroy_sample(sample);
			bool opcje = false;
			while (!opcje) {

				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);

				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (ev.keyboard.keycode)
					{

					case ALLEGRO_KEY_ESCAPE:
						opcje = true;
						break;
					}
				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					pos_x = ev.mouse.x;
					pos_y = ev.mouse.y;

				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 2) {
						opcje = true;
					} // robi za escape (sprawdzenie czy dziala tylko)
					else if (ev.mouse.button & 1) {

						if (pos_x > 394 && pos_x < 593 && pos_y> 475 && pos_y < 530) {

							goto gra;

						}




					}
				}

				if (pos_x > 394 && pos_x < 593 && pos_y> 475 && pos_y < 530) {

					al_draw_bitmap(informacja2, 0, 0, 0);

				}
				else{
					al_draw_bitmap(informacja1, 0, 0, 0);
                  }




				al_flip_display();
			}


		}
		break;

		// Ranking
		case 6:
		{
		ranking:

			
			bool opcje = false;
			while (!opcje) {

				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);

				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (ev.keyboard.keycode)
					{

					case ALLEGRO_KEY_ESCAPE:
						opcje = true;
						break;
					}
				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_AXES)
				{
					pos_x = ev.mouse.x;
					pos_y = ev.mouse.y;

				}
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 2) {
						opcje = true;
					} // robi za escape (sprawdzenie czy dziala tylko)
					else if (ev.mouse.button & 1) {

						if (pos_x > 394 && pos_x < 593 && pos_y> 475 && pos_y < 530) {

							//

						}




					}
				}

				if (pos_x > 0 && pos_x < 1000 && pos_y> 0 && pos_y < 700) {

					al_draw_bitmap(ranking, 0, 0, 0);

				}
				




				al_flip_display();
			}


		}
		break;


		case 3:
		{
			gra1:
			

			const int FPS = 60;

			


			if (!al_init())
				return -1;

			al_install_mouse();

			

			ALLEGRO_FONT *font24 = al_create_builtin_font();
			if (!font24)
				return 1;

			float hp;
			int poz_kostka = 0;
			bool kostka_ruch = false;

			int poz_kostka2 = 0;
			bool kostka_ruch2 = false;

			int poz_kostka3 = 198;
			bool kostka_ruch3 = false;

			int poz_kostka4 = 0;
			bool kostka_ruch4 = false;

			int poz_kostka5 = 640;
			bool kostka_ruch5 = false;

			int poz_kostka6 = 352;
			bool kostka_ruch6 = false;
			hp = 100;


			ALLEGRO_BITMAP *npc = NULL;
			npc = al_load_bitmap("grafika\\gracze\\gracz1.pcx");

			ALLEGRO_BITMAP *mur = NULL;
			mur = al_load_bitmap("grafiki/bloki/mur1.png");
			ALLEGRO_BITMAP *pok22 = al_create_sub_bitmap(npc, 0, 64, 32, 32);

			ALLEGRO_BITMAP *podloga = NULL;
			podloga = al_load_bitmap("grafiki/bloki/podloga.png");

			ALLEGRO_BITMAP *dol = NULL;
			dol = al_load_bitmap("grafiki/menu/info/dol2.jpg");
			ALLEGRO_BITMAP *bok = NULL;
			bok = al_load_bitmap("grafiki/menu/info/bok.jpg");
			ALLEGRO_BITMAP *zycie10 = NULL;
			zycie10 = al_load_bitmap("grafiki/menu/info/zycie10.jpg");
			ALLEGRO_BITMAP *zycie9 = NULL;
			zycie9 = al_load_bitmap("grafiki/menu/info/zycie9.jpg");
			ALLEGRO_BITMAP *zycie8 = NULL;
			zycie8 = al_load_bitmap("grafiki/menu/info/zycie8.jpg");
			ALLEGRO_BITMAP *zycie7 = NULL;
			zycie7 = al_load_bitmap("grafiki/menu/info/zycie7.jpg");
			ALLEGRO_BITMAP *zycie6 = NULL;
			zycie6 = al_load_bitmap("grafiki/menu/info/zycie6.jpg");
			ALLEGRO_BITMAP *zycie5 = NULL;
			zycie5 = al_load_bitmap("grafiki/menu/info/zycie5.jpg");
			ALLEGRO_BITMAP *zycie4 = NULL;
			zycie4 = al_load_bitmap("grafiki/menu/info/zycie4.jpg");
			ALLEGRO_BITMAP *zycie3 = NULL;
			zycie3 = al_load_bitmap("grafiki/menu/info/zycie3.jpg");
			ALLEGRO_BITMAP *zycie2 = NULL;
			zycie2 = al_load_bitmap("grafiki/menu/info/zycie2.jpg");
			ALLEGRO_BITMAP *zycie1 = NULL;
			zycie1 = al_load_bitmap("grafiki/menu/info/zycie1.jpg");
			ALLEGRO_BITMAP *zycie0 = NULL;
			zycie0 = al_load_bitmap("grafiki/menu/info/zycie0.jpg");
			ALLEGRO_BITMAP *przeszkoda = NULL;
			przeszkoda = al_load_bitmap("grafiki/bloki/blokdodatkowy.png");

			ALLEGRO_BITMAP *broken = NULL;
			broken = al_load_bitmap("grafiki/items/broken.png");
			ALLEGRO_BITMAP *klucz = NULL;
			klucz = al_load_bitmap("grafiki/items/klucz.png");
			ALLEGRO_BITMAP *drzwi = NULL;
			drzwi = al_load_bitmap("grafiki/items/drzwi.png");
			ALLEGRO_BITMAP *prezent = NULL;
			prezent = al_load_bitmap("grafiki/items/prezent.png");

			ALLEGRO_BITMAP *zield = NULL;
			zield = al_load_bitmap("grafiki/menu/zield.bmp");
			ALLEGRO_BITMAP *zielm = NULL;
			zielm = al_load_bitmap("grafiki/menu/zielm.bmp");
			ALLEGRO_BITMAP *czed = NULL;
			czed = al_load_bitmap("grafiki/menu/czed.bmp");
			ALLEGRO_BITMAP *czem = NULL;
			czem = al_load_bitmap("grafiki/menu/czem.bmp");

			
			
	
			
			bool mury[25][20];


			for (int i = 0; i < 25; i++)
				for (int j = 0; j < 20; j++)
				{
					mury[i][j] = false;
					
					

				}

			// Mapa œwiata

			for (int i = 0; i < 25; i++)
				for (int j = 0; j < 20; j++)
				{
					if (i == 0 || i == 24 || j == 0 || j == 19)
						mury[i][j] = true;
					mury[1][15] = true; mury[2][15] = true; mury[4][15] = true; mury[5][15] = true; mury[5][16] = true; mury[5][17] = true; mury[5][18] = true; mury[5][19] = true; mury[5][20] = true; mury[1][15] = true; mury[5][14] = true; mury[5][13] = true; mury[5][12] = true; mury[5][11] = true; mury[5][10] = true; mury[5][9] = true; mury[5][8] = true; mury[5][7] = true; mury[5][6] = true;
					mury[5][5] = true; mury[5][4] = true; mury[5][3] = true; mury[5][1] = true; mury[6][1] = true; mury[7][1] = true; mury[8][1] = true; mury[8][2] = true; mury[8][3] = true; mury[8][4] = true; mury[8][5] = true; mury[8][6] = true; mury[8][7] = true; mury[8][8] = true; mury[8][9] = true; mury[8][8] = true;
					mury[8][10] = true; mury[8][11] = true; mury[9][11] = true; mury[10][11] = true; mury[12][11] = true; mury[11][11] = true; mury[12][11] = true; mury[13][11] = true; mury[14][11] = true; mury[15][11] = true; mury[16][11] = true; mury[17][11] = true; mury[18][11] = true; mury[19][11] = true; mury[20][11] = true; mury[20][14] = true; mury[20][13] = true; mury[20][12] = true; mury[17][14] = true;
					mury[16][14] = true; mury[15][14] = true; mury[14][14] = true; mury[13][14] = true; mury[11][14] = true; mury[10][14] = true; mury[20][16] = true; mury[20][15] = true;
					mury[19][16] = true; mury[18][16] = true; mury[17][16] = true; mury[16][16] = true; mury[15][16] = true; mury[14][16] = true; mury[13][16] = true; mury[12][16] = true; mury[11][16] = true;
					mury[10][16] = true; mury[9][16] = true; mury[8][16] = true; mury[9][14] = true; mury[8][14] = true; mury[7][14] = true; mury[12][13] = true; mury[13][13] = true; mury[11][13] = true; mury[6][14] = true; mury[23][8] = true; mury[22][8] = true; mury[21][8] = true; mury[20][8] = true; mury[19][8] = true; mury[18][8] = true;
					mury[17][8] = true; mury[16][8] = true; mury[15][8] = true; mury[14][8] = true; mury[13][8] = true; mury[12][8] = true; mury[11][8] = true; mury[11][7] = true; mury[11][6] = true; mury[11][3] = true; mury[11][2] = true;
					mury[12][3] = true; mury[13][3] = true; mury[14][3] = true; mury[15][3] = true; mury[16][3] = true; mury[17][3] = true; mury[18][3] = true; mury[19][3] = true; mury[20][3] = true; mury[21][3] = true; mury[22][3] = true; mury[23][3] = true;
					mury[14][4] = true; mury[14][5] = true; mury[22][1] = true; mury[15][4] = true; mury[16][4] = true; mury[17][4] = true; mury[18][4] = true; mury[19][4] = true; mury[20][4] = true; mury[21][4] = true; mury[22][4] = true; mury[23][4] = true; mury[14][6] = true; mury[15][6] = true; mury[16][6] = true; mury[17][6] = true; mury[18][6] = true; mury[19][6] = true; mury[20][6] = true; mury[21][6] = true;
					mury[21][14] = true; mury[21][12] = true;
				}
			

			

			al_convert_mask_to_alpha(gracz, al_map_rgb(0, 255, 255));
			al_convert_mask_to_alpha(pok22, al_map_rgb(255, 0, 255));
			al_convert_mask_to_alpha(gracz1, al_map_rgb(0, 255, 255));
			al_convert_mask_to_alpha(gracz2, al_map_rgb(0, 255, 255));
			al_convert_mask_to_alpha(gracz0, al_map_rgb(0, 255, 255));

			int gracz_x = 96, gracz_y = 512;
			int npc_x = 32, npc_y = 32;
			int mur_x = 0, mur_y = 0;
			int wspmur_x[25][20], wspmur_y[25][20];

			for (int k = 0; k < 20; k++)
				for (int l = 0; l < 15; l++)
				{
					wspmur_x[k][l] = 0;
					wspmur_y[k][l] = 0;
				}


			ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			al_register_event_source(event_queue, al_get_timer_event_source(timer));

			bool zamknij = false;
			bool kolizja = false;
			bool ruch = true, ruch1 = true, ruch2 = true, ruch3 = true, ruch4 = true, ruch5 = true;

			al_start_timer(timer);
			while (!zamknij)
			{
				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
				{
					switch (ev.keyboard.keycode)
					{
					case ALLEGRO_KEY_UP:
						keys[UP] = true;
						break;
					case ALLEGRO_KEY_DOWN:
						keys[DOWN] = true;
						break;
					case ALLEGRO_KEY_LEFT:
						keys[LEFT] = true;
						break;
					case ALLEGRO_KEY_RIGHT:
						keys[RIGHT] = true;
						break;
					case ALLEGRO_KEY_W:
						keys[W] = true;
						break;
					case ALLEGRO_KEY_S:
						keys[S] = true;
						break;
					case ALLEGRO_KEY_A:
						keys[A] = true;
						break;
					case ALLEGRO_KEY_D:
						keys[D] = true;
						break;
					case ALLEGRO_KEY_ESCAPE:
						zamknij = true;
						break;
					}
				}
				else if (ev.type == ALLEGRO_EVENT_KEY_UP)
				{
					switch (ev.keyboard.keycode)
					{
					case ALLEGRO_KEY_UP:
						keys[UP] = false;
						break;
					case ALLEGRO_KEY_DOWN:
						keys[DOWN] = false;
						break;
					case ALLEGRO_KEY_LEFT:
						keys[LEFT] = false;
						break;
					case ALLEGRO_KEY_RIGHT:
						keys[RIGHT] = false;
						break;
					case ALLEGRO_KEY_W:
						keys[W] = false;
						break;
					case ALLEGRO_KEY_S:
						keys[S] = false;
						break;
					case ALLEGRO_KEY_A:
						keys[A] = false;
						break;
					case ALLEGRO_KEY_D:
						keys[D] = false;
						break;
					}
				}
				else if (ev.type == ALLEGRO_EVENT_TIMER)
				{

					czas++;

					if (ruch)
					{
						gracz_y -= keys[UP] * 2;
						gracz_y += keys[DOWN] * 2;
						gracz_x -= keys[LEFT] * 2;
						gracz_x += keys[RIGHT] * 2;
					}

					if (!kostka_ruch)// pierwsza przeszkoda
					{
						poz_kostka = poz_kostka + 2; if (poz_kostka == 162) { kostka_ruch = true; }
					}
					if (kostka_ruch) { poz_kostka = poz_kostka - 2; if (poz_kostka == 0) { kostka_ruch = false; } }


					if (!kostka_ruch2)//druga przeszkoda
					{
						poz_kostka2 = poz_kostka2 + 2; if (poz_kostka2 == 162) { kostka_ruch2 = true; }
					}
					if (kostka_ruch2) { poz_kostka2 = poz_kostka2 - 2; if (poz_kostka2 == 0) { kostka_ruch2 = false; } }

					if (!kostka_ruch3)//trzecia przeszkoda
					{
						poz_kostka3 = poz_kostka3 + 1; if (poz_kostka3 == 260) { kostka_ruch3 = true; }
					}
					if (kostka_ruch3) { poz_kostka3 = poz_kostka3 - 1; if (poz_kostka3 == 188) { kostka_ruch3 = false; } }

					if (!kostka_ruch4)//czwarta przeszkoda
					{
						poz_kostka4 = poz_kostka4 + 1; if (poz_kostka4 == 100) { kostka_ruch4 = true; }
					}
					if (kostka_ruch4) { poz_kostka4 = poz_kostka4 - 1; if (poz_kostka4 == -5) { kostka_ruch4 = false; } }

					if (!kostka_ruch5)//piata przeszkoda
					{
						poz_kostka5 = poz_kostka5 + 2; if (poz_kostka5 == 768) { kostka_ruch5 = true; }
					}
					if (kostka_ruch5) { poz_kostka5 = poz_kostka5 - 2; if (poz_kostka5 == 640) { kostka_ruch5 = false; } }

					if (!kostka_ruch6)//szosta przeszkoda
					{
						poz_kostka6 = poz_kostka6 + 1; if (poz_kostka6 == 416) { kostka_ruch6 = true; }
					}
					if (kostka_ruch6) { poz_kostka6 = poz_kostka6 - 1; if (poz_kostka6 == 352) { kostka_ruch6 = false; } }

				}




				if (!kolizja)
				{
					for (int k = 0; k < 25; k++)
						for (int l = 0; l < 20; l++)
						{
							if (mury[k][l]) { al_draw_bitmap(mur, k * 32, l * 32, 0); wspmur_x[k][l] = k * 32; wspmur_y[k][l] = l * 32; }
						}

					for (int i = 0; i < 25; i++)
						for (int j = 0; j < 20; j++)
						{
							if (mury[i][j] == false) { al_draw_bitmap(podloga, i * 32, j * 32, 0); }
						}


					al_draw_bitmap(bok, 800, 0, 0);
					al_draw_bitmap(dol, 0, 640, 0);
					al_draw_bitmap(broken, 672, 416, 0);
					al_draw_bitmap(drzwi, 736, 32, 0);


					

					if (gracz_x < 32)                               // warunki na ograniczenie przez okno
						gracz_x = 32;
					else if (gracz_x > al_get_display_width(display) - al_get_bitmap_width(gracz) - 32)
						gracz_x = al_get_display_width(display) - al_get_bitmap_width(gracz) - 32;
					if (gracz_y < 32)
						gracz_y = 32;
					else if (gracz_y > al_get_display_height(display) - al_get_bitmap_height(gracz) - 32)
						gracz_y = al_get_display_height(display) - al_get_bitmap_height(gracz) - 32;




					if (gracz_x >= 32 && gracz_x <= 64 && gracz_y >= 32 && gracz_y < 64) {

						if (tablica <= 10) {
							hp = hp - 0.02;
						}
						else if (tablica > 10 && tablica < 20) {
							hp = hp - 5;
						}
						else if (tablica >= 20)
						{
							hp = hp + 10;
						}
					}

					if (gracz_x >= 288 && gracz_x <= 320 && gracz_y >= 32 && gracz_y < 40) {

						
					}

					if (gracz_x >= 608 && gracz_x <= 640 && gracz_y >= 128 && gracz_y < 150) {

						prezencik++;
					}
					if (poz_kostka == gracz_x && gracz_y >= 318 && gracz_y <= 386) {
						hp = hp - 15;
					}
					if (poz_kostka2 == gracz_x && gracz_y >= 62 && gracz_y <= 130) {
						hp = hp - 15;
					}
					if (poz_kostka3 == gracz_y && gracz_x >= 416 && gracz_x <= 482) {
						hp = hp - 15;
					}
					if (poz_kostka4 == gracz_y && gracz_x >= 488 && gracz_x <= 544) {
						hp = hp - 15;
					}
					if (poz_kostka5 == gracz_x && gracz_y >= 478 && gracz_y <= 548) {
						hp = hp - 15;
					}
					if (poz_kostka6 == gracz_y && gracz_x >= 352 && gracz_x <= 416) {
						hp = hp - 15;
					}



					// zycie
					if (hp <= 100 && hp >= 90) { al_draw_bitmap(zycie10, 320, 660, 0); }
					if (hp < 90 && hp >= 80) { al_draw_bitmap(zycie9, 320, 660, 0); }
					if (hp < 80 && hp >= 70) { al_draw_bitmap(zycie8, 320, 660, 0); }
					if (hp < 70 && hp >= 60) { al_draw_bitmap(zycie7, 320, 660, 0); }
					if (hp < 60 && hp >= 50) { al_draw_bitmap(zycie6, 320, 660, 0); }
					if (hp < 50 && hp >= 40) { al_draw_bitmap(zycie5, 320, 660, 0); }
					if (hp < 40 && hp >= 30) { al_draw_bitmap(zycie4, 320, 660, 0); }
					if (hp < 30 && hp >= 20) { al_draw_bitmap(zycie3, 320, 660, 0); }
					if (hp < 20 && hp >= 10) { al_draw_bitmap(zycie2, 320, 660, 0); }
					if (hp < 10 && hp >= 1) { al_draw_bitmap(zycie1, 320, 660, 0); }
					if (hp < 0) { al_draw_bitmap(zycie0, 320, 660, 0); }


					if (keys[LEFT])
						al_draw_bitmap(gracz2, gracz_x, gracz_y, 0); if (keys[RIGHT]) al_draw_bitmap(gracz0, gracz_x, gracz_y, 0); if (keys[UP])al_draw_bitmap(gracz1, gracz_x, gracz_y, 0); if (keys[DOWN])al_draw_bitmap(gracz, gracz_x, gracz_y, 0); if (!keys[LEFT] && !keys[RIGHT] && !keys[UP] && !keys[DOWN])al_draw_bitmap(gracz, gracz_x, gracz_y, 0);

				}

				for (int k = 0; k < 25; k++)
					for (int l = 0; l < 20; l++)
					{
						if ((wspmur_x[k][l] < gracz_x + al_get_bitmap_width(gracz)) && (wspmur_x[k][l] > gracz_x - al_get_bitmap_width(gracz)) && (wspmur_y[k][l] < gracz_y + al_get_bitmap_height(gracz)) && (wspmur_y[k][l] > gracz_y - al_get_bitmap_height(gracz)))
							ruch = false;


					}



				if (!ruch)
				{
					if (keys[LEFT]) gracz_x += 2; if (keys[RIGHT]) gracz_x -= 2; if (keys[UP]) gracz_y += 2; if (keys[DOWN]) gracz_y -= 2;
					ruch = true;
				}



				bool poziom = true;

				al_start_timer;

				if (poziom) {
					al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 230, ALLEGRO_ALIGN_CENTRE, "x=%d y=%d h=%f ", gracz_x, gracz_y, hp);
					al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 260, ALLEGRO_ALIGN_CENTRE, "t=%f  ", tablica);
					al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 280, ALLEGRO_ALIGN_CENTRE, "klucz=%f ", kluczyk);
					al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 360, ALLEGRO_ALIGN_CENTRE, "prezent=%f ", prezencik);
					al_draw_textf(czcionka, al_map_rgb(0, 255, 0), 900, 90, ALLEGRO_ALIGN_CENTRE, "czas=%f ", czas);


					if (kluczyk > 1) {

						al_draw_bitmap(zielm, 876, 640, 0);
						
					}
					else {
						al_draw_bitmap(czem, 876, 640, 0);
					}

					if (prezencik > 1) {
						al_draw_bitmap(zield, 876, 659, 0);
						
					}
					else {
						al_draw_bitmap(czed, 876, 659, 0);
					}
					if (prezencik > 1 && kluczyk > 1) {
						al_draw_bitmap(zield, 876, 680, 0);
					}
					else {
						al_draw_bitmap(czed, 876, 680, 0);
					}



				}


				if (prezencik > 1 && kluczyk > 1) {
					if (gracz_x == 736 && gracz_y <36) {


						//al_draw_filled_rectangle(300, 300, 600, 600, al_map_rgb(255, 0, 0));
						goto gra2;
						//al_flip_display;
					}
				}

				al_draw_bitmap(przeszkoda, poz_kostka, 352, 0);
				al_draw_bitmap(przeszkoda, poz_kostka2, 96, 0);
				al_draw_bitmap(przeszkoda, 448, poz_kostka3, 0);
				al_draw_bitmap(przeszkoda, 512, poz_kostka4, 0);
				al_draw_bitmap(przeszkoda, poz_kostka5, 512, 0);
				al_draw_bitmap(przeszkoda, 384, poz_kostka6, 0);
























				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}

			al_destroy_bitmap(gracz);
			al_destroy_font(font24);
			al_destroy_font(czcionka);
			al_destroy_display(display);
			return 0;



		}

		break;


case 4:
{
	gra2:


	const int FPS = 60;




	if (!al_init())
		return -1;

	al_install_mouse();



	ALLEGRO_FONT *font24 = al_create_builtin_font();
	if (!font24)
		return 1;

	float hp;
	int poz_kostka = 386;
	bool kostka_ruch = false;

	int poz_kostka2 = 706;
	bool kostka_ruch2 = false;

	int poz_kostka3 = 128;
	bool kostka_ruch3 = false;

	int poz_kostka4 = 128;
	bool kostka_ruch4 = false;

	int poz_kostka5 = 0;
	bool kostka_ruch5 = false;

	int poz_kostka6 = 0;
	bool kostka_ruch6 = false;
	hp = 100;


	ALLEGRO_BITMAP *npc = NULL;
	npc = al_load_bitmap("grafika\\gracze\\gracz1.pcx");

	ALLEGRO_BITMAP *mur = NULL;
	mur = al_load_bitmap("grafiki/bloki/mur.png");
	ALLEGRO_BITMAP *pok22 = al_create_sub_bitmap(npc, 0, 64, 32, 32);

	ALLEGRO_BITMAP *podloga = NULL;
	podloga = al_load_bitmap("grafiki/bloki/podloga2.jpg");

	ALLEGRO_BITMAP *dol = NULL;
	dol = al_load_bitmap("grafiki/menu/info/dol3.jpg");
	ALLEGRO_BITMAP *bok = NULL;
	bok = al_load_bitmap("grafiki/menu/info/bok.jpg");
	ALLEGRO_BITMAP *zycie10 = NULL;
	zycie10 = al_load_bitmap("grafiki/menu/info/zycie10.jpg");
	ALLEGRO_BITMAP *zycie9 = NULL;
	zycie9 = al_load_bitmap("grafiki/menu/info/zycie9.jpg");
	ALLEGRO_BITMAP *zycie8 = NULL;
	zycie8 = al_load_bitmap("grafiki/menu/info/zycie8.jpg");
	ALLEGRO_BITMAP *zycie7 = NULL;
	zycie7 = al_load_bitmap("grafiki/menu/info/zycie7.jpg");
	ALLEGRO_BITMAP *zycie6 = NULL;
	zycie6 = al_load_bitmap("grafiki/menu/info/zycie6.jpg");
	ALLEGRO_BITMAP *zycie5 = NULL;
	zycie5 = al_load_bitmap("grafiki/menu/info/zycie5.jpg");
	ALLEGRO_BITMAP *zycie4 = NULL;
	zycie4 = al_load_bitmap("grafiki/menu/info/zycie4.jpg");
	ALLEGRO_BITMAP *zycie3 = NULL;
	zycie3 = al_load_bitmap("grafiki/menu/info/zycie3.jpg");
	ALLEGRO_BITMAP *zycie2 = NULL;
	zycie2 = al_load_bitmap("grafiki/menu/info/zycie2.jpg");
	ALLEGRO_BITMAP *zycie1 = NULL;
	zycie1 = al_load_bitmap("grafiki/menu/info/zycie1.jpg");
	ALLEGRO_BITMAP *zycie0 = NULL;
	zycie0 = al_load_bitmap("grafiki/menu/info/zycie0.jpg");
	ALLEGRO_BITMAP *przeszkoda = NULL;
	przeszkoda = al_load_bitmap("grafiki/bloki/blokdodatkowy.png");

	ALLEGRO_BITMAP *broken = NULL;
	broken = al_load_bitmap("grafiki/items/broken.png");
	ALLEGRO_BITMAP *klucz = NULL;
	klucz = al_load_bitmap("grafiki/items/klucz.png");
	ALLEGRO_BITMAP *drzwi = NULL;
	drzwi = al_load_bitmap("grafiki/items/drzwi.png");
	ALLEGRO_BITMAP *prezent = NULL;
	prezent = al_load_bitmap("grafiki/items/prezent.png");

	ALLEGRO_BITMAP *zield = NULL;
	zield = al_load_bitmap("grafiki/menu/zield.bmp");
	ALLEGRO_BITMAP *zielm = NULL;
	zielm = al_load_bitmap("grafiki/menu/zielm.bmp");
	ALLEGRO_BITMAP *czed = NULL;
	czed = al_load_bitmap("grafiki/menu/czed.bmp");
	ALLEGRO_BITMAP *czem = NULL;
	czem = al_load_bitmap("grafiki/menu/czem.bmp");

	




	bool mury[25][20];


	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 20; j++)
		{
			mury[i][j] = false;

		}

	// Mapa œwiata

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 20; j++)
		{
			if (i == 0 || i == 24 || j == 0 || j == 19)
				mury[i][j] = true; mury[1][15] = true; mury[2][15] = true; mury[4][15] = true; mury[5][15] = true; mury[5][16] = true; mury[5][17] = true; mury[5][18] = true; mury[5][19] = true; mury[5][20] = true;
			mury[1][14] = true; mury[2][14] = true; mury[1][13] = true; mury[1][12] = true; mury[2][13] = true; mury[2][12] = true; mury[3][12] = true; mury[4][12] = true; mury[5][12] = true; mury[6][12] = true; mury[7][12] = true; mury[8][12] = true; mury[8][13] = true; mury[8][14] = true; mury[8][15] = true; mury[8][16] = true; mury[9][16] = true; mury[10][16] = true; mury[13][16] = true; mury[13][17] = true; mury[13][18] = true;
			mury[10][15] = true; mury[10][14] = true; mury[13][14] = true; mury[13][15] = true; mury[10][13] = true; mury[10][12] = true; mury[10][11] = true; mury[10][10] = true; mury[12][10] = true; mury[12][11] = true; mury[12][12] = true;
			mury[14][10] = true; mury[14][11] = true; mury[14][12] = true; mury[14][14] = true; mury[15][14] = true; mury[16][14] = true; mury[16][13] = true; mury[16][12] = true; mury[16][11] = true; mury[16][10] = true; mury[16][9] = true; mury[16][8] = true; mury[15][8] = true; mury[14][8] = true; mury[13][8] = true; mury[12][8] = true; mury[11][8] = true; mury[10][8] = true; mury[9][8] = true; mury[8][8] = true; mury[7][8] = true; mury[9][12] = true; mury[7][9] = true; mury[7][10] = true;
			mury[6][10] = true; mury[5][10] = true; mury[4][10] = true; mury[3][10] = true; mury[3][9] = true; mury[3][8] = true; mury[3][7] = true; mury[3][6] = true; mury[3][5] = true; mury[3][4] = true; mury[3][3] = true; mury[3][1] = true; mury[5][1] = true;
			mury[5][2] = true; mury[5][3] = true; mury[5][4] = true; mury[5][5] = true; mury[5][6] = true; mury[5][7] = true; mury[5][8] = true;
			mury[7][2] = true; mury[8][2] = true; mury[9][2] = true; mury[10][2] = true; mury[11][2] = true; mury[12][2] = true; mury[13][2] = true; mury[14][2] = true; mury[15][2] = true; mury[16][2] = true;
			mury[7][4] = true; mury[8][4] = true; mury[9][4] = true; mury[10][4] = true; mury[11][4] = true; mury[12][4] = true; mury[13][4] = true; mury[14][4] = true; mury[15][4] = true; mury[16][4] = true;
			mury[7][6] = true; mury[8][6] = true; mury[9][6] = true; mury[10][6] = true; mury[11][6] = true; mury[12][6] = true; mury[13][6] = true; mury[14][6] = true; mury[15][6] = true; mury[16][6] = true;
			mury[19][1] = true; mury[19][2] = true; mury[19][3] = true; mury[19][4] = true; mury[19][5] = true; mury[19][6] = true; mury[19][7] = true; mury[19][8] = true; mury[19][9] = true;
			mury[19][10] = true; mury[19][11] = true; mury[19][12] = true; mury[19][13] = true; mury[19][14] = true; mury[19][15] = true; mury[16][15] = true; mury[16][16] = true; mury[16][17] = true; 
			mury[15][15] = true; mury[15][16] = true; mury[15][17] = true; mury[17][17] = true; mury[18][17] = true; mury[19][17] = true; mury[20][17] = true; mury[21][17] = true; mury[22][17] = true;
			mury[21][16] = true; mury[22][16] = true; mury[21][15] = true; mury[22][15] = true; mury[21][14] = true; mury[22][14] = true; mury[21][13] = true; mury[22][13] = true; mury[21][12] = true; mury[22][12] = true; mury[21][11] = true; mury[22][11] = true; mury[21][10] = true; mury[22][10] = true; mury[21][9] = true; mury[22][9] = true; mury[21][8] = true; mury[22][8] = true; mury[21][7] = true; mury[22][7] = true; mury[21][6] = true; mury[22][6] = true; mury[21][5] = true; mury[22][5] = true; mury[21][4] = true; mury[22][4] = true; mury[21][3] = true; mury[22][3] = true;
		}




	al_convert_mask_to_alpha(gracz, al_map_rgb(0, 255, 255));
	al_convert_mask_to_alpha(pok22, al_map_rgb(255, 0, 255));
	al_convert_mask_to_alpha(gracz1, al_map_rgb(0, 255, 255));
	al_convert_mask_to_alpha(gracz2, al_map_rgb(0, 255, 255));
	al_convert_mask_to_alpha(gracz0, al_map_rgb(0, 255, 255));

	int gracz_x = 96, gracz_y = 512;
	int npc_x = 32, npc_y = 32;
	int mur_x = 0, mur_y = 0;
	int wspmur_x[25][20], wspmur_y[25][20];

	for (int k = 0; k < 20; k++)
		for (int l = 0; l < 15; l++)
		{
			wspmur_x[k][l] = 0;
			wspmur_y[k][l] = 0;
		}


	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	bool zamknij = false;
	bool kolizja = false;
	bool ruch = true, ruch1 = true, ruch2 = true, ruch3 = true, ruch4 = true, ruch5 = true;

	al_start_timer(timer);
	while (!zamknij)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_W:
				keys[W] = true;
				break;
			case ALLEGRO_KEY_S:
				keys[S] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[D] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				zamknij = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_W:
				keys[W] = false;
				break;
			case ALLEGRO_KEY_S:
				keys[S] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[D] = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{

			czas++;

			if (ruch)
			{
				gracz_y -= keys[UP] * 2;
				gracz_y += keys[DOWN] * 2;
				gracz_x -= keys[LEFT] * 2;
				gracz_x += keys[RIGHT] * 2;
			}

			if (!kostka_ruch)// pierwsza przeszkoda
			{
				poz_kostka = poz_kostka + 1; if (poz_kostka == 452) { kostka_ruch = true; }
			}
			if (kostka_ruch) { poz_kostka = poz_kostka - 1; if (poz_kostka == 382) { kostka_ruch = false; } }


			if (!kostka_ruch2)//druga przeszkoda
			{
				poz_kostka2 = poz_kostka2 + 1; if (poz_kostka2 == 770) { kostka_ruch2 = true; }
			}
			if (kostka_ruch2) { poz_kostka2 = poz_kostka2 - 1; if (poz_kostka2 == 704) { kostka_ruch2 = false; } }

			if (!kostka_ruch3)//trzecia przeszkoda
			{
				poz_kostka3 = poz_kostka3 + 2; if (poz_kostka3 == 256) { kostka_ruch3 = true; }
			}
			if (kostka_ruch3) { poz_kostka3 = poz_kostka3 - 2; if (poz_kostka3 == 128) { kostka_ruch3 = false; } }

			if (!kostka_ruch4)//czwarta przeszkoda
			{
				poz_kostka4 = poz_kostka4 + 2; if (poz_kostka4 == 256) { kostka_ruch4 = true; }
			}
			if (kostka_ruch4) { poz_kostka4 = poz_kostka4 - 2; if (poz_kostka4 == 128) { kostka_ruch4 = false; } }

			if (!kostka_ruch5)//piata przeszkoda
			{
				poz_kostka5 = poz_kostka5 + 2; if (poz_kostka5 == 128) { kostka_ruch5 = true; }
			}
			if (kostka_ruch5) { poz_kostka5 = poz_kostka5 - 2; if (poz_kostka5 ==0) { kostka_ruch5 = false; } }

			if (!kostka_ruch6)//szosta przeszkoda
			{
				poz_kostka6 = poz_kostka6 + 2; if (poz_kostka6 == 128) { kostka_ruch6 = true; }
			}
			if (kostka_ruch6) { poz_kostka6 = poz_kostka6 - 2; if (poz_kostka6 == 0) { kostka_ruch6 = false; } }

		}




		if (!kolizja)
		{
			for (int k = 0; k < 25; k++)
				for (int l = 0; l < 20; l++)
				{
					if (mury[k][l]) { al_draw_bitmap(mur, k * 32, l * 32, 0); wspmur_x[k][l] = k * 32; wspmur_y[k][l] = l * 32; }
				}

			for (int i = 0; i < 25; i++)
				for (int j = 0; j < 20; j++)
				{
					if (mury[i][j] == false) { al_draw_bitmap(podloga, i * 32, j * 32, 0); }
				}


			al_draw_bitmap(bok, 800, 0, 0);
			al_draw_bitmap(dol, 0, 640, 0);
			al_draw_bitmap(broken, 416, 224, 0);
			al_draw_bitmap(drzwi, 448, 480, 0);




			if (gracz_x < 32)                               // warunki na ograniczenie przez okno
				gracz_x = 32;
			else if (gracz_x > al_get_display_width(display) - al_get_bitmap_width(gracz) - 32)
				gracz_x = al_get_display_width(display) - al_get_bitmap_width(gracz) - 32;
			if (gracz_y < 32)
				gracz_y = 32;
			else if (gracz_y > al_get_display_height(display) - al_get_bitmap_height(gracz) - 32)
				gracz_y = al_get_display_height(display) - al_get_bitmap_height(gracz) - 32;




			if (gracz_x >= 32 && gracz_x <= 64 && gracz_y >= 32 && gracz_y < 64) {

				if (tablica <= 10) {
					hp = hp - 0.02;
				}
				else if (tablica > 10 && tablica < 20) {
					hp = hp - 5;
				}
				else if (tablica >= 20)
				{
					hp = hp + 10;
				}
			}

			if (gracz_x >= 288 && gracz_x <= 320 && gracz_y >= 32 && gracz_y < 40) {

				kluczyk++;
			}

			if (gracz_x >= 608 && gracz_x <= 640 && gracz_y >= 128 && gracz_y < 150) {

				prezencik++;
			}
			if (poz_kostka == gracz_x && gracz_y >= 352 && gracz_y <= 415) {
				hp = hp - 15;
			}
			if (poz_kostka2 == gracz_x && gracz_y >= 168 && gracz_y <= 232) {
				hp = hp - 15;
			}
			if (poz_kostka3 == gracz_y && gracz_x >= 256 && gracz_x <= 320) {
				hp = hp - 15;
			}
			if (poz_kostka4 == gracz_y && gracz_x >= 418 && gracz_x <= 480) {
				hp = hp - 15;
			}
			if (poz_kostka5 == gracz_y && gracz_x >= 480 && gracz_x <= 542) {
				hp = hp - 15;
			}
			if (poz_kostka6 == gracz_y && gracz_x >= 196 && gracz_x <= 256) {
				hp = hp - 15;
			}



			// zycie
			if (hp <= 100 && hp >= 90) { al_draw_bitmap(zycie10, 320, 660, 0); }
			if (hp < 90 && hp >= 80) { al_draw_bitmap(zycie9, 320, 660, 0); }
			if (hp < 80 && hp >= 70) { al_draw_bitmap(zycie8, 320, 660, 0); }
			if (hp < 70 && hp >= 60) { al_draw_bitmap(zycie7, 320, 660, 0); }
			if (hp < 60 && hp >= 50) { al_draw_bitmap(zycie6, 320, 660, 0); }
			if (hp < 50 && hp >= 40) { al_draw_bitmap(zycie5, 320, 660, 0); }
			if (hp < 40 && hp >= 30) { al_draw_bitmap(zycie4, 320, 660, 0); }
			if (hp < 30 && hp >= 20) { al_draw_bitmap(zycie3, 320, 660, 0); }
			if (hp < 20 && hp >= 10) { al_draw_bitmap(zycie2, 320, 660, 0); }
			if (hp < 10 && hp >= 1) { al_draw_bitmap(zycie1, 320, 660, 0); }
			if (hp < 0) { al_draw_bitmap(zycie0, 320, 660, 0); }


			if (keys[LEFT])
				al_draw_bitmap(gracz2, gracz_x, gracz_y, 0); if (keys[RIGHT]) al_draw_bitmap(gracz0, gracz_x, gracz_y, 0); if (keys[UP])al_draw_bitmap(gracz1, gracz_x, gracz_y, 0); if (keys[DOWN])al_draw_bitmap(gracz, gracz_x, gracz_y, 0); if (!keys[LEFT] && !keys[RIGHT] && !keys[UP] && !keys[DOWN])al_draw_bitmap(gracz, gracz_x, gracz_y, 0);

		}

		for (int k = 0; k < 25; k++)
			for (int l = 0; l < 20; l++)
			{
				if ((wspmur_x[k][l] < gracz_x + al_get_bitmap_width(gracz)) && (wspmur_x[k][l] > gracz_x - al_get_bitmap_width(gracz)) && (wspmur_y[k][l] < gracz_y + al_get_bitmap_height(gracz)) && (wspmur_y[k][l] > gracz_y - al_get_bitmap_height(gracz)))
					ruch = false;


			}



		if (!ruch)
		{
			if (keys[LEFT]) gracz_x += 2; if (keys[RIGHT]) gracz_x -= 2; if (keys[UP]) gracz_y += 2; if (keys[DOWN]) gracz_y -= 2;
			ruch = true;
		}



		bool poziom = true;

		al_start_timer;

		if (poziom) {
			al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 230, ALLEGRO_ALIGN_CENTRE, "x=%d y=%d h=%f ", gracz_x, gracz_y, hp);
			al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 260, ALLEGRO_ALIGN_CENTRE, "t=%f  ", tablica);
			al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 280, ALLEGRO_ALIGN_CENTRE, "klucz=%f ", kluczyk);
			al_draw_textf(font24, al_map_rgb(0, 255, 0), 900, 360, ALLEGRO_ALIGN_CENTRE, "prezent=%f ", prezencik);
			al_draw_textf(czcionka, al_map_rgb(0, 255, 0), 900, 90, ALLEGRO_ALIGN_CENTRE, "czas=%f ", czas);


			if (kluczyk > 1) {

				al_draw_bitmap(zielm, 876, 640, 0);

			}
			else {
				al_draw_bitmap(czem, 876, 640, 0);
			}

			if (prezencik > 1) {
				al_draw_bitmap(zield, 876, 659, 0);

			}
			else {
				al_draw_bitmap(czed, 876, 659, 0);
			}
			if (prezencik > 1 && kluczyk > 1) {
				al_draw_bitmap(zield, 876, 680, 0);
			}
			else {
				al_draw_bitmap(czed, 876, 680, 0);
			}



		}


		if (prezencik > 1 && kluczyk > 1) {
			if (gracz_x == 448 && gracz_y < 486) {


			al_draw_filled_rectangle(300, 300, 600, 600, al_map_rgb(255, 0, 0));
				
				al_flip_display;
			}
		}

		al_draw_bitmap(przeszkoda, poz_kostka, 384, 0);
		al_draw_bitmap(przeszkoda, poz_kostka2, 200, 0);
		al_draw_bitmap(przeszkoda, 288, poz_kostka3, 0);
		al_draw_bitmap(przeszkoda, 448, poz_kostka4, 0);
		al_draw_bitmap(przeszkoda, 512, poz_kostka5, 0);
		al_draw_bitmap(przeszkoda, 224, poz_kostka6, 0);
























		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_bitmap(gracz);
	al_destroy_font(font24);
	al_destroy_font(czcionka);
	al_destroy_display(display);
	return 0;


}




		}






		





	}



	al_destroy_bitmap(fondo1);
	al_destroy_display(display);
	return 0;
}