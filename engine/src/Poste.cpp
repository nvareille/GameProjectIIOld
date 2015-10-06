#include "Poste.h"

namespace StrawberryMilk
{
	namespace MessageSystem
	{

		Poste::Poste()
		{
		}

		bool Poste::toClean(Message * m)
		{
			return (m->readed);
		}

		void Poste::cleanMessage()
		{
			messages.erase(std::remove_if(messages.begin(), messages.end(), toClean), messages.end());
		}

		void Poste::triggerEvent(Message *m)
		{
			events.push_back(m);
		}

		void Poste::attachObserver(AObserver * o)
		{
			obs.push_back(o);
		}

		void Poste::notifyObserver()
		{
			for (unsigned int j = 0; j < events.size(); j++)
			{
				if (!events[j]->readed)
				{
					for (unsigned int i = 0; i < obs.size(); i++)
					{
						if (events[j]->id == obs[i]->getMessageId() &&
							events[j]->target == obs[i])
							obs[i]->update();
					}
				}
			}
		}

		/* old functions*/
		/*
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
		*/

	};
};