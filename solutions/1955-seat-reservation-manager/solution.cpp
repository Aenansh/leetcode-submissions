class SeatManager {
    unordered_map<int, bool> seats;
    priority_queue<int, vector<int>, greater<int>> seatNo;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            seatNo.push(i);
        }
    }

    int reserve() {
        int s = seatNo.top();
        if (!seats[seatNo.top()]) {
            seats[seatNo.top()] = true;
            seatNo.pop();
        }
        return s;
    }

    void unreserve(int seatNumber) {
        if(seats[seatNumber]){
            seats[seatNumber] = false;
            seatNo.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
