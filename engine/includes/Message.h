#pragma once

namespace StrawberryMilk
{
	namespace MessageSystem
	{
		//define here for no duplicity
		enum e_IdMessage
		{

		};
		class Message
		{
		private:
			Message();
			Message(const Message &&);
			Message(const Message &);
			void operator=(const Message &);
		public:
			void * sender;
			e_IdMessage id;
			bool todelete;
			void * content;

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