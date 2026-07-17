#include <stdio.h>
#include "../fw.h"

// Fill [x0,y0)..[x1,y1) with wrapping text at cell size 6, 8, or 16.
static void fill_lorem(int x0, int y0, int x1, int y1, int size, const char* text, uint32_t color){
	int x=x0;
	int y=y0;
	const char* p=text;
	while(y+size<=y1){
		if(*p=='\0')p=text; // repeat to fill
		char c=*p++;
		if(c=='\n'||x+size>x1){
			x=x0;
			y+=size;
			if(c=='\n')continue;
			if(y+size>y1)break;
		}
		if(size==6)draw_char_6(x,y,c,color);
		else if(size==8)draw_char_8(x,y,c,color);
		else draw_char_16(x,y,c,color);
		x+=size;
	}
}

void main(){
	fw_init("test");



	Image* image=load_image("./test/res/image.img");

	const char* lorem=
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod "
		"tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, "
		"quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
		"Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu "
		"fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
		"culpa qui officia deserunt mollit anim id est laborum. ";

	while(!is_termination_requested()){
		begin_frame();

		draw_line(5, 5, 100, 100, 0xFF0000FF, 0x00FF00FF);
		draw_triangle(5,5,100,100,100,5,0xFFFFFFFF,0xFF0000FF,0x00FF00FF);
		// Three bands: 6x6, 8x8, 16x16
		fill_lorem(0,0,640,120,6,lorem,0xFFFFFFFF);
		fill_lorem(0,120,640,240,8,lorem,0xAAAAAAFF);
		fill_lorem(0,240,640,360,16,lorem,0x55FF55FF);
		draw_image_region(image, 100, 100, 10, 0, -100, 20);
		end_frame();
	}

	fw_close();
}
