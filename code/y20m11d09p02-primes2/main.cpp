#include <cstdlib> // for std::rand()
#include <ctime> // for std::time()
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
#include <thread>

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

void prime_worker(const std::vector<int>& possible_primes, 
                  const unsigned int first, const unsigned int last,
                  std::vector<int>& actual_primes) {
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

  unsigned int i;
  for(i = first; i < last; i++) {
    if(is_prime(possible_primes[i])) {
      actual_primes.push_back(possible_primes[i]);
    }
  }
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now( );
  std::chrono::duration< double > time_span = 
    std::chrono::duration_cast< std::chrono::duration< double > >( t2 - t1 );
  std::cout << "Worker: " << first << ":" << last << " " << time_span.count() << std::endl;
}

int main(int argc, const char *argv[]) {
  unsigned int i;
  std::vector<int> possible_primes;
  std::vector<int> actual_primes;
  
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
  
  // record possible prime numbers
  for(i = 2; i <= max_prime; i++) {
    possible_primes.push_back(i);
  }

  // start time
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

  std::vector<std::thread> threads;

  for(i = 0; i < max_workers; i++) {
    unsigned int first = i*possible_primes.size()/max_workers;
    unsigned int last = (i+1)*possible_primes.size()/max_workers;
    threads.push_back( std::thread(prime_worker, std::ref(possible_primes), first, last, std::ref(actual_primes)) );
    //prime_worker(possible_primes, first, last, actual_primes);
  }

  for(i = 0; i < max_workers; i++) {
    threads[i].join();
  }

  // end time
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now( );

  // report time
  std::chrono::duration< double > time_span = 
    std::chrono::duration_cast< std::chrono::duration< double > >(t2 - t1);
  std::cout << "It took " << time_span.count() << " seconds to check "
            << possible_primes.size() << " numbers." << std::endl;

  // show last few prime numbers
  unsigned int max_display = 10;
  for(i = 0; i < max_display && i < actual_primes.size(); i++) {
    std::cout << actual_primes[actual_primes.size()-i-1] << " ";
  }
  std::cout << std::endl;

  return 0;
}
