class Solution {
public:
    string simplifyPath(string path) {
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/')
                path[i] = ' ';
        }

        stack<string> dir;
        stack<string> pth;

        stringstream ss(path);
        string w;
        while (ss >> w) {
            dir.push(w);
        }

        int cd = 0;
        while (!dir.empty()) {
            w = dir.top();
            dir.pop();

            if (w != ".." && w != ".") {
                pth.push(w);
            } else if (w == "..") {
                cd++;
                while (!dir.empty() && dir.top() == "..") {
                    cd++;
                    dir.pop();
                }
                while (!dir.empty() && cd > 0 && dir.top() != "..") {
                    if (dir.top() != ".")
                        cd--;
                    dir.pop();
                }

            } else {
                continue;
            }
        }

        if (pth.empty())
            return "/";

        string ans = "";
        while (!pth.empty()) {
            string p = pth.top();
            pth.pop();

            ans += "/" + p;
        }
        return ans;
    }
};
