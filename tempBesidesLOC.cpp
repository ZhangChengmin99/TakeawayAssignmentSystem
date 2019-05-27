#include "tempBesidesLOC.h"

tempBesidesLOC::tempBesidesLOC() {
  resANDcusLOC.clear();
  customerLOC.clear();
  restrantLOC.clear();
}

void tempBesidesLOC::resetMe() {
  resANDcusLOC.clear();
  customerLOC.clear();
  restrantLOC.clear();
}

bool tempBesidesLOC::pushLOC(type type1, int x, int y) {
  if ((!(x % 2)) && (!(y % 2))) {
    BesidesLOC temp = {x, y};
    switch (type1) {
	case resruant : {
      restrantLOC.push_back(temp);
      break;
    }
    case customer : {
      customerLOC.push_back(temp);
      break;
	}
    case resANDcus : {
      resANDcusLOC.push_back(temp);
      break;
	}
    }
  } else {
    return false;
  }
  return true;
}

tempBesidesLOC::~tempBesidesLOC() {}
