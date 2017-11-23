class Solution {
public:
    string getHint(string secret, string guess) {
        int A=0, B=0;
        unordered_map<int, int> count;
        for (int i=0; i<secret.length(); ++i) {
            if (secret[i]==guess[i])    ++A;
            else    ++count[secret[i]];
        }
        for (int i=0; i<guess.length(); ++i) {
            if (secret[i]!=guess[i] && count[guess[i]]-->0)
                ++B;
        }
        stringstream ss;
        ss << A << "A" << B << "B";
        return ss.str();
    }
};