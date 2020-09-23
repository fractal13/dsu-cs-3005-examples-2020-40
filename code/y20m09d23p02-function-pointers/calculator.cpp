#include "calculator.h"
#include <string>

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
  std::string operation;
  int total = 0;
  int right_hand_operand;
  bool done = false;

  int (*calc)(const int&, const int&);
  while(!done) {
    os << "Current total: " << total << std::endl;

    operation = getString(is, os, "Action? ");
    if(operation != "quit") {
      right_hand_operand = getInteger(is, os, "Operand? ");
    }

    if(operation == "add") {
      calc = add;
    } else if(operation == "subtract") {
      calc = subtract;
    } else if(operation == "multiply") {
      calc = multiply;
    } else if(operation == "divide") {
      calc = divide;
    } else if(operation == "quit") {
      calc = 0;
      done = true;
    } else {
      calc = 0;
      os << "action: " << operation << " is not known." << std::endl;
      os << "try: add, subtract, multiply, divide, or quit." << std::endl;
    }
    if(calc != 0) {
      total = calc(total, right_hand_operand);
    }
  }

  os << "Total: " << total << std::endl;
  return total;
}
