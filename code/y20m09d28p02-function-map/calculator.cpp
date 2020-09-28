#include "calculator.h"
#include <string>
#include <map>

std::string getString(std::istream& is, std::ostream& os, const std::string& prompt) {
  std::string answer;
  os << prompt;
  is >> answer;
  return answer;
}

int getInteger(std::istream& is, std::ostream& os, const std::string& prompt) {
  int answer;
  os << prompt;
  is >> answer;
  return answer;
}

int calculator(std::istream& is, std::ostream& os) {
  typedef int (*CalcFunction)(const int&, const int&);

  std::map<std::string, CalcFunction> actions;
  CalcFunction calc;
  actions["add"] = add;
  actions["subtract"] = subtract;
  actions["multiply"] = multiply;
  actions["divide"] = divide;
  
  std::string operation;
  int total = 0;
  int right_hand_operand;
  bool done = false;

  while(!done) {
    os << "Current total: " << total << std::endl;

    operation = getString(is, os, "Action? ");
    if(operation != "quit") {
      right_hand_operand = getInteger(is, os, "Operand? ");
    }

    if(actions.find(operation) != actions.end()) {
      calc = actions[operation];
    } else {
      if(operation == "quit") {
        done = true;
      } else {
        os << "action: " << operation << " is not known." << std::endl;
        os << "try: add, subtract, multiply, divide, or quit." << std::endl;
      }
      calc = 0;
    }

    if(calc != 0) {
      total = calc(total, right_hand_operand);
    }
  }

  os << "Total: " << total << std::endl;
  return total;
}
