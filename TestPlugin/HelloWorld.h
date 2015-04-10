#pragma once

#include <iostream>
#include "../PluginManager/IGreetings.h"

class HelloWorld : public IGreetings
{
	public:
		void Hello() override 
		{
			std::cout << "Hello World from DLL!" << std::endl;
		};
};

