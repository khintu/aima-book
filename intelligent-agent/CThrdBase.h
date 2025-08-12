#pragma once

namespace AI {
	class CThrdBase {
		pthread_mutex_t mtx;
		pthread_cond_t cond;
	public:
		pthread_t thread;
	protected:
		inline void lock() {
			pthread_mutex_lock(&mtx);
		}
		inline void unlock() {
			pthread_mutex_unlock(&mtx);
		}
		inline void wait() {
			pthread_cond_wait(&cond, &mtx);
		}
		inline void signal() {
			pthread_cond_signal(&cond);
		}
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
		void waitToJoinWithThrd() {
			pthread_join(thread, NULL);
		}

		// To be implemented by derived concrete threads
		virtual void thrdInitialize() = 0;
		virtual void thrdExecution() = 0;
		virtual void thrdFinalize() = 0;

		static void* threadObjectStartExecCb(void* arg);
	};
}
