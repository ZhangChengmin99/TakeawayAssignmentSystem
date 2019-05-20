#include <windows.h>
#include <iostream>
#include <string>
#include "Company.h"

typedef struct tempLoc {
  int x;
  int y;
} tempLoc;

bool PrintRectangle(int x);
void PrintReferencedNumX();

using namespace std;

int main() {
  // 0 ʹ���Զ������
  SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  // 1 ���ɼٹ�˾���������
  Company com1 = Company(3, 8, 7);
  com1.riderGroup.riders[0].coordinateOfSelf.changeCoordinate(15, 0);
  com1.riderGroup.riders[1].coordinateOfSelf.changeCoordinate(1, 14);
  // 2 ������������λ�õĶ��б���λ��
  std::deque<tempLoc> tempLOC;
  for (int i = 0; i < com1.riderGroup.riders.size(); i++) {
    tempLoc temp;
    temp.x = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheXPosition();
    temp.y = com1.riderGroup.riders.at(i).coordinateOfSelf.returnTheYPosition();
    tempLOC.push_back(temp);
  }
  // 3 ���Դ�ӡ��-1��
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
  cout << "   16   ";

  // ***************** ��ӡ��0�� ******************
  // 4 ���Դ�ӡ��0-0(0)��
  int count = 0;
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|������|����";
  cout << "|������|";
  // 5 ���Դ�ӡ��0-1(1)�� ��Ҫ������λ���ж��߼�
  cout << "\n0" << count;
  count += 1;
  if (tempLOC.size() == 0) {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      cout << "  ";
      putchar(' ');
    }
  } else {
    for (int i = 0; i < 8; i++) {
      cout << "|      | ";
      bool flag = false;
      for (int k = 0; k < tempLOC.size();k++) {
        if (tempLOC.at(k).y == 0 && tempLOC.at(k).x == 2 * i + 1) {
          flag = true;
          tempLOC.erase(tempLOC.begin() + k);
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
  // *********************************************


  // ***************** ��ӡ��1�� ******************
  cout << "|      |";
  // 6 ���Դ�ӡ��0-2(2)��
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |";
  // 7 ���Դ�ӡ��1-0(3)��
  cout << "\n  ";
  cout << "|������     ";
  for (int i = 0; i < 7; i++) cout << " ������     ";
  cout << " ������|";
  // 7 ���Դ�ӡ��1-1(4)�� ��Ҫ������λ���ж��߼�
  cout << "\n0" << count;
  count += 1;
  cout << "|  ��       ";
  for (int i = 0; i < 7; i++) cout << "   ��       ";
  cout << "   ��  |";
  // 7 ���Դ�ӡ��1-2(5)��
  cout << "\n  ";
  cout << "|           ";
  for (int i = 0; i < 7; i++) cout << "            ";
  cout << "       |";
 

  // ***************** ��ӡѭ�� ******************
  while (count < 16) {
    cout << "\n  ";
    for (int i = 0; i < 8; i++) cout << "|������|    ";
    cout << "|������|";
    // 5 ���Դ�ӡ��0-1(1)��
    if (count < 10) {
      cout << "\n0" << count;
    } else {
      cout << "\n" << count;
    }
    count += 1;
    for (int i = 0; i < 8; i++) cout << "|      |    ";
    cout << "|      |";
    // 6 ���Դ�ӡ��0-2(2)��
    cout << "\n  ";
    for (int i = 0; i < 8; i++) cout << "|      |    ";
    cout << "|      |";
    // 7 ���Դ�ӡ��1-0(3)��
    cout << "\n  ";
    cout << "|������     ";
    for (int i = 0; i < 7; i++) cout << " ������     ";
    cout << " ������|";
    // 7 ���Դ�ӡ��1-1(4)��
    if (count < 10) {
      cout << "\n0" << count;
    } else {
      cout << "\n" << count;
    }
    count += 1;
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
    // 7 ���Դ�ӡ��1-2(5)��
    cout << "\n  ";
    cout << "|           ";
    for (int i = 0; i < 7; i++) cout << "            ";
    cout << "       |";
  }
  // *********************************************


  // ***************** ��ӡ��16�� ******************
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|������|    ";
  cout << "|������|";
  // 5 ���Դ�ӡ��0-1(1)��
  if (count < 10) {
    cout << "\n0" << count;
  } else {
    cout << "\n" << count;
  }
  count += 1;
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |";
  // 6 ���Դ�ӡ��0-2(2)��
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << "|      |    ";
  cout << "|      |";
  cout << "\n  ";
  for (int i = 0; i < 8; i++) cout << " ������ ����";
  cout << " ������ ";
  // *********************************************

  //
  getchar();
  return 0;
}

// Print the

// д����ĺ�����ʵ��Ӧ������ɨ�裩
bool PrintRectangle(int x) {
  if (x < 1) return false;
  cout << "";
  cout << "  ��";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < x; i++) {
    cout << "��";
  }
  cout << "|��";
  cout << "\n ";
  for (int i = 0; i < x; i++) {
    cout << "��";
  }
  return true;
}

// ��ӡ�ο���������
void PrintReferencedNumX() {
  // Ԥ���ο�������
  cout << "  ";
  for (int i = 0; i < 17; i++) {
    cout << "   ";
    if (i < 10) {
      cout << "0" << i;
    } else {
      cout << i;
    }
    cout << "    ";
  }
  putchar('\n');
}