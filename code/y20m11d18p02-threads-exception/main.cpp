#include <cstdlib> // for std::rand()
#include <ctime> // for std::time()
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
#include <thread>
#include <mutex>
#include "ThreadedVector.h"

// data holder
class PrimeTask {
public:
  PrimeTask(unsigned int f, unsigned int l) : first(f), last(l) { }
  unsigned int first; // first number to check in a task
  unsigned int last; // last-1 is the last number to check
};

class PrimeHunter {
public:
  PrimeHunter(unsigned int& mp, unsigned int& mw, unsigned int& ts);
  void findPrimes();
  void primeWorker();
  ThreadedVector<PrimeTask>& getTasks();
  ThreadedVector<int>& getActualPrimes();

protected:
  unsigned int mMaxPrime;
  unsigned int mMaxWorkers;
  unsigned int mTaskSize;
  ThreadedVector<PrimeTask> mTasks;
  ThreadedVector<int> mActualPrimes;
  std::mutex mOutputLock;
};

PrimeHunter::PrimeHunter(unsigned int& mp, unsigned int& mw, unsigned int& ts) 
  : mMaxPrime(mp), mMaxWorkers(mw), mTaskSize(ts) {
}

void PrimeHunter::findPrimes() {
  unsigned int i;
  
  // record possible prime numbers
  for(i = 2; i <= mMaxPrime; i+=mTaskSize) {
    mTasks.push_back(PrimeTask(i, i+mTaskSize));
  }

  std::vector<std::thread> threads;

  for(i = 0; i < mMaxWorkers; i++) {
    try {
      threads.push_back( std::thread(&PrimeHunter::primeWorker, this) );  // this->primeWork()
    } catch (std::exception& e) {
      // no real clean up.
      std::cout << "Exception: " << e.what() << std::endl;
    }
  }

  for(i = 0; i < mMaxWorkers; i++) {
    threads[i].join();
  }
  
}

ThreadedVector<PrimeTask>& PrimeHunter::getTasks() {
  return mTasks;
}

ThreadedVector<int>& PrimeHunter::getActualPrimes() {
  return mActualPrimes;
}

bool is_prime( int n ) {
  if( n == 2 ) {
    return true;
  }
  if( n % 2 == 0 ) {
    return false;
  }
  int i;
  for( i = 3; i < std::sqrt( n ) + 1; i += 2 ) {
    if( n % i == 0 ) {
      return false;
    }
  }
  return true;
}

void PrimeHunter::primeWorker() {
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  std::vector<PrimeTask> my_tasks;
  
  unsigned int i, j;
  while(!mTasks.empty()) {
    //my_tasks.resize(0);
    my_tasks.clear();
    mTasks.pop_back(my_tasks, 1);
    
    for(i = 0; i < my_tasks.size(); i++) {
      for(j = my_tasks[i].first; j < my_tasks[i].last; j++) {
        if(is_prime(j)) {
          mActualPrimes.push_back(j);
        }
      }
    }
  }
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now( );
  std::chrono::duration< double > time_span = 
    std::chrono::duration_cast< std::chrono::duration< double > >( t2 - t1 );

  mOutputLock.lock();
  std::cout << "Worker: " << time_span.count() << std::endl;
  mOutputLock.unlock();
}

int main(int argc, const char *argv[]) {
  unsigned int i;
  
  // find all primes up to 100, unless user specified a different limit in the command line arguments
  unsigned int max_prime = 100;
  if(argc > 1) {
    std::stringstream ss(argv[1]);
    ss >> max_prime;
  }

  // calculate in one pass, unless the user specified differently in the command line arguments.
  unsigned int max_workers = 1;
  if(argc > 2) {
    std::stringstream ss(argv[2]);
    ss >> max_workers;
  }

  // task size
  unsigned int task_size = 1;
  if(argc > 3) {
    std::stringstream ss(argv[3]);
    ss >> task_size;
  }

  PrimeHunter orion(max_prime, max_workers, task_size);
  
  // start time
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

  orion.findPrimes();

  // end time
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now( );

  // report time
  std::chrono::duration< double > time_span = 
    std::chrono::duration_cast< std::chrono::duration< double > >(t2 - t1);
  std::cout << "It took " << time_span.count() << " seconds to check " << std::endl;

  // show last few prime numbers
  unsigned int max_display = 10;
  for(i = 0; i < max_display && i < orion.getActualPrimes().size(); i++) {
    std::cout << orion.getActualPrimes()[orion.getActualPrimes().size()-i-1] << " ";
  }
  std::cout << std::endl;

  return 0;
}
