class Solution {
    double r,  x_center, y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double theta = ((double)rand() / RAND_MAX) * M_PI * 2;
        double len = sqrt((double)rand() / RAND_MAX) * r;
        
        return {x_center+cos(theta)*len, y_center+sin(theta)*len};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */