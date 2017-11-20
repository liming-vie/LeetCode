class Solution {
public:
    int calPoints(vector<string>& ops) {
        long sum = 0;
        int tmp;
        vector<long> vec;
        for (const auto& str : ops) {
            switch (str[0]) {
                case 'D':
                    tmp = vec.back()*2;
                    sum += tmp;
                    vec.push_back(tmp);
                    break;
                case 'C':
                    sum -= vec.back();
                    vec.pop_back();
                    break;
                case '+':
                    tmp = vec.back() + vec[vec.size()-2];
                    sum += tmp;
                    vec.push_back(tmp);
                    break;
                default:
                    tmp = atoi(str.c_str());
                    sum += tmp;
                    vec.push_back(tmp);
            }
        }
        return sum;
    }
};