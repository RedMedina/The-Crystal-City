/*
  _  __              _                   _____    _____     _____
 | |/ /             | |                 |  __ \  |  __ \   / ____|
 | ' /    ___     __| |   __ _   _   _  | |__) | | |__) | | |  __
 |  <    / _ \   / _` |  / _` | | | | | |  _  /  |  ___/  | | |_ |
 | . \  | (_) | | (_| | | (_| | | |_| | | | \ \  | |      | |__| |
 |_|\_\  \___/   \__,_|  \__,_|  \__, | |_|  \_\ |_|       \_____|
                                  __/ |
                                 |___/

BLOG : https://programacion-cpp.blogspot.com/
WEB  : https://devcpp-allegro.blogspot.com/

Menu con botones y raton 
y ahora con sonido
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

int pantallax = 800;
int pantallay = 450;

ALLEGRO_FONT* font;
ALLEGRO_FONT* font2;

ALLEGRO_SAMPLE* sound1;
ALLEGRO_SAMPLE* sound2;

ALLEGRO_MOUSE_STATE ratonEstado;

class ALLEGRO_MIBOTON
{
    int x, y;
    int alto;
    int ancho;
    const char* texto;
    ALLEGRO_FONT* fuente;

    bool click, encima;

public:

    void crea(int _x, int _y, ALLEGRO_FONT* font, const char* _texto)
    {
        fuente = font;
        x = _x;
        y = _y;
        texto = _texto;

        alto = al_get_font_line_height(fuente) + 8;
        ancho = al_get_text_width(fuente, texto) + 20;

        click = false;
        encima = false;
    }

    void pinta()
    {
        ALLEGRO_COLOR grey;
        ALLEGRO_COLOR grey2;
        ALLEGRO_COLOR grey3;
        ALLEGRO_COLOR black;
        ALLEGRO_COLOR white;

        grey = al_map_rgb(0xe0, 0xe0, 0xe0);
        grey2 = al_map_rgb(0xc0, 0xc0, 0xc0);
        grey3 = al_map_rgb(0x90, 0x90, 0x90);
        black = al_map_rgb(0, 0, 0);
        white = al_map_rgb(155, 155, 155);

        if (ratonEstado.x >= x && ratonEstado.x < x + ancho + 1 && ratonEstado.y >= y && ratonEstado.y < y + alto + 1)
        {
            if (al_mouse_button_down(&ratonEstado, 1))
            {
                //pulsa el raton
                al_draw_text(fuente, black, x + 9.5, y, 0, texto);

                if (!click)
                {
                    al_play_sample(sound2, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    click = true;
                }
            }
            else
            {
                // sin pulsar       
                al_draw_text(fuente, white, x + 9.5, y, 0, texto);

                if (!encima) 
                {
                    al_play_sample(sound1, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    encima = true;
                }

                click = false;
            }
        }
        else
        {      
            al_draw_text(fuente, black, x + 9.5, y, 0, texto);

            encima = false;
            click = false;
        }      
    }

    bool pulsado()
    {
        return (ratonEstado.x >= x && ratonEstado.x < x + ancho + 1 && ratonEstado.y >= y && ratonEstado.y < y + alto + 1) && al_mouse_button_down(&ratonEstado, 1);
    }

};

ALLEGRO_MIBOTON opcionesMenu[4];


struct {
    int FPS;
    ALLEGRO_EVENT_QUEUE* Mis_eventos;
    ALLEGRO_COLOR fondo;
    ALLEGRO_BITMAP* img;
} sistema;


void dibuja()
{
    al_draw_bitmap(sistema.img,0,0,0);

    for (int i = 0; i < 4; i++)
    {
        opcionesMenu[i].pinta();
    }

    al_draw_text(font, al_map_rgb(50, 0, 0), 57, 382, 0, "KodayRPG 2020");
    al_draw_text(font, al_map_rgb(250, 150, 0), 55, 380, 0, "KodayRPG 2020");
    
    if (opcionesMenu[1].pulsado())
    {
        al_draw_text(font2, al_map_rgb(230, 200, 0), 295, 80, 0, "Has pulsado Opcion 1");
        
    }
    if (opcionesMenu[2].pulsado())
    {
        al_draw_text(font2, al_map_rgb(230, 200, 0), 295, 80, 0, "Has pulsado Opcion 2");
    }

       // muestra por pantalla
    al_flip_display();
}

void jugar(ALLEGRO_EVENT evento)
{

    ALLEGRO_BITMAP* img1 = al_load_bitmap("datos/menu2.png");
    ALLEGRO_MIBOTON volver;
    volver.crea(350, 90, font2, " Volver ");
    bool salir = false;
    while (!salir)
    {

        al_clear_to_color(al_map_rgb(240, 200, 0));
        al_draw_bitmap(img1, 0, 0, 0);
        volver.pinta();
        al_flip_display();

        
        al_wait_for_event(sistema.Mis_eventos, &evento);
        // pasa un tiempo determinado
        if (evento.type == ALLEGRO_EVENT_TIMER)
        {
            al_get_mouse_state(&ratonEstado);
        }

        if (volver.pulsado()) salir = true;
    }
}

void update(ALLEGRO_EVENT evento)
{
    if (opcionesMenu[0].pulsado())
    {      
        jugar(evento);
    }
}


void juego()
{
    font = al_load_ttf_font("datos/neuropol.ttf", 64, 0);
    font2 = al_load_ttf_font("datos/Dimbo.ttf", 32, 0);

    opcionesMenu[0].crea(350, 130, font2, " JUGAR ");
    opcionesMenu[1].crea(340, 180, font2, " OPCION 1 ");
    opcionesMenu[2].crea(340, 230, font2, " OPCION 2 ");
    opcionesMenu[3].crea(350, 280, font2, " SALIR ");

    ALLEGRO_EVENT evento;
    bool repetir = true;
    bool dibujar = true;

    while (repetir)
    {
        // Pinta si es dibuja y esta vacia la lista de eventos
        if (dibujar && al_event_queue_is_empty(sistema.Mis_eventos))
        {
            dibuja();
            dibujar = false;
        }

        // esperamos a que ocurra un evento
        al_wait_for_event(sistema.Mis_eventos, &evento);

        // se ha cerrado la ventana
        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            repetir = false;
        }

        // se ha pulsado ESC
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE )
            {
                repetir = false;
            }
        }

        // pasa un tiempo determinado
        if (evento.type == ALLEGRO_EVENT_TIMER)
        {
            dibujar = true;
            update(evento);
            al_get_mouse_state(&ratonEstado);
            if (opcionesMenu[3].pulsado() )
            {
                repetir = false;
            }
        }
    }
    al_destroy_font(font2);
    al_destroy_font(font);
}


int main(void)
{
    // inicializamos las librerías
    al_init();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();
    al_init_acodec_addon();
    al_install_audio();


    ALLEGRO_DISPLAY* display = al_create_display(800, 450);
    ALLEGRO_TIMER* timer = NULL;

    al_set_window_title(display, "KodayRPG - Menu");
    
    al_reserve_samples(2);

    sound1 = al_load_sample("datos/button1.wav");
    sound2 = al_load_sample("datos/click.wav");

    sistema.img = al_load_bitmap("datos/menu1.png");
    sistema.fondo = al_map_rgb(40, 40, 120);
    sistema.FPS = 60;
    timer = al_create_timer(1.0 / sistema.FPS);

    // creo lista de eventos
    sistema.Mis_eventos = al_create_event_queue();

    // asigno eventos a la lista de eventos
    al_register_event_source(sistema.Mis_eventos, al_get_keyboard_event_source());
    al_register_event_source(sistema.Mis_eventos, al_get_display_event_source(display));
    al_register_event_source(sistema.Mis_eventos, al_get_timer_event_source(timer));
    al_start_timer(timer);

    juego();

    al_destroy_sample(sound1);
    al_destroy_sample(sound2);
    al_destroy_display(display);
}