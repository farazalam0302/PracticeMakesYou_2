#include "LoadWeatherFiles.hpp"
// #define VERBOSE
using namespace std;

LoadWeatherData::LoadWeatherData() { loadData(); }

void LoadWeatherData::loadData() {
  int year = 2012;
  for (; year <= 2015; year++) {
    ostringstream fileNameStream;
    fileNameStream << RESOURCE_PATH << "Environmental_Data_Deep_Moor_" << year
                   << ".txt";

    string fileName = fileNameStream.str();

    cout << "Loading .... " << fileName << endl;

    fstream dataFileStream;
    dataFileStream.open(fileName);
    string line;
#ifdef VERBOSE
    int flag = 0;
#endif // VERBOSE

    getline(dataFileStream, line); // discard header
    while (getline(dataFileStream, line)) {
      string date, time;
      double Air_Temp, Barometric_Press, Dew_Point, Relative_Humidity, Wind_Dir,
          Wind_Gust, Wind_Speed;
      istringstream buffer(line);
      buffer >> date >> time >> Air_Temp >> Barometric_Press >> Dew_Point >>
          Relative_Humidity >> Wind_Dir >> Wind_Gust >> Wind_Speed;
#ifdef VERBOSE

      if (flag <= 2) {
        cout << date << " | " << time << " | " << Air_Temp << " | "
             << Barometric_Press << " | " << Dew_Point << " | "
             << Relative_Humidity << " | " << Wind_Dir << " | " << Wind_Gust
             << " | " << Wind_Speed << endl;
      }
      flag++;
#endif
    }
    dataFileStream.close();
  }
}