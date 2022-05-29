#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

#include "XengineConfig"

typedef struct xengine_app {
	int posX;
	int posY;
	int lenX;
	int lenY;
	char* (*getView)(void*);
} * App;

static App applications[MAX_APPLICATIONS + 1];

void xengine_init(){

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

}

void xengine_renderWidget(App win){

	int x;
	int y;
	char* view = win->getView(NULL);

	for (y = 0; y < win->lenY; y++){

		for (x = 0; x < win->lenX; x++){

			mvprintw(win->posY + y, win->posX + x, "%c", view[x + (y * win->lenY) - 1]);

		}

	}

}

void xengine_renderView(){

	int i;

	for (i = 0; i < MAX_APPLICATIONS + 1; i++){
		if (applications[i] != NULL){
			xengine_renderWidget(applications[i]);
		}
	}

}

void xengine_viewManager(){

	while (1){
		xengine_renderView();
		refresh();
	}

}

void xengine_terminate(){

	endwin();

}

int main( int argc, char* argv[] ){

	if ( strcmp( argv[argc - 1], HELP_FLAG ) == 0 ){
		printf("Xengine Help\n");
		exit(EXIT_SUCCESS);
	}

	xengine_init();

	xengine_viewManager();	

	xengine_terminate();
	exit(EXIT_SUCCESS);
}
