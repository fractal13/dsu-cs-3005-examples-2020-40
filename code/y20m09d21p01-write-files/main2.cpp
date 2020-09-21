#include <fstream> // for std::ofstream

int main() {
  std::ofstream fout("msg2.txt", std::ios::binary);

  fout << "hello";

  fout.close();
  return 0;
}
