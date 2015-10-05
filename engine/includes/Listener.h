#pragma once
#include "Message.h"
#include "Ilistener.h"

namespace StrawberryMilk
{
	namespace MessageSystem
	{
		class MessageListener
		{
		private:
			MessageListener();
		public:
			e_IdMessage id;
			IListener *ptr;
			void *sender;
			MessageListener(e_IdMessage _id, IListener * _ptr, void * _sender)
			{
				id = _id;
				ptr = _ptr;
				sender = _sender;
			};
		};
	};
};