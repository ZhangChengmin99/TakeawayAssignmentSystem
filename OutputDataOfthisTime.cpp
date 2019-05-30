#include "OutputDataOfthisTime.h"

void OutputDataOfthisTime::increaseMySelfFromAnotherOutput(
    OutputDataOfthisTime AnotherOutput) {
	thisTimeProfitBesidesFINE += AnotherOutput.thisTimeProfitBesidesFINE;
	thisTimeFINE += AnotherOutput.thisTimeFINE;
	for(int i = 0; i<AnotherOutput.thisTimeFinishedTaskNO.size();i++){
		thisTimeFinishedTaskNO.push_back(AnotherOutput.thisTimeFinishedTaskNO.at(i));
	}
	for(int i  = 0; i<AnotherOutput.thisTimeFINEDTaskNO.size();i++){
		thisTimeFINEDTaskNO.push_back(AnotherOutput.thisTimeFINEDTaskNO.at(i));
	}
        for (int i = 0; i < AnotherOutput.thisTimeOut60TaskNO.size(); i++) {
          thisTimeOut60TaskNO.push_back(
              AnotherOutput.thisTimeOut60TaskNO.at(i));
        }
}

void OutputDataOfthisTime::resetMe() {
  thisTimeFINE = 0;
  thisTimeProfitBesidesFINE = 0;
  thisTimeFINEDTaskNO.clear();
  thisTimeFinishedTaskNO.clear();
}

OutputDataOfthisTime::OutputDataOfthisTime() {
  thisTimeFINE = 0;
  thisTimeProfitBesidesFINE = 0;
  thisTimeFINEDTaskNO.clear();
  thisTimeFinishedTaskNO.clear();
}

OutputDataOfthisTime::~OutputDataOfthisTime() {}
