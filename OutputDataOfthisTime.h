#pragma once
#include <deque>

class OutputDataOfthisTime {
 public:
  int thisTimeProfitBesidesFINE;  //
  int thisTimeFINE;               //
  std::deque<int> thisTimeFinishedTaskNO;
  std::deque<int> thisTimeFINEDTaskNO;
  std::deque<int> thisTimeOut60TaskNO;
  
  
  void increaseMySelfFromAnotherOutput(OutputDataOfthisTime AnotherOutput);
  void resetMe(); // ����Ҫ����thisTimeOut60TaskNO
  OutputDataOfthisTime();

  ~OutputDataOfthisTime();
};
