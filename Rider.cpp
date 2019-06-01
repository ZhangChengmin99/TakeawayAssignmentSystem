//
// Created by 张成敏 on 2019-04-25.
//

#include "Rider.h"

Rider::Rider()
{
    id = -1;
    totalProfitGet = 0;
    coordinateOfSelf = Coordinate();
}

Rider::Rider(int id1, int x, int y)
{
    id = id1; // id应该从总骑手数组中引用,通过id1传入
    totalProfitGet = 0;
    coordinateOfSelf = Coordinate(x, y);
    tempbesidesLOC = tempBesidesLOC();
    // 其余三个数据结构调用默认构造器
}

bool Rider::changeCoordinateOfSelfByRoutes()
{
    if (theRoute.routes.empty()) {
        return false;
    }
    Coordinate tempCoordinate = Rider::theRoute.routes.at(0);
    Rider::theRoute.routes.pop_front();
    return Rider::changeCoordinateOfSelf(tempCoordinate);
}

bool Rider::changeCoordinateOfSelf(Coordinate outCoordinate)
{
    return Rider::coordinateOfSelf.moveThourghtheIndsideCoordinate(outCoordinate);
}

bool Rider::moveFromChange(Coordinate::change change1)
{
    return Rider::coordinateOfSelf.move(change1);
}

void Rider::updateMytheRoute(int time)
{
    if (theTaskList.taskItems.empty()) {
        return;
    }
    // TODO::个人路径规划算法核心
    // 1 计算每一个订单的危机程度，
    // 1-1
    // 为了使用sort排序，先将所有订单从deque中迁移至vector,并在过程中计算每一单紧急时间
    if (theRoute.routes.empty()) {
        std::vector<TasksItem> tasks;
        for (auto i : theTaskList.taskItems) {
            // 紧急时间的分为两类，（1）运行未超过30订单（2）运行已超过30订单（3）分配完成后就已经完成的订单
            if (i.sendGoodState) {
                continue; // 已经送达，不考虑此订单
            } else {
                // 未送达的订单
                int time1 = time - i.receiveTime; // 1 计算已经经过时间time1
                int time2 = 0; // 2 从当前位置到饭店的最短时间
                int time3 = 0; // 3
                    // 若已取餐则为当前位置到顾客的最短时间，若未取餐则为饭店到顾客的最短时间
                    // 2 计算从当前位置到饭店的最短时间
                if (i.fetchGoodState) {
                    // 已经取餐
                    time2 = 0;
                    time3 = (abs(i.customerAdd.returnTheXPosition() - coordinateOfSelf.returnTheXPosition()) + abs(i.customerAdd.returnTheYPosition() - coordinateOfSelf.returnTheYPosition()) - 1) / 2;
                } else {
                    // 未取餐
                    time2 = (abs(i.restaurantAdd.returnTheXPosition() - coordinateOfSelf.returnTheXPosition()) + abs(i.restaurantAdd.returnTheYPosition() - coordinateOfSelf.returnTheYPosition()) - 1) / 2;
                    time3 = (abs(i.customerAdd.returnTheXPosition() - i.restaurantAdd.returnTheXPosition()) + abs(i.customerAdd.returnTheYPosition() - i.restaurantAdd.returnTheXPosition())) / 2;
                }
				// 暂时处理
                if (time - i.receiveTime < 30) {
                    i.emergencyTime = 30 - time1 - time2 - time3;

                } else {
                    // 已经超时的订单
                    i.emergencyTime = 60 - time1 - time2 - time3;
                }
            }
            tasks.push_back(i);
        }
        // 2 为了使用sort排序，让sort根据vector中的taskitem中危机时间重新排序还需重新定义小于号,已经重新定义
        sort(tasks.begin(), tasks.end());

        // 3 简易算法用于测试，直接去最紧急的单不管顺路
        // 3-1 确定目的地
        Coordinate des1 = coordinateOfSelf;
        if (!tasks.empty()) {
            if (tasks.at(0).fetchGoodState) {
                des1 = tasks.at(0).customerAdd;
            } else {
                des1 = tasks.at(0).restaurantAdd;
            }
        }
        // 确定一个相邻点先以右侧为准，最后一列建筑物以左侧为准
        if (!tasks.empty()) {
            if (des1.returnTheXPosition() == 16) {
                des1.changeCoordinate(des1.returnTheXPosition() - 1, des1.returnTheYPosition());
            } else {
                des1.changeCoordinate(des1.returnTheXPosition() + 1, des1.returnTheYPosition());
            }
        }
        // 3-2 计算目标与自身位置的中间路线拟合
        
        Route temproute = Route(coordinateOfSelf, des1);
        for (auto i : temproute.routes) {
            theRoute.routes.push_back(i);
        }
    }
}

int Rider::intimateMyRouteAndReturnIncreasedStepsNum(int num1,
    int receiveTime1,
    bool contributionState1,
    int riderId1,
    int restaurantAddX,
    int restaurantAddY,
    int customerAddX,
    int customerAddY)
{
    // TODO::个人路径规划算法核心,利用本骑手taskItemList中的全部任务外加输入任务返回步数增加数量
    int inimatedAllStep = -1;
    // TODO::计算部分
    //
    return theRoute.routes.size();
}

