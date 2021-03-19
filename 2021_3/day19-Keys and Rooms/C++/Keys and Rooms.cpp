class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> opened_room ;
        queue<int> wait_open;
        wait_open.push(0);
        opened_room.insert(0);
        
        while(!wait_open.empty() && opened_room.size() < rooms.size()) {
            int open = wait_open.front();
            wait_open.pop();
            
            for(auto room: rooms[open]) {
                if(!opened_room.count(room))
                    wait_open.push(room);
                opened_room.insert(room);
            }
        }
        
        if(opened_room.size() == rooms.size())
            return true;
        
        return false;
    }
};