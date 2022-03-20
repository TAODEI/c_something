#include <iostream>
using namespace std;

class Building {
  private:
    int roomNum;

  protected:
    int floorNum;
    int id;
    float area;

  public:
    Building(int floorNum, int id, int roomNum, float area)
        : floorNum(floorNum), id(id), roomNum(roomNum), area(area) {}
    int GetRoomNumber() {
        return roomNum;
    }
};

class TeachBuilding : public Building {
  private:
    int classNum;

  public:
    TeachBuilding(int floorNum, int id, int roomNum, float area)
        : Building(floorNum, id, roomNum, area) {
        classNum = GetRoomNumber();
    }
};

class DormBuilding : public Building {
  private:
    int dormNum;
    int maxStudentNum;

  public:
    DormBuilding(int floorNum, int id, int roomNum, float area, int num)
        : Building(floorNum, id, roomNum, area) {
        dormNum = GetRoomNumber();
        maxStudentNum = num;
    }
};