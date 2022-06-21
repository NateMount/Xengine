#include <ncurses.h>
#include <stdlib.h>
#include "xengine_applib.h"

App makeApp(int start_x, int start_y, int height, int width, void* (*init)(void*), void* (*update)(void*)){

	App new = (App) malloc(sizeof(struct _app_st));
	new->view = newwin(height, width, start_y, start_x);
	new->init = init;
	new->update = update;

	return new;

}

void delApp(App app){

	wborder(app->view, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(app->view);
	delwin(app->view);

	free(app);

}
