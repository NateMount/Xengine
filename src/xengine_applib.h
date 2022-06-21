#ifndef __xengine_applib
#define __xengine_applib

#define MAX_APPS 12

typedef struct _app_st {

	WINDOW* view;
	void* (*init)(void*);
	void* (*update)(void*);

} * App;



/// Make App
/// Function used to create an app instance to be rendered in xengine
///
/// @param start_x : window starting x position
/// @param start_y : window starting y position
/// @param height : window height
/// @param width : window width
/// @param init : intilization function to be run prior to app being rendered
/// @param update : update function to be run each frame
/// @return App: returns an App struct pointer
App makeApp(int start_x, int start_y, int height, int width, void* (*init)(void*), void* (*update)(void*));

/// Delete App
/// Function to delete an App instance
///
/// @param app : App to be deleted
void delApp(App app);

#endif
