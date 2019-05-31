//
// Created by 张成敏 on 2019-05-04.
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
    // 先判断两个位置是否为建筑物或不可能点
    if (begin.roadJudge() && end.roadJudge()) {
        // 且不应横纵坐标同时为奇数
        if ((!(begin.returnTheXPosition() % 2 && begin.returnTheYPosition() % 2)) && (!(end.returnTheXPosition() % 2 && end.returnTheYPosition() % 2))) {
            // 开始计算
            Coordinate tempCoord = Coordinate(begin.returnTheXPosition(), begin.returnTheYPosition());
            // 由于时间关系采用暴力求解，遍历骑手可能的八个方向，找到相对目的地最近的位置定为下一个点，直至找到距离为0
            while (!(tempCoord.returnTheXPosition() == end.returnTheXPosition() && tempCoord.returnTheYPosition() == end.returnTheYPosition())) {
                int distance[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
                for (enum Coordinate::change i = Coordinate::change::leftUp; i <= Coordinate::change::downStraight; i = (Coordinate::change)(i + 1)) {
                    // 拷贝tempCoord
                    Coordinate copy = tempCoord;
                    // 让copy 行走
                    if (copy.move(i)) {
                        distance[i] = abs(copy.returnTheXPosition() - end.returnTheXPosition()) + abs(copy.returnTheYPosition() - end.returnTheYPosition());
                    }
                    // 计算与end距离
                }
                // 找到distance中最小的元素下标
                int theMindistance = 10000;
                std::deque<int> thetheMindistancePos;
                for (int j = 0; j < 8; j++) {
                    if (distance[j] != -1 && distance[j] <= theMindistance) {
                        theMindistance = distance[j];
                        thetheMindistancePos.push_back(j);
                    }
                }
				//遍历检查，使不符合要求的命令erase
                for (int i = 0; i < thetheMindistancePos.size(); i++) {
                    Coordinate copy = tempCoord;
                    copy.move((Coordinate::change)thetheMindistancePos.at(i));
                    if ((copy.returnTheXPosition() == end.returnTheXPosition() && copy.returnTheYPosition() != end.returnTheYPosition() && (!(end.returnTheXPosition() % 2))) || (copy.returnTheYPosition() == end.returnTheYPosition() && copy.returnTheXPosition() != end.returnTheXPosition() && (!(end.returnTheYPosition() % 2)))) {
                        thetheMindistancePos.erase(thetheMindistancePos.begin() + i);
                        i -= 1;
                    }
                }
				//通过下标使真正的tempCoord移动并加入路线
                tempCoord.move((Coordinate::change)thetheMindistancePos.at(0));
                routes.push_back(tempCoord);
            }
        }
    }
}
