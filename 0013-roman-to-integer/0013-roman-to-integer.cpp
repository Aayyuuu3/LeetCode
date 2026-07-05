class Solution {
public:
    int romanToInt(string s) {
        int n=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='I')
                n+=1;
            else if(s[i]=='V'){
                if(i>0 && s[i-1]=='I')
                    n+=4-1;
                else n+=5;
            }
            else if(s[i]=='X'){
                if(i>0 && s[i-1]=='I')
                    n+=9-1;
                else n+=10;
            }
            else if(s[i]=='L'){
                if(i>0 && s[i-1]=='X')
                    n+=40-10;
                else n+=50;
            }
            else if(s[i]=='C'){
                if(i>0 && s[i-1]=='X')
                    n+=90-10;
                else n+=100;
            }
            else if(s[i]=='D'){
                if(i>0 && s[i-1]=='C')
                    n+=400-100;
                else n+=500;
            }
            else if(s[i]=='M'){
                if(i>0 && s[i-1]=='C')
                    n+=900-100;
                else n+=1000;
            }
        }
        return n;
    }
};