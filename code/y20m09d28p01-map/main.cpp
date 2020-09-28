#include <iostream>
#include <map>
#include <string>

int main() {
  std::map<std::string, int> primes;

  // Spencer 13
  // LangHui 3
  // Claire 101
  // Jason 13
  primes["Spencer"] = 13;
  primes["LangHui"] = 3;
  primes["Claire"] = 101;
  primes["Jason"] = 13;
  
  std::string name = "Heather";
  int prime = 2;

  primes[name] = prime;

  // for key in primes:
  //    print(key, primes[key])
  std::map<std::string, int>::iterator p;
  for(p = primes.begin(); p != primes.end(); p++) {
    std::cout << p->first << " " << p->second << std::endl;
  }

  //
  std::cout << std::endl;
  std::cout << primes["Heather"] << std::endl;
  std::cout << primes["Jason"] << std::endl;
  // if "Marshall" in primes:
  if(primes.find("Marshall") != primes.end()) {
    std::cout << primes["Marshall"] << std::endl;
  }

  std::cout << "Whose number? ";
  std::cin >> name;
  if(primes.find(name) != primes.end()) {
    std::cout << primes[name] << std::endl;
  } else {
    std::cout << name << " does not have a favorite prime." << std::endl;
  }
  
  return 0;
}
