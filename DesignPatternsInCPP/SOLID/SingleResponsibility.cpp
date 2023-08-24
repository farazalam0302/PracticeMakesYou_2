#include <bits/stdc++.h>
using namespace std;

struct Journal {

  string title;
  vector<string> entries;
  Journal(const string &title) : title(title) {}
  void addEntry(const string &entry) {
    static int count = 1;
    string ec = "";
    ec = ec + to_string(count) + " : " + entry;
    entries.push_back(ec);
    count++;
  }
  void save(const string &filename) { /* This is for Saving it to HDD but this
                                         must be separate class */
    ofstream ofs(filename);
    for (auto &e : entries) {
      ofs << e << endl;
    }
  }
};

struct PersistenceManager {
  static void save(const Journal &j, const string &filename) {
    ofstream ofs(filename);
    for (auto &e : j.entries) {
      ofs << e << endl;
    }
  }
};

int main(int argc, char const *argv[]) {

  Journal journal{"Dear Diary"};
  journal.addEntry("I love India!");
  journal.addEntry("I love Chai!");
  // journal.save("diary.txt")
  PersistenceManager pm;
  pm.save(journal, "diary.txt");
  return 0;
}
