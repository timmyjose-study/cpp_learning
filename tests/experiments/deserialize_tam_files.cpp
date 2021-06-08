#include <cstdio>
#include <fstream>
#include <iostream>

struct Instruction {
  int op;
  int r;
  int n;
  int d;

  Instruction() {}

  friend std::ostream &operator<<(std::ostream &out, const Instruction &instr) {
    return out << "Instruction { op: " << instr.op << ", r: " << instr.r
               << ", n: " << instr.n << ", d: " << instr.d << std::endl;
  }
};

int extract_big_endian(std::ifstream &in) {
  char *buf = new char[4];
  in.read(buf, 4);

  int res = (buf[3] << 0) | (buf[2] << 8) | (buf[1] << 16) | (buf[0] << 24);
  delete[] buf;

  return res;
}

int main() {
  const char *filename = "../tests/experiments/hello.tam";
  std::ifstream infile{filename, std::ios::in | std::ios::binary};

  if (infile.is_open()) {
    while (!infile.eof()) {
      Instruction instr{};

      instr.op = extract_big_endian(infile);
      instr.r = extract_big_endian(infile);
      instr.n = extract_big_endian(infile);
      instr.d = extract_big_endian(infile);

      std::cout << instr << std::endl;
    }

    // fclose(fp);
    infile.close();
  } else {
    std::cerr << "Unable to open file " << filename << std::endl;
    std::exit(1);
  }

  return 0;
}