#pragma once
#include <deque>
#include <fstream>
#include <iostream>
#include <assert.h> 

typedef struct SalesItem {
	int no;
	int time;
	int restAddX;
	int restAddY;
	int cusAddX;
	int cusAddY;
} SalesItem;

class SalesList {
 public:
	 std::deque<SalesItem> Saleslist;

  SalesList();
  // �����ļ��������������б�
  
  // ��ӡ�����б�
  void PrintSalsesList();
  ~SalesList();
};
