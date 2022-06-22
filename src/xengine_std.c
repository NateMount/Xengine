#include "xengine_std.h"

updateObj xengine_std_keyboardEvent(int ch, unsigned char mode){

	updateObj new = makeUpdateObject( (void*) ch, mode, SIGNULL );
	return new;

}

void* xengine_std_passthroughUpdate( updateObj obj ){

	char* tmp = (char*) obj->data;

	delUpdateObject( obj );
	
	return tmp;

}
