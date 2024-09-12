#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  static int lineNo{};
  static const char *ofilePath = "output.txt";
  static const char *sampleText = "faraz alam is best";

  cout << "Write a file\n";
  ofstream ofile(ofilePath);
  for (int i = 0; i < 5; i++) {
    ofile << ++lineNo << " : " << sampleText << endl;
  }
  ofile.close();

  static char buf[128];
  ifstream ifile(ofilePath);
  while (ifile.good()) {
    ifile.getline(buf, sizeof(buf));
    cout << buf << endl;
  }
  ifile.close();
  cout << "delete file.\n";
  remove(ofilePath);
  return 0;
}
