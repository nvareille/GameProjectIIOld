#pragma once
#include "AObserver.h"
namespace StrawberryMilk
{
	namespace MessageSystem
	{
		class Message
		{
		private:
			Message();
			Message(const Message &&);
			Message(const Message &);
			void operator=(const Message &);
		public:

			e_IdMessage id;


			//new
			AObserver * target;
			bool readed;
			Message(e_IdMessage _id, AObserver * _target)
			{
				id = _id;
				readed = false;
				target = _target;
			};
			//old
			bool todelete;
			void * content;
			void * sender;
			Message(e_IdMessage _id, void * _sender, void * _content)
			{
				id = _id;
				content = _content;
				todelete = false;
				sender = _sender;
			};
		};
	};
};