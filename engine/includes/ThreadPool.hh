#pragma once

#include <vector>
#include <thread>
#include <mutex>
#include <list>
#include <condition_variable>
#include <functional>

namespace StrawberryMilk
{
	namespace Thread
	{
		class ThreadPool
		{
		private:

			unsigned int maxThreads;
			unsigned int workingThreads;
			bool closedpool;
			std::condition_variable condvarTasks; //to improve : encapsulate
			std::vector<std::thread> threads; //to improve : encapsulate
			std::list<std::function<void()> > tasks;
			std::mutex mutexTasks; //to improve : encapsulate

			ThreadPool();
			ThreadPool(const ThreadPool &&);
			ThreadPool(const ThreadPool &);
			void operator=(const ThreadPool &);

		public:
			ThreadPool(unsigned int);
			~ThreadPool();
			void addTask(std::function<void()>& task);
			void terminate();
			unsigned int getWorkingThreads();
		};
	};
};
