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
  const int basementY = 0;
  int count;
 public:
  Screen();
  Screen(Company com1);
  // 使用擦除函数的打印方式
  void PrintChangableElem();
  void ClearChangableElem();
  void gotoxy(tempLoc tempLOC);
  tempLoc TransLocationToScreenXY(int x, int y);
  //
  void PrintTheBasicMap();
  void PrintBulidingCenterLine();
  void PrintRoadCenterLine();
  
  
  
  // *************************
  void ReloadTheTempLOC(Company com1);
  ~Screen();
};
