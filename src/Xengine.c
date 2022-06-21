#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

#include "xengine_applib.h"

static int maxX, maxY;
static int ch;
static App apps[MAX_APPS];

void xengine_inputManager(){

	while ((ch = getchar()) != '@'){

		

	}

}

void xengine_renderView(){

	mvprintw(10,10,"God please work");

}


void xengine_viewManager(){

	while (1){
		xengine_renderView();
		refresh();
	}

}

void xengine_terminate(){

	int i;

	for (i = 0; i < MAX_APPS; i++){
		delApp(apps[i]);
	}

	endwin();

}

int main( int argc, char* argv[] ){

	if ( strcmp( argv[argc - 1], "--help" ) == 0 ){
		printf("Xengine Help\n");
		exit(EXIT_SUCCESS);
	}


	initscr();
	raw();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, maxY, maxX);

	apps[0] = makeApp(10,10,20,20,NULL,NULL);

	xengine_viewManager();	

	xengine_terminate();
	exit(EXIT_SUCCESS);
}
