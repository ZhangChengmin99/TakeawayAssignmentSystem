//
// Created by �ų��� on 2019-05-04.
//

#include "Route.h"

Route::Route()
{
    Coordinate coordinate;
    routes.insert(routes.begin(), 0, coordinate);
}

Route::Route(int num)
{
    Coordinate coordinate;
    routes.insert(routes.begin(), num, coordinate);
}

void Route::tellTheRoute()
{
    std::cout << "The route of this rider is:\n";
    for (auto x : routes) {
        x.tellPosition();
    }
}

void Route::addFrontCustomCoordinate(int x1, int y1)
{
    Coordinate coordinate = Coordinate(x1, y1);
    routes.push_front(coordinate);
}

void Route::addBackCustomCoordinate(int x1, int y1)
{
    Coordinate coordinate = Coordinate(x1, y1);
    routes.push_back(coordinate);
}

bool Route::increaseMyselfFromAnotherRoute(Route route1)
{
    if (!route1.routes.empty()) {
        for (auto i : route1.routes) {
            routes.push_back(i);
        }
        return true;
    } else {
        return false;
    }
}

Route::Route(Coordinate begin, Coordinate end)
{
    // ���ж�����λ���Ƿ�Ϊ������򲻿��ܵ�
    if (begin.roadJudge() && end.roadJudge()) {
        // �Ҳ�Ӧ��������ͬʱΪ����
        if ((!(begin.returnTheXPosition() % 2 && begin.returnTheYPosition() % 2)) && (!(end.returnTheXPosition() % 2 && end.returnTheYPosition() % 2))) {
            // ��ʼ����
            Coordinate tempCoord = Coordinate(begin.returnTheXPosition(), begin.returnTheYPosition());
            // ����ʱ���ϵ���ñ�����⣬�������ֿ��ܵİ˸������ҵ����Ŀ�ĵ������λ�ö�Ϊ��һ���㣬ֱ���ҵ�����Ϊ0
            while (!(tempCoord.returnTheXPosition() == end.returnTheXPosition() && tempCoord.returnTheYPosition() == end.returnTheYPosition())) {
                int distance[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
                for (enum Coordinate::change i = Coordinate::change::leftUp; i <= Coordinate::change::downStraight; i = (Coordinate::change)(i + 1)) {
                    // ����tempCoord
                    Coordinate copy = tempCoord;
                    // ��copy ����
                    if (copy.move(i)) {
                        distance[i] = abs(copy.returnTheXPosition() - end.returnTheXPosition()) + abs(copy.returnTheYPosition() - end.returnTheYPosition());
                    }
                    // ������end����
                }
                // �ҵ�distance����С��Ԫ���±�
                int theMindistance = 10000;
                std::deque<int> thetheMindistancePos;
                for (int j = 0; j < 8; j++) {
                    if (distance[j] != -1 && distance[j] <= theMindistance) {
                        theMindistance = distance[j];
                        thetheMindistancePos.push_back(j);
                    }
                }
				//������飬ʹ������Ҫ�������erase
                for (int i = 0; i < thetheMindistancePos.size(); i++) {
                    Coordinate copy = tempCoord;
                    copy.move((Coordinate::change)thetheMindistancePos.at(i));
                    if ((copy.returnTheXPosition() == end.returnTheXPosition() && copy.returnTheYPosition() != end.returnTheYPosition() && (!(end.returnTheXPosition() % 2))) || (copy.returnTheYPosition() == end.returnTheYPosition() && copy.returnTheXPosition() != end.returnTheXPosition() && (!(end.returnTheYPosition() % 2)))) {
                        thetheMindistancePos.erase(thetheMindistancePos.begin() + i);
                        i -= 1;
                    }
                }
				//ͨ���±�ʹ������tempCoord�ƶ�������·��
                tempCoord.move((Coordinate::change)thetheMindistancePos.at(0));
                routes.push_back(tempCoord);
            }
        }
    }
}
