class UndergroundSystem {
    unordered_map<int, pair<string, int> > in_time;
    unordered_map<string, pair<double, int> > total_time;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in_time[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string s = in_time[id].first + "_" + stationName;
        if(total_time.count(s)) {
            total_time[s].first += t-in_time[id].second;
            total_time[s].second ++;
        } else {
            total_time[s] = make_pair((double)(t-in_time[id].second), 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string s = startStation + "_" + endStation;
        return total_time[s].first/total_time[s].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */