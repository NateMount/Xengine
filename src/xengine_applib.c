#include "xengine_applib.h"

updateObj makeUpdateObject(void* data, unsigned char mode, unsigned int signal){

	updateObj new = (updateObj) malloc(sizeof(struct _update_object_st));
	new->data = data;
	new->mode = mode;
	new->signal = signal;

	return new;

}

void delUpdateObject(updateObj obj){

	free(obj);

}

App makeApp(int height, int width, int start_x, int start_y, char* name, updateObj (*init)(void), void* (*update)(updateObj event)){

	App new = (App) malloc(sizeof(struct _app_st));
	new->id = name;
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


void renderApp( App app ){

	refresh();
	box(app->view, 0, 0);
	mvwprintw(app->view,0,1,"[ %s ]", app->id);
	wrefresh(app->view);

}
