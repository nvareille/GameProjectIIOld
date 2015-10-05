#pragma once
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "Message.h"
#include "Listener.h"
#include "Ilistener.h"


namespace StrawberryMilk
{
	namespace MessageSystem
	{
		class Poste
		{
		private:
			std::vector<Message *> messages;
			std::vector<MessageListener *> listeners;
		public:
			static bool toClean(Message *);
			void suscribe(MessageListener *);
			void sendmessage();
			void addMessage(Message *);
			void cleanMessage();
		};
	};
};
