#include <iostream>
#include "../PluginManager/ITest.h"

class TestImpl : public ITest
{
	public:
		void MemoryTest(std::vector<int> &vec) override
		{
			std::cout << "Number of items: " << vec.size() << std::endl;
		}

		void SayHello() override
		{
			std::cout << "Hello from DLL!" << std::endl;
		}
};



extern "C" __declspec(dllexport) TestImpl* load()
{
	auto *helloWorld = new TestImpl();
	return helloWorld;
}

extern "C" __declspec(dllexport) void unload(TestImpl * helloWorld)
{
	delete helloWorld;
}