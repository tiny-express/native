#include "../builtin.h"
#include "../unit_test.h"

// pid = (int)pthread_self();

static int total = 0;

void task1(){
	total++;
}

void task2(){
	total++;
}
	
TEST(Builtin_Thread, MultipleThreading) {
	// Init number of parallel processes
	threadpool thpool = thpool_init(5);
	int i;
	// Push job to queue
	for (i=0; i<5; i++) {
		thpool_add_work(thpool, (void*) task1, NULL);
		thpool_add_work(thpool, (void*) task2, NULL);
	};
	// Wait until jobs are done
	thpool_wait(thpool);
	thpool_destroy(thpool);
	ASSERT_EQUAL(10, total);
}