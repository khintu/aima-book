#pragma once

namespace AI {
	class CThrdBase {
		pthread_mutex_t mtx;
		pthread_cond_t cond;
		pthread_t thread;
	public:
		CThrdBase() :mtx(PTHREAD_MUTEX_INITIALIZER), \
								 cond(PTHREAD_COND_INITIALIZER)
		{
			pthread_mutex_init(&mtx, NULL);
			pthread_cond_init(&cond, NULL);
			memset(&thread, 0, sizeof(pthread_t));
		}
		virtual ~CThrdBase() {
			pthread_mutex_destroy(&mtx);
			pthread_cond_destroy(&cond);
		}
		void waitToExit() {
			pthread_join(thread, NULL);
		}
		void lock() {
			pthread_mutex_lock(&mtx);
		}
		void unlock() {
			pthread_mutex_unlock(&mtx);
		}
		void wait() {
			pthread_cond_wait(&cond, &mtx);
		}
		void signal() {
			pthread_cond_signal(&cond);
		}

		// To be implemented by derived concrete threads
		virtual void thrdInitialize() = 0;
		virtual void thrdExecution() = 0;
		virtual void thrdFinalize() = 0;

		static void* threadObjectStartExecCb(void* arg);
		static void startThread(CThrdBase* threadObj);
	};
}
