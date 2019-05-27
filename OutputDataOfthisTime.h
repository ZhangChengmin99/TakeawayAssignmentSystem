#pragma once
#include <deque>

class OutputDataOfthisTime {
 public:
  int thisTimeProfitBesidesFINE;  //
  int thisTimeFINE;               //
  std::deque<int> thisTimeFinishedTaskNO;
  std::deque<int> thisTimeFINEDTaskNO;
  
  
  void increaseMySelfFromAnotherOutput(OutputDataOfthisTime AnotherOutput);
  void resetMe();
  OutputDataOfthisTime();

  ~OutputDataOfthisTime();
};
