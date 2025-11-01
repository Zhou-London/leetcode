/* Car fleet */
// * Medium

#include <vector>
using namespace std;

class Solution
{
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, double>> cars;

        for (int i = 0; i < n; ++i)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleets = 0;
        double curTime = 0;

        for (auto &[pos, time] : cars)
        {
            if (time > curTime)
            {
                ++fleets;
                curTime = time;
            }
        }

        return fleets;
    }
};