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
  int basementY = 0;
  int count;
  OutputDataOfthisTime tempdata;
  char *name;
  int receiveTaskNum;
  int finishedTaskNum;
  int outTimeTaskNum;
  int worldTime;
  int totalAsset;

 public:
  Screen();
  Screen(Company com1,int baseY);
  // 使用擦除函数的打印方式
  void PrintChangableElem();
  void ClearChangableElem();
  //
  void PrintChangableWords();
  void ClearchangableWords();
  void gotoxy(tempLoc tempLOC);
  tempLoc TransLocationToScreenXY(int x, int y);
  //
  void PrintTheBasicMap();
  void PrintBulidingCenterLine();
  void PrintRoadCenterLine();
  //

  // *************************
  void ReloadTheScreenData(Company com1);
  ~Screen();
};
