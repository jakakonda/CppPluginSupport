#include "HelloWorld.h"

extern "C" __declspec(dllexport) HelloWorld* load()
{
	auto *helloWorld = new HelloWorld();
	return helloWorld;
}

extern "C" __declspec(dllexport) void unload(HelloWorld * helloWorld)
{
	delete helloWorld;
}