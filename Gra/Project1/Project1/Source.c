
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

enum KEYS { UP, DOWN, LEFT, RIGHT, W, S, A, D };

int main(void)
{
	int widht = 1000;
	int height = 700;

	bool done = false;
	bool draw = true;
	int pos_x = NULL;
	int pos_y = NULL;


	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *gameo = NULL;
	ALLEGRO_BITMAP *fondo1 = NULL;
	ALLEGRO_BITMAP *fondo2 = NULL;
	ALLEGRO_BITMAP *fondo3 = NULL;
	ALLEGRO_BITMAP *fondo4 = NULL;
	ALLEGRO_BITMAP *cursor = NULL;
	ALLEGRO_BITMAP *gracz = NULL;
	ALLEGRO_BITMAP *gracz0 = NULL;
	ALLEGRO_BITMAP *gracz1 = NULL;
	ALLEGRO_BITMAP *gracz2 = NULL;
	ALLEGRO_BITMAP *mur = NULL;
	ALLEGRO_SAMPLE *sample = NULL;

	const int FPS = 60;


	bool keys[8] = { false, false, false, false, false, false, false, false };

	if (!al_init())
		return -1;


	display = al_create_display(widht, height);
	timer = al_create_timer(1.0 / FPS);

	al_init_image_addon();
	al_init_primitives_addon();
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

	fondo1 = al_load_bitmap("fondo1.bmp");
	al_convert_mask_to_alpha(fondo1, al_map_rgb(255, 0, 255));
	fondo2 = al_load_bitmap("fondo2.bmp");
	al_convert_mask_to_alpha(fondo2, al_map_rgb(255, 0, 255));
	fondo3 = al_load_bitmap("fondo3.bmp");
	al_convert_mask_to_alpha(fondo3, al_map_rgb(255, 0, 255));
	fondo4 = al_load_bitmap("fondo4.bmp");
	al_convert_mask_to_alpha(fondo4, al_map_rgb(255, 0, 255));
	cursor = al_load_bitmap("cursor.bmp");
	al_convert_mask_to_alpha(cursor, al_map_rgb(255, 0, 255));
	gracz = al_load_bitmap("grafika\\gracze\\mojemario2.pcx");
	al_convert_mask_to_alpha(gracz, al_map_rgb(255, 0, 255));
    gracz0 = al_load_bitmap("grafika\\gracze\\mojemario.pcx");
	al_convert_mask_to_alpha(gracz0, al_map_rgb(255, 0, 255));
    gracz1 = al_load_bitmap("grafika\\gracze\\mojemario1.pcx");
	al_convert_mask_to_alpha(gracz1, al_map_rgb(255, 0, 255));
    gracz2 = al_load_bitmap("grafika\\gracze\\mojemario3.pcx");
	al_convert_mask_to_alpha(gracz2, al_map_rgb(255, 0, 255));
	
	mur = al_load_bitmap("grafika\\bloczki\\mur.pcx");



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
				if (pos_x > 393 && pos_x < 647 && pos_y> 312 && pos_y < 355) {
					opcja = 0;
				}
				else if (pos_x > 438 && pos_x < 590 && pos_y> 415 && pos_y < 469) {

					opcja=1;
				}
				else if (pos_x > 435 && pos_x < 593 && pos_y> 525 && pos_y < 579) {
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
		if (pos_x > 393 && pos_x < 647 && pos_y> 312 && pos_y < 355) {

			al_draw_bitmap(fondo2, 0, 0, 0);

		}
		else if (pos_x > 438 && pos_x < 590 && pos_y> 415 && pos_y < 469) {

			al_draw_bitmap(fondo3, 0, 0, 0);
			
		}
		else if (pos_x > 435 && pos_x < 593 && pos_y> 525 && pos_y < 579) {

			al_draw_bitmap(fondo4, 0, 0, 0);
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
		
		
		
		switch (opcja)
		{
		case 0: {

			bool ekrangry = false;
			while (!ekrangry) {

				/////////
				al_destroy_sample(sample);
		
				
				ALLEGRO_FONT *font24 = al_create_builtin_font();
				

		
				

				ALLEGRO_BITMAP *npc = NULL;
				npc = al_load_bitmap("grafika\\gracze\\gracz1.pcx");

				ALLEGRO_BITMAP *mur = NULL;
				mur = al_load_bitmap("grafika\\bloczki\\mur.pcx");
				ALLEGRO_BITMAP *pok22 = al_create_sub_bitmap(npc, 0, 64, 32, 32);


				bool mury[25][20];


				for (int i = 0; i < 25; i++)
					for (int j = 0; j < 20; j++)
					{
						mury[i][j] = false;

					}

				for (int i = 0; i < 25; i++)
					for (int j = 0; j < 20; j++)
					{
						if (i == 0 || i == 24 || j == 0 || j == 19)
							mury[i][j] = true;

						// Sciany
						mury[1][3] = true; mury[2][3] = true; mury[3][3] = true; mury[4][3] = true; mury[5][3] = true; mury[8][1] = true; mury[8][2] = true;
						mury[8][3] = true; mury[9][3] = true; mury[10][3] = true; mury[11][3] = true;  mury[13][3] = true; mury[14][3] = true;
						mury[15][3] = true; mury[15][2] = true; mury[15][1] = true; mury[15][4] = true; mury[15][5] = true; mury[15][6] = true; mury[15][7] = true;
						mury[15][8] = true; mury[15][9] = true; mury[15][10] = true; mury[15][11] = true; mury[14][11] = true; mury[13][11] = true; mury[12][11] = true;
						mury[11][11] = true; mury[10][11] = true; mury[3][6] = true; mury[3][7] = true; mury[3][8] = true; mury[3][9] = true; mury[3][10] = true;
						mury[3][11] = true; mury[3][12] = true; mury[3][13] = true; mury[4][13] = true; mury[5][13] = true;  mury[5][14] = true; mury[5][15] = true;
						mury[5][16] = true; mury[5][17] = true; mury[5][18] = true; mury[1][15] = true; mury[2][15] = true; mury[5][6] = true; mury[4][6] = true;
						mury[6][6] = true; mury[7][6] = true; mury[8][6] = true; mury[9][6] = true; mury[10][6] = true; mury[11][6] = true; mury[12][6] = true;
						mury[12][7] = true; mury[12][8] = true; mury[11][8] = true;   mury[10][8] = true; mury[9][8] = true; mury[8][8] = true; mury[7][8] = true;
						mury[7][9] = true; mury[7][10] = true; mury[7][11] = true; mury[7][12] = true; mury[7][13] = true; mury[7][14] = true; mury[8][14] = true;
						mury[9][14] = true; mury[10][14] = true; mury[11][14] = true; mury[12][14] = true; mury[13][14] = true; mury[14][14] = true;
						mury[15][14] = true; mury[16][14] = true; mury[17][14] = true; mury[18][14] = true; mury[18][13] = true; mury[18][12] = true;
						mury[18][11] = true; mury[18][10] = true; mury[18][9] = true; mury[18][8] = true; mury[18][7] = true; mury[18][6] = true;
						mury[18][5] = true; mury[18][4] = true; mury[18][3] = true; mury[19][3] = true; mury[20][3] = true; mury[21][3] = true;
						mury[21][4] = true; mury[21][5] = true; mury[21][6] = true; mury[20][6] = true; mury[19][6] = true; mury[21][3] = true;
						mury[19][10] = true; mury[20][10] = true; mury[21][10] = true; mury[22][8] = true; mury[23][8] = true; mury[21][11] = true;
						mury[21][12] = true; mury[21][13] = true; mury[21][14] = true; mury[21][15] = true; mury[21][16] = true; mury[10][15] = true;
						mury[10][16] = true; mury[10][17] = true; mury[10][18] = true; mury[11][15] = true; mury[12][15] = true; mury[20][16] = true;
						mury[13][15] = true; mury[14][15] = true; mury[14][16] = true; mury[14][17] = true;  mury[15][17] = true; mury[19][16] = true;
						mury[19][17] = true; mury[18][17] = true; mury[17][17] = true; mury[16][17] = true;



					}

				
			
		

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
						if (ruch)
						{
							gracz_y -= keys[UP] * 2;
							gracz_y += keys[DOWN] * 2;
							gracz_x -= keys[LEFT] * 2;
							gracz_x += keys[RIGHT] * 2;
						}

					}
				

					if (!kolizja)
					{
						for (int k = 0; k < 25; k++)
							for (int l = 0; l < 20; l++)
							{
								if (mury[k][l])
								{
									al_draw_bitmap(mur, k * 32, l * 32, 0);
									wspmur_x[k][l] = k * 32;
									wspmur_y[k][l] = l * 32;
								}

							}


						if (gracz_x < 32)                               // warunki na ograniczenie przez okno
							gracz_x = 32;
						else if (gracz_x > al_get_display_width(display) - al_get_bitmap_width(gracz) - 32)
							gracz_x = al_get_display_width(display) - al_get_bitmap_width(gracz) - 32;
						if (gracz_y < 32)
							gracz_y = 32;
						else if (gracz_y > al_get_display_height(display) - al_get_bitmap_height(gracz) - 32)
							gracz_y = al_get_display_height(display) - al_get_bitmap_height(gracz) - 32;








						if (keys[LEFT])
							al_draw_bitmap(gracz2, gracz_x, gracz_y, 0);
						if (keys[RIGHT])
							al_draw_bitmap(gracz0, gracz_x, gracz_y, 0);
						if (keys[UP])
							al_draw_bitmap(gracz1, gracz_x, gracz_y, 0);
						if (keys[DOWN])
							al_draw_bitmap(gracz, gracz_x, gracz_y, 0);
						if (!keys[LEFT] && !keys[RIGHT] && !keys[UP] && !keys[DOWN])
							al_draw_bitmap(gracz, gracz_x, gracz_y, 0);





					}

					for (int k = 0; k < 25; k++)
						for (int l = 0; l < 20; l++)
						{
							if ((wspmur_x[k][l] < gracz_x + al_get_bitmap_width(gracz)) &&
								(wspmur_x[k][l] > gracz_x - al_get_bitmap_width(gracz)) &&
								(wspmur_y[k][l] < gracz_y + al_get_bitmap_height(gracz)) &&
								(wspmur_y[k][l] > gracz_y - al_get_bitmap_height(gracz)))

								ruch = false;


						}

					if (!ruch)
					{


						if (keys[LEFT])
							gracz_x += 2;
						if (keys[RIGHT])
							gracz_x -= 2;
						if (keys[UP])
							gracz_y += 2;
						if (keys[DOWN])
							gracz_y -= 2;


						ruch = true;
					}
					bool poziom = true;
					if (poziom)
						al_draw_textf
						(

							font24, al_map_rgb(0, 255, 0), al_get_display_width(display) / 2, 670, ALLEGRO_ALIGN_CENTRE, "x=%d y=%d", gracz_x, gracz_y
						);


					



					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
				}

				al_destroy_bitmap(gracz);
				al_destroy_bitmap(npc);
				al_destroy_font(font24);
				al_destroy_display(display);
				return 0;

			





			}

			//

		}

				break;

		case 1: {
			
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
					}
				}


				al_flip_display();
			}
		

		}
				break;
		}





	}


	al_destroy_bitmap(fondo1);
	al_destroy_display(display);
	return 0;
}