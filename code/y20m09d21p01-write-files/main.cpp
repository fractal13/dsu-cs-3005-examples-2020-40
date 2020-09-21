#include <fstream> // for std::ofstream

int main() {
  std::ofstream fout("msg.txt", std::ios::binary);
  unsigned char c;
  
  //c = 104;
  c = 0x68;
  fout.write((char *)&c, sizeof(c));

  c = 101;
  fout.write((char *)&c, sizeof(c));

  c = 108;
  fout.write((char *)&c, sizeof(c));

  c = 108;
  fout.write((char *)&c, sizeof(c));

  c = 111;
  fout.write((char *)&c, sizeof(c));

  fout.close();
  return 0;
}
