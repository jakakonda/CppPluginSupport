#ifndef KPL_IGREETINGS_H
#define KPL_IGREETINGS_H

class IGreetings
{
	public:
		virtual ~IGreetings()
		{
		}

		virtual void Hello() = 0;
};


#endif // KPL_IGREETINGS_H