void Rider::updateMytaskListStateAfterMovement(int time)
{
    for (int i = 0; i < Rider::theTaskList.taskItems.size(); i++) {
        bool fetchchange = false;
        bool sendchange = false;
        if (Rider::coordinateOfSelf.insideJudgeFromAnother(
                theTaskList.taskItems[i].restaurantAdd)
            && (!theTaskList.taskItems[i].fetchGoodState)) {
            fetchchange = true;
            theTaskList.taskItems[i].changeFetchGoodState(true);
        }
        if (Rider::coordinateOfSelf.insideJudgeFromAnother(
                theTaskList.taskItems[i].customerAdd)
            && theTaskList.taskItems[i].fetchGoodState && (!theTaskList.taskItems[i].sendGoodState)) {
            sendchange = true;
            theTaskList.taskItems[i].changeSendDetailAndReturnFinishedTaskNo(true,
                time);
        }
        if (sendchange && fetchchange) {
            if ((theTaskList.taskItems[i].customerAdd.returnTheXPosition() == theTaskList.taskItems[i].restaurantAdd.returnTheXPosition()) && (theTaskList.taskItems[i].customerAdd.returnTheYPosition() == theTaskList.taskItems[i].restaurantAdd.returnTheYPosition())) {
                tempbesidesLOC.pushLOC(
                    tempBesidesLOC::resANDcus,
                    theTaskList.taskItems[i].customerAdd.returnTheXPosition(),
                    theTaskList.taskItems[i].customerAdd.returnTheYPosition());
            } else {
                tempbesidesLOC.pushLOC(
                    tempBesidesLOC::customer,
                    theTaskList.taskItems[i].customerAdd.returnTheXPosition(),
                    theTaskList.taskItems[i].customerAdd.returnTheYPosition());
                tempbesidesLOC.pushLOC(
                    tempBesidesLOC::resruant,
                    theTaskList.taskItems[i].restaurantAdd.returnTheXPosition(),
                    theTaskList.taskItems[i].restaurantAdd.returnTheYPosition());
            }

            continue;
        }
        if (sendchange == true && fetchchange == false) {
            tempbesidesLOC.pushLOC(
                tempBesidesLOC::customer,
                theTaskList.taskItems[i].customerAdd.returnTheXPosition(),
                theTaskList.taskItems[i].customerAdd.returnTheYPosition());
            continue;
        }
        if (sendchange == false && fetchchange == true) {
            tempbesidesLOC.pushLOC(
                tempBesidesLOC::resruant,
                theTaskList.taskItems[i].restaurantAdd.returnTheXPosition(),
                theTaskList.taskItems[i].restaurantAdd.returnTheYPosition());
            continue;
        }
    }
}

void Rider::outPutThisTimeANDresetTempBesidesLOC()
{
    using namespace std;
    ofstream outfile;
    outfile.open("output.txt", ios::app);
    outfile << "骑手" << id << "位置：" << coordinateOfSelf.returnTheXPosition()
            << "，" << coordinateOfSelf.returnTheYPosition() << "；停靠：";
    if (!tempbesidesLOC.restrantLOC.empty()) {
        outfile << "餐馆 ";
        for (auto i : tempbesidesLOC.restrantLOC) {
            outfile << i.x << " " << i.y << " ";
        }
    }
    if (!tempbesidesLOC.customerLOC.empty()) {
        outfile << "食客 ";
        for (auto i : tempbesidesLOC.customerLOC) {
            outfile << i.x << " " << i.y << " ";
        }
    }
    if (!tempbesidesLOC.resANDcusLOC.empty()) {
        outfile << "餐客 ";
        for (auto i : tempbesidesLOC.resANDcusLOC) {
            outfile << i.x << " " << i.y << " ";
        }
    }
    outfile << "；" << endl;
    outfile.close();
    tempbesidesLOC.resetMe();
}

OutputDataOfthisTime
Rider::returnOutputDataOfthisTimeAndPopFinishedTasks(int time)
{
    OutputDataOfthisTime tempOutput;
    tempOutput.increaseMySelfFromAnotherOutput(
        theTaskList.returnOutputDataOfthisTimeAndPopFinishedTasks(time));
    totalProfitGet += tempOutput.thisTimeProfitBesidesFINE - tempOutput.thisTimeFINE;
    return tempOutput;
}

void Rider::tellTheRider()
{
    std::cout << "**********************************************\n";
    std::cout << "1.The id:" << Rider::id << " rider data:\n";
    std::cout << "2.The position of self:\n";
    Rider::coordinateOfSelf.tellPosition();
    std::cout << "3.The Routes of the future:\n";
    Rider::theRoute.tellTheRoute();
    std::cout << "4.The TaskList:\n";
    Rider::theTaskList.tellTasksItemList();
    std::cout << "5.The Total Profit Gets: " << totalProfitGet << "$\n";
    std::cout << "**********************************************\n";
}

int Rider::getTheTotalProfit()
{
    return totalProfitGet;
}
