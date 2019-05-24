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
  // 根据文件复制整个任务列表
  
  // 打印整个列表
  void PrintSalsesList();
  ~SalesList();
};
