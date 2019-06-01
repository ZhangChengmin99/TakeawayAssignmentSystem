//
// Created by �ų��� on 2019-04-25.
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
    id = id1; // idӦ�ô�����������������,ͨ��id1����
    totalProfitGet = 0;
    coordinateOfSelf = Coordinate(x, y);
    tempbesidesLOC = tempBesidesLOC();
    // �����������ݽṹ����Ĭ�Ϲ�����
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
    // TODO::����·���滮�㷨����
    // 1 ����ÿһ��������Σ���̶ȣ�
    // 1-1
    // Ϊ��ʹ��sort�����Ƚ����ж�����deque��Ǩ����vector,���ڹ����м���ÿһ������ʱ��
    if (theRoute.routes.empty()) {
        std::vector<TasksItem> tasks;
        for (auto i : theTaskList.taskItems) {
            // ����ʱ��ķ�Ϊ���࣬��1������δ����30������2�������ѳ���30������3��������ɺ���Ѿ���ɵĶ���
            if (i.sendGoodState) {
                continue; // �Ѿ��ʹ�����Ǵ˶���
            } else {
                // δ�ʹ�Ķ���
                int time1 = time - i.receiveTime; // 1 �����Ѿ�����ʱ��time1
                int time2 = 0; // 2 �ӵ�ǰλ�õ���������ʱ��
                int time3 = 0; // 3
                    // ����ȡ����Ϊ��ǰλ�õ��˿͵����ʱ�䣬��δȡ����Ϊ���굽�˿͵����ʱ��
                    // 2 ����ӵ�ǰλ�õ���������ʱ��
                if (i.fetchGoodState) {
                    // �Ѿ�ȡ��
                    time2 = 0;
                    time3 = (abs(i.customerAdd.returnTheXPosition() - coordinateOfSelf.returnTheXPosition()) + abs(i.customerAdd.returnTheYPosition() - coordinateOfSelf.returnTheYPosition()) - 1) / 2;
                } else {
                    // δȡ��
                    time2 = (abs(i.restaurantAdd.returnTheXPosition() - coordinateOfSelf.returnTheXPosition()) + abs(i.restaurantAdd.returnTheYPosition() - coordinateOfSelf.returnTheYPosition()) - 1) / 2;
                    time3 = (abs(i.customerAdd.returnTheXPosition() - i.restaurantAdd.returnTheXPosition()) + abs(i.customerAdd.returnTheYPosition() - i.restaurantAdd.returnTheXPosition())) / 2;
                }
				// ��ʱ����
                if (time - i.receiveTime < 30) {
                    i.emergencyTime = 30 - time1 - time2 - time3;

                } else {
                    // �Ѿ���ʱ�Ķ���
                    i.emergencyTime = 60 - time1 - time2 - time3;
                }
            }
            tasks.push_back(i);
        }
        // 2 Ϊ��ʹ��sort������sort����vector�е�taskitem��Σ��ʱ���������������¶���С�ں�,�Ѿ����¶���
        sort(tasks.begin(), tasks.end());

        // 3 �����㷨���ڲ��ԣ�ֱ��ȥ������ĵ�����˳·
        // 3-1 ȷ��Ŀ�ĵ�
        Coordinate des1 = coordinateOfSelf;
        if (!tasks.empty()) {
            if (tasks.at(0).fetchGoodState) {
                des1 = tasks.at(0).customerAdd;
            } else {
                des1 = tasks.at(0).restaurantAdd;
            }
        }
        // ȷ��һ�����ڵ������Ҳ�Ϊ׼�����һ�н����������Ϊ׼
        if (!tasks.empty()) {
            if (des1.returnTheXPosition() == 16) {
                des1.changeCoordinate(des1.returnTheXPosition() - 1, des1.returnTheYPosition());
            } else {
                des1.changeCoordinate(des1.returnTheXPosition() + 1, des1.returnTheYPosition());
            }
        }
        // 3-2 ����Ŀ��������λ�õ��м�·�����
        
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
    // TODO::����·���滮�㷨����,���ñ�����taskItemList�е�ȫ����������������񷵻ز�����������
    int inimatedAllStep = -1;
    // TODO::���㲿��
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
    outfile << "����" << id << "λ�ã�" << coordinateOfSelf.returnTheXPosition()
            << "��" << coordinateOfSelf.returnTheYPosition() << "��ͣ����";
    if (!tempbesidesLOC.restrantLOC.empty()) {
        outfile << "�͹� ";
        for (auto i : tempbesidesLOC.restrantLOC) {
            outfile << i.x << " " << i.y << " ";
        }
    }
    if (!tempbesidesLOC.customerLOC.empty()) {
        outfile << "ʳ�� ";
        for (auto i : tempbesidesLOC.customerLOC) {
            outfile << i.x << " " << i.y << " ";
        }
    }
    if (!tempbesidesLOC.resANDcusLOC.empty()) {
        outfile << "�Ϳ� ";
        for (auto i : tempbesidesLOC.resANDcusLOC) {
            outfile << i.x << " " << i.y << " ";
        }
    }
    outfile << "��" << endl;
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
