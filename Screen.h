#pragma once
#include <deque>
#include "Company.h"

typedef struct tempLoc {
  int x;
  int y;
} tempLoc;

class Screen {
 private:
  std::deque<tempLoc> tempLOC;
  int count;
 public:
  Screen();
  Screen(Company com1);
  void PrintTheAllMaps();
  void PrintBulidingCenterLine();
  void PrintRoadCenterLine();
  void ReloadTheTempLOC(Company com1);
  ~Screen();
};
