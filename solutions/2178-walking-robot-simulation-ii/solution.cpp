class Robot {
    int pos, w, h, p;
    bool hasMoved;

public:
    Robot(int width, int height) {
        w = width - 1;
        h = height - 1;
        p = 2 * w + 2 * h;
        pos = 0;
        hasMoved = false;
    }

    void step(int num) {
        hasMoved = true;
        pos = (pos + num) % p;
    }

    vector<int> getPos() {
        if (pos <= w)
            return {pos, 0};
        else if (pos <= w + h)
            return {w, pos - w};
        else if (pos <= 2 * w + h)
            return {w - (pos - (w + h)), h};
        else
            return {0, h - (pos - (2 * w + h))};
    }

    string getDir() {
        if (pos == 0)
            return hasMoved ? "South" : "East";
        else if (pos <= w)
            return "East";
        else if (pos <= w + h)
            return "North";
        else if (pos <= 2 * w + h)
            return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
