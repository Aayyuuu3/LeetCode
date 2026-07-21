class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int var = num/1000;
        ans.append(var,'M');
        num = num % 1000;
        if(num >= 900){
            ans.push_back('C');
            ans.push_back('M');
            num -= 900;
        }
        if(num>=500)
            ans.push_back('D');
        num = num % 500;
        if(num >= 400){
            ans.push_back('C');
            ans.push_back('D');
            num -= 400;
        }
        var = num/100;
        ans.append(var,'C');
        num = num % 100;
        if(num >= 90){
            ans.push_back('X');
            ans.push_back('C');
            num -= 90;
        }
        if(num>=50)
            ans.push_back('L');
        num %= 50;
        if(num >= 40){
            ans.push_back('X');
            ans.push_back('L');
            num -= 40;
        }
        var = num/10;
        ans.append(var,'X');
        num %= 10;
        if(num>= 9){
            ans.push_back('I');
            ans.push_back('X');
            num -= 9;
        }
        if(num >=5)
            ans.push_back('V');
        num %= 5;
        if(num >= 4){
            ans.push_back('I');
            ans.push_back('V');
            num -=4;
        }
        ans.append(num,'I');
        return ans;
    }
};