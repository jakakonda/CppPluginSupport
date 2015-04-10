#include <iostream>
#include <iostream>
#include <string>

#include "Plugin.h"
#include "IGreetings.h"

using namespace std;
using namespace plugin_manager;

int main()
{
	Plugin<IGreetings> greetingsPlugin("TestPlugin", "load", "unload");

	auto pl = greetingsPlugin.Load();
	pl->Hello();

	return 0;
}