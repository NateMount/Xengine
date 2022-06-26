#ifndef __xengine_applib
#define __xengine_applib

#include <ncurses.h>
#include <stdlib.h>

#include "xengine_util.h"

#define MAX_APPS 25

// Update Signals
#define SIGNULL 0
#define INIT_FAILURE 1
#define INIT_WAIT 2
#define INIT_DROP 3
#define FREEZE 4
#define THAW 5
#define HIDE 6
#define SHOW 7
#define PETRIFY 8
#define FREE 9
#define MULTISIG(sigA, sigB) (( sigA * 10 ) + sigB )

// Xengine Mode
#define COMMAND 0
#define INTERFACE 1
#define PREKILL 2
#define DEBUG 3
#define WAITING 4
#define INIT 5
#define PRE_INIT 6

typedef struct _update_object_st {
	void* data;
	unsigned char mode;
	unsigned int signal;
}* updateObj;

typedef struct _app_st {
	WINDOW* view;
	char* id;
	char* buff;
	updateObj (*init)(void);
	char* (*update)( updateObj event, char* buff );
} * App;


/// Make Update Object
/// Function used to generate an update object
///
/// @param data : data to be passed to update function
/// @param mode : current mode of Xengine
/// @param signal : any signals to be passed to the update functions
///
/// @return updateObj: returns an updateObj struct pointer
updateObj makeUpdateObject(void* data, unsigned char mode, unsigned int signal);

/// Delete Update Object
/// Used to delete an update object from memory
///
/// @param obj : Update Object to be deleted
void delUpdateObject(updateObj obj);

/// Make App
/// Function used to create an app instance to be rendered in xengine
///
/// @param start_x : window starting x position
/// @param start_y : window starting y position
/// @param height : window height
/// @param width : window width
/// @param init : intilization function to be run prior to app being rendered
/// @param update : update function to be run each frame
///
/// @return App: returns an App struct pointer
App makeApp(int height, int width, int start_x, int start_y, char* name, char* buff, updateObj (*init)(void), char* (*update)(updateObj event, char* buff));

/// Delete App
/// Function to delete an App instance
///
/// @param app : App to be deleted
void delApp(App app);

/// Render App
/// Function to properly render an app in accordance with Xengine standards
///
/// @param app : App to be rendered
void renderApp( App app );

#endif
