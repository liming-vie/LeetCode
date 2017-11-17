class Vector2D {
public:
    vector<vector<int>>::iterator iter2d_end;
    vector<vector<int>>::iterator iter2d;
    vector<int>::iterator iter;
    
    Vector2D(vector<vector<int>>& vec2d) {
        iter2d = vec2d.begin();
        iter2d_end = vec2d.end();
        if (iter2d!=iter2d_end) {
            iter = iter2d->begin();
        }
    }

    bool helper() {
        if (iter2d == iter2d_end) {
            return false;
        }
        while (iter==iter2d->end()) {
            if (++iter2d == iter2d_end) {
                return false;
            }
            iter = iter2d->begin();
        }
        return true;
    }
    
    int next() {
        helper();
        return *(iter++);
    }

    bool hasNext() {
        if (helper()) return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */