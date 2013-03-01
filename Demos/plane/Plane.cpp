#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");
	
	ngl_plane plane_A;
	ngl_plane plane_B;
	ngl_plane plane_C;
	
	ngl_entity graphic1;
	graphic1.load("p1_g1.png");

	graphic1.x=170;
	graphic1.y=90;
	plane_A.add(&graphic1);

	ngl_entity graphic2;
	graphic2.load("p1_g2.png");

	graphic2.x=320;
	graphic2.y=90;
	plane_A.add(&graphic2);

	ngl_entity graphic3;
	graphic3.load("p1_g3.png");

	graphic3.x=470;
	graphic3.y=90;
	plane_A.add(&graphic3);

	ngl_entity graphic4;
	graphic4.load("p2_g1.png");

	graphic4.x=170;
	graphic4.y=240;
	plane_B.add(&graphic4);

	ngl_entity graphic5;
	graphic5.load("p2_g2.png");

	graphic5.x=320;
	graphic5.y=240;
	plane_B.add(&graphic5);

	ngl_entity graphic6;
	graphic6.load("p2_g3.png");

	graphic6.x=470;
	graphic6.y=240;
	plane_B.add(&graphic6);
	
	ngl_entity graphic7;
	graphic7.load("p3_g1.png");

	graphic7.x=170;
	graphic7.y=390;
	plane_C.add(&graphic7);

	ngl_entity graphic8;
	graphic8.load("p3_g2.png");

	graphic8.x=320;
	graphic8.y=390;
	plane_C.add(&graphic8);

	ngl_entity graphic9;
	graphic9.load("p3_g3.png");

	graphic9.x=470;
	graphic9.y=390;
	plane_C.add(&graphic9);

	plane_A.paint();
	plane_B.paint();
	plane_C.paint();
	
	ngl_frame();

	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			break;
		}
	}

	graphic1.unload();
	graphic2.unload();
	graphic3.unload();
	graphic4.unload();
	graphic5.unload();
	graphic6.unload();
	graphic7.unload();
	graphic8.unload();
	graphic9.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
