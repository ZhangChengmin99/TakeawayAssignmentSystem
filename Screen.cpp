#include "Screen.h"
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>

Screen::Screen() {
	count = 0;
	tempLOC.clear();
    name = new char[100];
    receiveTaskNum = 0;
    finishedTaskNum = 0;
    outTimeTaskNum = 0;
    worldTime = 0;
    totalAsset = 0;
	basementY = 0;
}

Screen::Screen(Company com1,int baseY) {
  name = new char[100];
  strcpy_s(name, 100, com1.name);
  receiveTaskNum = com1.receiveTaskNum;
  finishedTaskNum = com1.finishedTaskNum;
  outTimeTaskNum = com1.outTimeTaskNum;
  worldTime = com1.worldTime;
  totalAsset = com1.totalAsset;
  tempdata = com1.outputThisTime;
  basementY = baseY;
  //
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
	for(auto i:tempLOC) {
		gotoxy(i);
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

void Screen::PrintChangableWords() {
  using namespace std;
  // ��ӡʱ��
  tempLoc temp = {21,64+basementY};
  gotoxy(temp);
  cout << setw(11) << setfill(' ') << worldTime;
  // ��ӡ��Ǯ
  temp = {21, 63+basementY};
  gotoxy(temp);
  cout << setw(10) << setfill(' ') << totalAsset;
  // ��ӡ���յ���
  temp = {21, 65+basementY};
  gotoxy(temp);
  cout << setw(11) << setfill(' ') << receiveTaskNum;
  // ��ӡ��ɵ���
  temp = {21, 66+basementY};
  gotoxy(temp);
  cout << setw(11) << setfill(' ') << finishedTaskNum;
  // ��ӡ��ʱ����
  temp = {67, 62+basementY};
  gotoxy(temp);
  cout << outTimeTaskNum;
  // 6 ��ӡ��ɶ������
  // 6-1 ���������λ��
  temp = {53, 64+basementY};
  gotoxy(temp);
  cout << "                                                             ";
  // 6-2 ��ӡ������
  temp = {53, 64+basementY};
  gotoxy(temp);
  if(tempdata.thisTimeFinishedTaskNO.size()==0){
	  cout << "NO FINISHED TASKS IN THIS TIME!";
  } else {
	  for(auto i:tempdata.thisTimeFinishedTaskNO){
		cout << i << " ";
	  }
  }
  // 7 ��ӡ��ʱ�������
  // 7-1 ���������λ��
  temp = {53, 66+basementY};
  gotoxy(temp);
  cout << "                                                             ";
  // 7-2 ��ӡ������
  temp = {53, 66+basementY};
  gotoxy(temp);
  if (tempdata.thisTimeFINEDTaskNO.size() == 0) {
    cout << "NO OUTTIME TASKS IN THIS TIME!";
  } else {
    for (auto i : tempdata.thisTimeFINEDTaskNO) {
      cout << i << " ";
    }
  }


  //
  temp = {0, 69 + basementY};
  gotoxy(temp);
}

void Screen::ClearchangableWords() {
	// δ�ô˷���
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
  using namespace std;
  cout << "\n "
          "********************************************************************"
          "**********************************************\n";
  cout << " *                                                                  "
          "                                              *\n";
  std::cout << " *   Company   Name: " << setw(11) << setfill(' ') << name
            << "                     OutTimeTaskN:                                                *\n";
  std::cout << " *   Company Assets:           $                     FinishedTaskNo(thisTime):                                    *\n";
  std::cout << " *   All World Time:                                                                                              *\n";
  std::cout << " *   Receive TasksN:                                 OutTimeTaskNo(thisTime):                                     *\n";
  std::cout << " *   Finished TaskN:                                                                                              *\n";
  cout << " *                                                            "
          "      "
          "                                              *\n";
  cout << " "
          "**************************************************************"
          "******"
          "**********************************************\n";
  
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

void Screen::ReloadTheScreenData(Company com1) {
  tempdata = com1.outputThisTime;
  receiveTaskNum = com1.receiveTaskNum;
  finishedTaskNum = com1.finishedTaskNum;
  outTimeTaskNum = com1.outTimeTaskNum;
  worldTime = com1.worldTime;
  totalAsset = com1.totalAsset;
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
