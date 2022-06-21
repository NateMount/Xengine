#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

static WINDOW* CTRL_BAR;
static int maxX, maxY;
static int ch;

void xengine_init(){

	initscr();
	raw();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	getmaxyx(stdscr, maxY, maxX);

	CTRL_BAR = newwin(2,maxX,maxY - 5, 0);
	wborder(CTRL_BAR, 0, 0, '#', 0, 0, 0, 0, 0);
	wrefresh(CTRL_BAR);
	refresh();

}

void xengine_inputManager(){

	while ((ch = getchar()) != '@'){

		

	}

}

void xengine_renderView(){



}


void xengine_viewManager(){

	while (1){
		xengine_renderView();
		refresh();
	}

}

void xengine_terminate(){

	wborder(CTRL_BAR,0,0,0,0,0,0,0,0);
	wrefresh(CTRL_BAR);
	delwin(CTRL_BAR);
	endwin();

}

int main( int argc, char* argv[] ){

	if ( strcmp( argv[argc - 1], "--help" ) == 0 ){
		printf("Xengine Help\n");
		exit(EXIT_SUCCESS);
	}

	xengine_init();

	xengine_viewManager();	

	xengine_terminate();
	exit(EXIT_SUCCESS);
}
