#pragma once
#include <deque>

class OutputDataOfthisTime {
 public:
  int thisTimeProfitBesidesFINE;  //
  int thisTimeFINE;               //
  int thisTimeReceiveTaskNUM;

  std::deque<int> thisTimeFinishedTaskNO;
  std::deque<int> thisTimeFINEDTaskNO;
 public:
  OutputDataOfthisTime();

  ~OutputDataOfthisTime();
};
