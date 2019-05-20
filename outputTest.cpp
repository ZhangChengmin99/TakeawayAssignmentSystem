#include <windows.h>
#include <iostream>
#include <string>
#include "Company.h"

typedef struct tempLoc {
  int x;
  int y;
} tempLoc;

using namespace std;

void PrintBulidingCenterLine(int* count,deque<tempLoc>* tempLOC);
void PrintRoadCenterLine(int* count, deque<tempLoc>* tempLOC);


int main() {
  using namespace std;
  // 0 ʹ���Զ������
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  // 1 ���ɼٹ�˾���������
  Company com1 = Company(1, 15, 16);
  com1.buyRiders(2);
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(14, 3);
  com1.riderGroup.riders[2].coordinateOfSelf.changeCoordinate(2, 15);
  // 2 ������������λ�õĶ��б���λ��
  std::deque<tempLoc>* tempLOC;
  tempLOC = new deque<tempLoc>;
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLoc temp;
    temp.x = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition();
    temp.y = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition();
    tempLOC->push_back(temp);
  }
  // ��ӡװ����
  cout << "\n ******************************************************************************************************************\n";
  cout << " *                                                                                                                *\n";
  cout << " *                                    TakeawayAssignmentSystem 1.0 by Group 22                                    *";
  cout << "\n *                                                                                                                *\n";
  cout << " ******************************************************************************************************************";
  cout << "\n *                                                                                                                *\n";
  // ��ӡ�����
  cout << " *  ";
  cout << "  ";  // Ԥ�����пո�
  // 3-1 ����ÿһ�����Ӻ���8��Ӣ���ַ�,һ��9������
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      cout << 0 << i << " ";
    }
    else {
      cout << "   " << 0 << i << "    ";
	}
  }
  for (int i = 10; i < 16; i++) {
    if (i % 2) {
      cout << i << " ";
    } else {
      cout << "   " << i << "    ";
    }
  }
  cout << "   16       *";

 
  // ��ӡ�������ݶ�
  int count = 0;
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|������|����";
  cout << "|������|";
  cout << "    *";
  // ��ӡ�������м��� ��Ҫ������λ���ж��߼�

  PrintBulidingCenterLine(&count,tempLOC);
  // ��ӡ���������һ��û�е�
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |    *";
  // ��ӡ������׺͵�·��һ��
  cout << "\n ";
  cout << "*    ";
  cout << "|������     ";
  for (int i = 0; i < 7; i++) cout << " ������     ";
  cout << " ������|    *";
  // ��ӡ��·�м��� ��Ҫ������λ���ж��߼�
  PrintRoadCenterLine(&count,tempLOC);
  // ��ӡ��·���һ��
  cout << "\n ";
  cout << "*    ";
  cout << "|           ";
  for (int i = 0; i < 7; i++) cout << "            ";
  cout << "       |    *";
 

  // ***************** ��ӡѭ�� ******************
  while (count < 16) {
	// ��ӡ�������ݶ�
    cout << "\n ";
    cout << "*    ";
    for (int i = 0; i < 8; i++) cout << "|������|    ";
    cout << "|������|    *";
    // ��ӡ�������м���
    PrintBulidingCenterLine(&count, tempLOC);
	// ��ӡ�����������
    cout << "\n ";
    cout << "*    ";
    for (int i = 0; i < 8; i++) cout << "|      |    ";
    cout << "|      |    *";
    // ��ӡ������׺͵�·��һ��
    cout << "\n ";
    cout << "*    ";
    cout << "|������     ";
    for (int i = 0; i < 7; i++) cout << " ������     ";
    cout << " ������|    *";
    // ��ӡ��·�м���
    PrintRoadCenterLine(&count, tempLOC);
    // ��ӡ��·���һ��
    cout << "\n ";
    cout << "*    ";
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |    *";
  }
  // *********************************************


  // ***************** ��ӡ��16�� ******************
  // ��ӡ�����ﶥ
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|������|    ";
  cout << "|������|    *";
  // ��ӡ�������м���
  PrintBulidingCenterLine(&count, tempLOC);
  // ��ӡ���������һ��
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |    *";
  cout << "\n ";
  // ��ӡ������ĵ�
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << " ������ ����";
  cout << " ������     *";
  // *********************************************
  cout << "\n "
          "********************************************************************"
          "**********************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
  com1.printPartCompanyInfo();
  cout << " *                                                                  "
          "                                              *\n";
  cout << " "
          "********************************************************************"
          "**********************************************\n";
  //
  getchar();
  return 0;
}

void PrintBulidingCenterLine(int* count, deque<tempLoc> * tempLOC) {
  
  if (*count < 10) {
    cout << "\n" << " *  " << "0" <<*count;
  } else {
    cout << "\n" << " *  " << *count;
  }
  
  if ( tempLOC->size() == 0) {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      cout << "  ";
      putchar(' ');
    }
  } else {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      bool flag = false;
      for (int k = 0; k < tempLOC->size(); k++) {
        if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 2 * i + 1) {
          flag = true;
          tempLOC->erase(tempLOC->begin() + k);
        }
      }
      if (flag) {
        cout << "��";
      } else {
        cout << "  ";
      }
      putchar(' ');
    }
  }
  cout << "|      |    *";
  *count += 1;
}

void PrintRoadCenterLine(int* count, deque<tempLoc>* tempLOC) {
  if (*count < 10) {
    cout << "\n"
         << " *  "
         << "0" << *count;
  } else {
    cout << "\n"
         << " *  " << *count;
  }
  if (tempLOC->size() == 0) {
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
  } else {
    // ��ӡ��·�м��е�һλ��
    cout << "|  ";
    bool flag = false;
    for (int k = 0; k < tempLOC->size(); k++) {
      if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 0) {
        flag = true;
        tempLOC->erase(tempLOC->begin() + k);
      }
    }
    if (flag) {
      cout << "��";
    } else {
      cout << "  ";
    }
    cout << "       ";
    // ��ӡ��·�м����м�λ��
    for (int i = 0; i < 7; i++) {
      flag = false;
      cout << "   ";
      for (int k = 0; k < tempLOC->size(); k++) {
        if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 2 * (i + 1)) {
          flag = true;
          tempLOC->erase(tempLOC->begin() + k);
        }
      }
      if (flag) {
        cout << "��";
      } else {
        cout << "  ";
      }
      cout << "       ";
    }
    // ��ӡ��·�м������λ��
    cout << "   ";
    flag = false;
    for (int k = 0; k < tempLOC->size(); k++) {
      if (tempLOC->at(k).y == *count && tempLOC->at(k).x == 16) {
        flag = true;
        tempLOC->erase(tempLOC->begin() + k);
      }
    }
    if (flag) {
      cout << "��";
    } else {
      cout << "  ";
    }
    flag = false;
    cout << "  |    *";
    *count += 1;
  }
}