#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <stdlib.h>

#include "xengine_applib.h"
#include "xengine_std.h"

static int maxX, maxY;
static int ch;
static int mode;
static App apps[MAX_APPS];
static char* views[MAX_APPS];

void xengine_inputManager(){

	int i;

	while (1){

		ch = getchar();

	}

}

void xengine_renderView(){

	int i;
	char* u;

	for (i = 0; i < MAX_APPS; i++){

		if ( apps[i] != NULL ) {
		
			if (apps[i]->update != NULL){
				u = (char*) apps[i]->update(xengine_std_keyboardEvent(ch, mode));
				//mvwprintw(apps[i]->view, 0,0, u);
			}

			wrefresh(apps[i]->view);
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
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, maxY, maxX);

	curs_set(0);


	apps[0] = makeApp(50, 100, 5, 20, "Mark", NULL, NULL);
	renderApp(apps[0]);

	xengine_viewManager();	

	xengine_terminate();
	exit(EXIT_SUCCESS);
}
