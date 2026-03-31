
struct Info {
  std::string value;
  int timestamp;
  Info(std::string value, int timestamp)
      : value(value), timestamp(timestamp) {};
};

class TimeMap {
public:
  std::unordered_map<std::string, std::vector<Info>> hash;
  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    if (hash.find(key) == hash.end())
      hash[key] = {};
    hash[key].push_back(Info(value, timestamp));
  }

  std::string get(std::string key, int timestamp) {
    auto it = hash.find(key);
    if (it == hash.end())
      return "";

    std::vector<Info> &temp = it->second;

    int l = 0;
    int r = temp.size() - 1;
    int result = -1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (temp[mid].timestamp <= timestamp) {
        result = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return (result == -1) ? "" : temp[result].value;
  }
};
