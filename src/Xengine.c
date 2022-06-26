#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>

#include "xengine_util.h"
#include "xengine_applib.h"
#include "xengine_std.h"

static int maxX, maxY;
static int ch;
static int mode;
static App apps[MAX_APPS];

void* xengine_inputManager( void* cfg ){

	while (1) {
		ch = getchar();
	}

}

void xengine_renderView(){

	int i;
	char* u;

	for (i = 0; i < MAX_APPS; i++){

		if ( apps[i] != NULL ) {
		
			if (apps[i]->update != NULL){
				u = (char*) apps[i]->update(xengine_std_keyboardEvent(ch, mode), apps[i]->buff);
				mvwprintw(apps[i]->view, 1,1, u);
			}

			wrefresh(apps[i]->view);
		}

	}

}


void* xengine_viewManager( void* cfg ){

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

	curs_set(1);

	endwin();

}

int main( int argc, char* argv[] ){

	if ( strcmp( argv[argc - 1], "--help" ) == 0 ){
		printf("Xengine Help\n");
		exit(EXIT_SUCCESS);
	}

	pthread_t display_manager;
	pthread_t input_manager;

	initscr();
	raw();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, maxY, maxX);

	mode = COMMAND;

	curs_set(0);

	apps[0] = makeApp(25, 50, 10, 10, "NotePad", "", NULL, xengine_std_passthroughUpdate);
	renderApp(apps[0]);

	pthread_create(&display_manager, NULL, xengine_viewManager, NULL);
	pthread_create(&input_manager, NULL, xengine_inputManager, NULL);

	pthread_join(input_manager, NULL);
	pthread_join(display_manager, NULL);

	xengine_terminate();
	exit(EXIT_SUCCESS);
}
