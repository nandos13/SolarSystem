#include "Application2D.h"
//#include "Vector2.h"
//#include "Vector3.h"
//#include "Vector4.h"

int main() {
	
	BaseApplication* app = new Application2D();
	if (app->startup())
		app->run();
	app->shutdown();

	return 0;
}