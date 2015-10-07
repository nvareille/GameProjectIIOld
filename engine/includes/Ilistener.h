#pragma once

namespace StrawberryMilk
{
	namespace MessageSystem
	{
		class IListener
		{
		public:
			virtual void listenMessage(void *)=0;
		};
	};
};