
#include <iostream>
#include <vector>

using namespace std;

struct User {
  string username;
  int skill;
  int user_level;
  int waiting_time;
};

struct match_config {
  int s_weight;
  int l_weight;
  int t_weight;
};

void ChessPairing(vector<User>& waiting_users, match_config& myConfig) {
  int NumberOfPlayers = waiting_users.size();
  vector<vector<int>> distanceScoreMatrix(
      NumberOfPlayers, vector<int>(NumberOfPlayers + 1, 1e6));

  vector<pair<int, bool>> respectivePartner(NumberOfPlayers, {1e6, false});
  int minimumPartner;
  for (int i = 0; i < NumberOfPlayers; ++i) {
    minimumPartner = 1e6;
    for (int j = 0; j < NumberOfPlayers; ++j) {
      int DeltaUserSkill = abs(waiting_users[i].skill - waiting_users[j].skill);
      int DeltaWaitingTime =
          abs(waiting_users[i].waiting_time - waiting_users[j].waiting_time);
      int DeltaUserLevel =
          abs(waiting_users[i].user_level - waiting_users[j].user_level);

      distanceScoreMatrix[i][j] = min(distanceScoreMatrix[i][j],
                                      (myConfig.s_weight * DeltaUserSkill +
                                       myConfig.l_weight * DeltaUserLevel +
                                       myConfig.t_weight * DeltaWaitingTime));

      if (i != j && minimumPartner >= distanceScoreMatrix[i][j]) {
        minimumPartner = distanceScoreMatrix[i][j];
        respectivePartner[i] = {j, false};
      }
    }
  }

  for (int i = 0; i < NumberOfPlayers; ++i) {
    if (respectivePartner[i].second == false) {
      cout << waiting_users[i].username << " : "
           << waiting_users[respectivePartner[i].first].username << endl;
      respectivePartner[i].second = true;
      respectivePartner[respectivePartner[i].first].second = true;
    }
  }
  //  for (int i = 0; i < NumberOfPlayers; ++i) {
  //    for (int j = 0; j < NumberOfPlayers; ++j) {
  //      cout << distanceScoreMatrix[i][j] << ", ";
  //    }
  //    cout << respectivePartner[i].first;
  //    cout << endl;
  //  }
}

int main() {
  //  User waiting_users[50] =

  vector<User> waiting_users{
      {"lyingOrange6", 62, 2, 4},       {"betrayedSnipe6", 25, 4, 32},
      {"morbidDove1", 92, 0, 47},       {"decimalCheese8", 94, 4, 82},
      {"lazySnail8", 29, 2, 47},        {"shamefulBuzzard5", 72, 2, 51},
      {"giddyBuck3", 71, 1, 30},        {"panickyToucan5", 23, 2, 62},
      {"cynicalCordial3", 26, 2, 15},   {"zestyMagpie5", 26, 2, 46},
      {"dearEggs6", 47, 2, 88},         {"grudgingPup3", 72, 4, 0},
      {"artisticMallard1", 75, 3, 42},  {"solidSausage3", 9, 1, 24},
      {"awedAntelope0", 33, 3, 13},     {"jealousBoars7", 28, 2, 84},
      {"pridefulBobolink8", 5, 1, 22},  {"needyEagle6", 49, 1, 1},
      {"cockyBustard3", 88, 4, 15},     {"pleasedBuck8", 64, 4, 63},
      {"hushedJaguar8", 77, 1, 47},     {"pitifulCaribou6", 47, 3, 67},
      {"adoringSeafowl8", 53, 3, 74},   {"peskyMandrill7", 53, 4, 21},
      {"kindSeafowl4", 44, 4, 72},      {"shyCheetah0", 92, 4, 76},
      {"grizzledBoa6", 96, 4, 37},      {"similarSeagull6", 51, 3, 48},
      {"obsessedMoth2", 10, 1, 79},     {"sincereBoa1", 23, 4, 67},
      {"humorousHoopoe5", 4, 0, 33},    {"thriftyLapwing1", 39, 1, 44},
      {"outlyingApricots1", 64, 3, 69}, {"eagerCow2", 94, 4, 89},
      {"shyCockatoo9", 62, 2, 59},      {"worriedChile9", 72, 3, 2},
      {"dopeyWhiting7", 37, 2, 5},      {"cheerfulMoth9", 4, 2, 46},
      {"grudgingPorpoise3", 76, 4, 40}, {"trustingOrange7", 80, 4, 72},
      {"dopeyChamois3", 80, 0, 50},     {"peacefulGatorade4", 19, 4, 26},
      {"cruelEland7", 47, 0, 21},       {"aboardWasp3", 12, 4, 34},
      {"grudgingGelding4", 75, 1, 36},  {"cockyHare2", 41, 0, 56},
      {"guiltyPolenta9", 91, 0, 42},    {"scornfulTacos5", 48, 1, 64},
      {"pluckyAntelope3", 93, 0, 88},   {"holisticChough1", 25, 3, 78}};

  match_config myConfig{5, 25, 2};

  ChessPairing(waiting_users, myConfig);
  return 0;
}
