#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

#include "XengineConfig"

void xengine_init(){

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);

}

void xengine_renderView(){

}

void xengine_viewManager(){

	while (1){

		xengine_renderView();

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
