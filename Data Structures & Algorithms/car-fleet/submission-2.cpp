
struct car {
  int position;
  int speed;

  car(int position, int speed) : position(position), speed(speed) {}
};

class Solution {
public:
  int carFleet(int target, std::vector<int> &position,
               std::vector<int> &speed) {

    std::vector<car> cars;
    for (int i = 0; i < position.size(); ++i) {
      cars.push_back(car(position[i], speed[i]));
    }

    //  NOTE: Soring the car based on position
    std::sort(cars.begin(), cars.end(), [](car first, car second) {
      return first.position < second.position;
    });

    int fleet = 1;
    std::pair<int, int> last_car = {cars[cars.size() - 1].position,
                                    cars[cars.size() - 1].speed};
    for (int i = cars.size() - 2; i >= 0; --i) {
      if (last_car.second > cars[i].speed) {
        fleet++;
        last_car = {cars[i].position, cars[i].speed};
        continue;
      }

      float time1 = (target - last_car.first) / (float)last_car.second;
      float time2 = (target - cars[i].position) / (float)cars[i].speed;

      // std::cout << time1 << " " << time2 << std::endl;

      if (time1 < time2) {
        fleet++;
        last_car = {cars[i].position, cars[i].speed};
      }
    }

    return fleet;
  }
};


