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
  // ʹ�ò��������Ĵ�ӡ��ʽ
  void PrintChangableElem();
  void PrintTheBasicMap();
  void PrintBulidingCenterLine();
  void PrintRoadCenterLine();
  // *************************
  void ReloadTheTempLOC(Company com1);
  ~Screen();
};
