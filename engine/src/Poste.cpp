#include "Poste.h"

namespace StrawberryMilk
{
	namespace MessageSystem
	{

		void Poste::suscribe(MessageListener *l)
		{
			listeners.push_back(l);
		}

		void Poste::sendmessage()
		{
			std::vector< Message *>::iterator itm;
			std::vector <MessageListener *>::iterator  itl;
			for (itm = messages.begin(); itm != messages.end(); ++itm)
			{
				for (itl = listeners.begin(); itl != listeners.end(); ++itl)
				{
					if ((*itl)->sender == (*itm)->sender && (*itl)->id == (*itm)->id)
					{
						((*itl)->ptr)->listenMessage((*itm)->content);
						(*itm)->todelete = true;
					}
				}
				

			}
		}

		void Poste::addMessage( Message * m)
		{
			messages.push_back(m);
		}

		bool Poste::toClean( Message * m)
		{
			return (m->todelete);
		}

		void Poste::cleanMessage()
		{
			messages.erase(std::remove_if(messages.begin(), messages.end(), toClean), messages.end());
		}
	};
};