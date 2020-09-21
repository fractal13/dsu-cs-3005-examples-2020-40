#include <fstream> // for std::ofstream

int main() {
  std::ofstream fout("nums.dat", std::ios::binary);
  int i = 1111;
  unsigned char c;
  
  //c = 104;
  c = i;
  fout.write((char *)&c, sizeof(c));

  c = 208;
  fout.write((char *)&c, sizeof(c));

  c = 255;
  fout.write((char *)&c, sizeof(c));

  c = 165;
  fout.write((char *)&c, sizeof(c));

  c = 243;
  fout.write((char *)&c, sizeof(c));

  fout.close();
  return 0;
}
