class Solution {
public:
    // мое решение
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        set<pair<int, int>> koef;
        for(int i = 1; i < coordinates.size(); i++) {
            pair<int, int> x = make_pair(coordinates[i][0] - coordinates[i - 1][0], 
                                         coordinates[i][1] - coordinates[i - 1][1]);
            koef.insert(x);
        }
        
        for(auto s : koef) {
            // cout << s.first << ", " << s.second << endl;
            int p = gcd(s.first, s.second);
            if(p != 1) {
                koef.erase(s);
                pair<int, int> x = make_pair(s.first / p, s.second / p);
                koef.insert(x);
            }
        }
        
        return koef.size() == 1;
    }
    
    // гениальное решение
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y = (coordinates[0][1] - coordinates[1][1]);
        int x = (coordinates[0][0] - coordinates[1][0]);
        float m = (float) y/x;
        
        float prev = m;
        for(int j = 1; j < coordinates.size() - 1; j++) {
            y = (coordinates[j][1] - coordinates[j + 1][1]);
            x = (coordinates[j][0] - coordinates[j + 1][0]);
            m = (float) y/x;
            
            if(m != prev) return false;
        }
        
        return true;
    }
};

int main() {
    // You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
    // Check if these points make a straight line in the XY plane.

    // Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    // Output: true

    // Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
    // Output: false

    return 0;
}