#include "xengine_std.h"

updateObj xengine_std_keyboardEvent(int ch, unsigned char mode){

	updateObj new = makeUpdateObject( (void*) ch, mode, SIGNULL );
	return new;

}

char* xengine_std_passthroughUpdate( updateObj obj, char* buff ){

	if (obj->data != NULL){
		strncat(buff, (char*) obj->data, 1);
	}

	delUpdateObject( obj );

	return buff;

}

char* xengine_std_helloXengineUpdate( updateObj obj, char* buff ){

	delUpdateObject( obj );

	return "Hello Xengine";

}
