class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }

    double times,timetotal;
    unordered_map<int,pair<string,int>>ininfo;
    unordered_map<string,pair<int,int>>outinfo;

    void checkIn(int id, string stationName, int t) {
        ininfo[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
       auto [ststation,sttime]=ininfo[id];
       int timec = t-sttime;
       string route = ststation +"->"+ stationName;
       outinfo[route].second +=1;
       outinfo[route].first +=timec;

    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation +"->"+  endStation;
        auto[timeused, times] = outinfo[route];
        return (double)timeused/times;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */