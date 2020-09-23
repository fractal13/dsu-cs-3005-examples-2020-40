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
  while(!done) {
    os << "Current total: " << total << std::endl;

    operation = getString(is, os, "Action? ");
    if(operation != "quit") {
      right_hand_operand = getInteger(is, os, "Operand? ");
    }

    if(operation == "add") {
      total = add(total, right_hand_operand);
    } else if(operation == "subtract") {
      total = subtract(total, right_hand_operand);
    } else if(operation == "multiply") {
      total = multiply(total, right_hand_operand);
    } else if(operation == "divide") {
      total = divide(total, right_hand_operand);
    } else if(operation == "quit") {
      done = true;
    } else {
      os << "action: " << operation << " is not known." << std::endl;
      os << "try: add, subtract, multiply, divide, or quit." << std::endl;
    }
  }

  os << "Total: " << total << std::endl;
  return total;
}
