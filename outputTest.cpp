#include <windows.h>
#include <iostream>
#include <string>

bool PrintRectangle(int x);

using namespace std;
int main() {
  //	// 1 ʹ���Զ������
  // SetConsoleTitle(L"TakeawayAssignmentSystem 1.0 by Group 22");
  //// 2 Sleep������������ʹ��
  // cout << "Hello World!\n";
  // Sleep(1000);
  // system("cls");
  // cout << "George Zhang\n";

  // 3 ���Դ�ӡһ��������
  //PrintRectangle(3);
  system("pause");
  return 0;
}

// Print the 

// д����ĺ�����ʵ��Ӧ������ɨ�裩
bool PrintRectangle(int x) {
  if (x < 1) return false;
  cout << "   ";
  cout << "��";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < x; i++) {
    cout << "��";
  }
  cout << "|";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < 2*x; i++) {
    cout << " ";
  }
  cout << "|";
  cout << "��";
  cout << "\n";
  cout << "|";
  for (int i = 0; i < 2 * x; i++) {
    cout << " ";
  }
  cout << "|";
  cout << "\n";
  cout << " ";
  for (int i = 0; i < x; i++) {
    cout << "��";
  }
  return true;
}