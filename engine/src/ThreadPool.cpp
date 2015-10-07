#include "../includes/ThreadPool.hh"

namespace StrawberryMilk
{
	namespace Thread
	{
		ThreadPool::ThreadPool(unsigned int size)
		{
			closedpool = false;
			workingThreads = size;
			maxThreads = size;
			for (unsigned int i = 0; i < size; ++i)
			{
				threads.emplace_back([this]() -> void
				{
					while (true)
					{
						std::function<void()> task;
						{   //to improve anti missed interval update
							std::unique_lock<std::mutex> lock(mutexTasks);
							workingThreads--;
							condvarTasks.wait(lock, [this]() -> bool
							{
								return !tasks.empty() || closedpool;
							});
							if (closedpool && tasks.empty())
								return;
							task = std::move(tasks.front());
							tasks.pop_front();
							workingThreads++;
						}

						task();
					}
				});
			}
		}

		ThreadPool::~ThreadPool()
		{
			closedpool = true;
			condvarTasks.notify_all();
			for (unsigned int i = 0; i < threads.size(); ++i)
				threads[i].join();
		}

		void ThreadPool::addTask(std::function<void()>& task)
		{
			{
				std::unique_lock<std::mutex> lock(mutexTasks);
				tasks.push_back(task);
			}
			condvarTasks.notify_one();
		}

		void ThreadPool::terminate()
		{
			closedpool = true;
			condvarTasks.notify_all();
		}

		unsigned int ThreadPool::getWorkingThreads()
		{
			return workingThreads;
		}
	};
};
