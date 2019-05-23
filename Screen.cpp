#include "Screen.h"
#include <windows.h>
#include <iostream>
#include <string>

Screen::Screen() {
	count = 0;
	tempLOC.clear();
}

Screen::Screen(Company com1) {
  count = 0;
  tempLOC.clear();
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    
    tempLOC.push_back(TransLocationToScreenXY(
        com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition(),
        com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition()));
  }
}



void Screen::PrintChangableElem() {
	using namespace std;
	for(int i = 0; i<tempLOC.size(); i++) {
		gotoxy(tempLOC.at(i));
		cout << "��";
	}
        tempLoc temp = {0, 69 + basementY};
        gotoxy(temp);
}

void Screen::ClearChangableElem() {
  using namespace std;
  for (int i = 0; i < tempLOC.size(); i++) {
    gotoxy(tempLOC.at(i));
    cout << "  ";
  }
  tempLoc temp = {0, 69 + basementY};
  gotoxy(temp);
}



void Screen::PrintTheBasicMap() {
	using namespace std;
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  // ��ӡװ����
  std::cout << "\n "
               "***************************************************************"
               "***************************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
  cout << " *                                    TakeawayAssignmentSystem 1.0 "
          "by Group 22                                    *";
  cout << "\n *                                                                "
          "                                                *\n";
  cout << " *******************************************************************"
          "***********************************************";
  cout << "\n *                                                                "
          "                                                *\n";
  // ��ӡ�����
  cout << " *  ";
  cout << "  ";  // Ԥ�����пո�
  // 3-1 ����ÿһ�����Ӻ���8��Ӣ���ַ�,һ��9������
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      cout << 0 << i << " ";
    } else {
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
  cout << "\n ";
  cout << "*    ";
  for (int i = 0; i < 8; i++) cout << "|������|����";
  cout << "|������|";
  cout << "    *";
  // ��ӡ�������м��� ��Ҫ������λ���ж��߼�

  PrintBulidingCenterLine();
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
  PrintRoadCenterLine();
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
    PrintBulidingCenterLine();
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
    PrintRoadCenterLine();
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
  PrintBulidingCenterLine();
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
  
}

void Screen::PrintBulidingCenterLine() {
	using namespace std;
  if (count < 10) {
    cout << "\n"
         << " *  "
         << "0" << count;
  } else {
    cout << "\n"
         << " *  " << count;
  }

  for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      cout << "  ";
      putchar(' ');
    }
  cout << "|      |    *";
  count += 1;
}

void Screen::PrintRoadCenterLine() {
	using namespace std;
  if (count < 10) {
    cout << "\n"
         << " *  "
         << "0" << count;
  } else {
    cout << "\n"
         << " *  " << count;
  }
  
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |    *";
	count += 1;
}

void Screen::gotoxy(tempLoc tempLOC) {
  COORD pos = {tempLOC.x,tempLOC.y};
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  // ��ȡ��׼����豸���
  SetConsoleCursorPosition(hOut, pos);  //���������ֱ���ָ���ĸ����壬����λ��
}

tempLoc Screen::TransLocationToScreenXY(int x, int y) { 
	y = 9 + basementY + 3*y;
	// ���x��ż��
	if(x%2==0){
		x = 9 + (x/2) * 12;
	} else {
		x = 15 + ( (x-1) / 2 ) * 12;
	}
	tempLoc tempLOC = {x,y};
	return tempLOC; 
}

void Screen::ReloadTheTempLOC(Company com1) {
	count = 0;
	tempLOC.clear();
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLOC.push_back(TransLocationToScreenXY(
              com1.riderGroup.riders.at(i)
                  .coordinateOfSelf.returnTheXPosition(),
              com1.riderGroup.riders.at(i)
                  .coordinateOfSelf.returnTheYPosition()));
  }
}

Screen::~Screen() {}
