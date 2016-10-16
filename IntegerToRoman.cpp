string c[4][10] = {   {"","I","II","III","IV","V","VI","VII","VIII","IX"},
                            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
                            {"", "M", "MM", "MMM"} };
class Solution {
public:
    string intToRoman(int num) {
        string str;
        int k=0;
        while(num) {
            str = c[k++][num % 10] + str;
            num /= 10;
        }
        return str;
    }
};