#ifndef KPL_IGREETINGS_H
#define KPL_IGREETINGS_H

#include <iostream>
#include <vector>
#include <memory>

class ITest
{
	public:
		virtual ~ITest()
		{
		}

		virtual void MemoryTest(std::vector<int> &vec) = 0;
		virtual void SayHello() = 0;
};


#endif // KPL_IGREETINGS_H