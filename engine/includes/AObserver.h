#pragma once
#include <vector>
#include "Message.h"

namespace StrawberryMilk
{
	namespace MessageSystem
	{
		//define here for no duplicity
		enum e_IdMessage
		{
			MAINPLAYERDEAD
		};

		class AObserver
		{
		private:
			e_IdMessage sub;
		public:
			AObserver(e_IdMessage _sub)
			{
				sub = _sub;
			}

			virtual void update() = 0;

			e_IdMessage getMessageId()
			{
				return sub;
			}

			void getMessageId(e_IdMessage id)
			{
				sub = id;
			}
		};
	};
};