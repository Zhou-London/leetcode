/* Time based key-value store */
// * Medium

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap
{
  public:
    using Timestamp = int;
    unordered_map<string, vector<pair<Timestamp, string>>> store;

    TimeMap() = default;

    void set(string key, string value, Timestamp timestamp)
    {
        store[key].emplace_back(timestamp, value);
    }

    string get(string key, Timestamp timestamp)
    {
        if (!store.count(key))
            return "";

        const auto &vec = store[key];
        int left = 0, right = vec.size() - 1;
        string res = "";

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (vec[mid].first <= timestamp)
            {
                res = vec[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */