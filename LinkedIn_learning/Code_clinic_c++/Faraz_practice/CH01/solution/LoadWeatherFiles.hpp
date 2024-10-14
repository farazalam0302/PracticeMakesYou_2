#ifndef LOADWEATHERFILES_H_
#define LOADWEATHERFILES_H_
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#define RESOURCE_PATH "../resources/"

class LoadWeatherData {
public:
  LoadWeatherData();

private:
  void loadData();
};

#endif // !1