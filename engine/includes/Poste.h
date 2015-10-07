#pragma once
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "Message.h"
#include "Listener.h"
#include "Ilistener.h"
#include "AObserver.h"

namespace StrawberryMilk
{
	namespace MessageSystem
	{
		class Poste
		{
		private:

			Poste(const Poste &&);
			Poste(const Poste &);
			void operator=(const Poste &);

			//new
			std::vector<AObserver *> obs;
			std::vector<Message *> events;

			//old
			std::vector<Message *> messages;
			std::vector<MessageListener *> listeners;
			//old method		
			void suscribe(MessageListener *);
			void sendmessage();
			void addMessage(Message *);

		public:

			Poste();
			void cleanMessage();
			static bool toClean(Message *);

			// new method
			void triggerEvent(Message *);
			void attachObserver(AObserver *);
			void notifyObserver();



		};
	};
};
