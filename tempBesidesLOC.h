#pragma once
#include <deque>

typedef struct BesidesLOC {
	int x;
	int y;
} BesidesLOC;

class tempBesidesLOC {
 public:
	 enum type{
		 restraunt,
		 customer,
		 resANDcus
	 } ;
  std::deque<BesidesLOC> restrantLOC;
  std::deque<BesidesLOC> customerLOC;
  std::deque<BesidesLOC> resANDcusLOC;
  tempBesidesLOC();
  void resetMe();
  bool pushLOC(type type1,int x,int y);
  ~tempBesidesLOC();
};
