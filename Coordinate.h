//
// Created by �ų��� on 2019-04-25.
//

#ifndef TAKEAWAYASSIGNMENT0_1_COORDINATE_H
#define TAKEAWAYASSIGNMENT0_1_COORDINATE_H
#define BIRTHPOSITION_X 8
#define BIRTHPOSITION_Y 7

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Coordinate {
 private:
  int x;
  int y;

 public:
  enum change {
    leftUp,
    leftDown,
    rightUp,
    rightDown,
    rightStraight,
    leftStraight,
    upStraight,
    downStraight,
  };
  // Ĭ�Ϲ�����
  Coordinate();
  // ����������
  explicit Coordinate(int x1, int y1);
  // �������꺯��(���Ȩ��)
  void changeCoordinate(int x1, int y1);
  // ��������ƶ������ƶ�(��·�ϵ�����)
  bool move(change change1);
  // ����ͨ����һ����������ƶ�(��·�ϵĿ��ƶ�����)
  bool moveThourghtheIndsideCoordinate(Coordinate coordinate2);
  // �ж�һ�������Ƿ���·��(��·�Ϸ���true����false)
  bool roadJudge();
  // �ж����������Ƿ�����
  bool insideJudgeFromAnother(Coordinate coordinate2);
  // ����λ�����
  void tellPosition();
};

#endif  // TAKEAWAYASSIGNMENT0_1_COORDINATE_H
