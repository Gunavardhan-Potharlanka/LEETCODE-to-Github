class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp={{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        int i=10;
        string s="";
        while(num){
            int d=num%i;
            num-=d;
            if(d!=0 && mp[d]!="") s=mp[d]+s;
            else{
                int x=i/10;
                while(d){
                    if(mp[d]!=""){
                        s=mp[d]+s;
                        d=0;
                    }
                    else{
                        s=mp[x]+s;
                        d-=x;
                    }
                }
            }
            i=i*10;
        }
        return s;
    }
};