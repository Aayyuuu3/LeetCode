class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> ans;
        for(int k = 1; k <= n; k++){
            if(k % 3 == 0 && k % 5 == 0)
                ans.push_back("FizzBuzz");
            else if(k % 3 == 0)
                ans.push_back("Fizz");
            else if(k % 5 == 0)
                ans.push_back("Buzz");
            else
                ans.push_back(to_string(k));
        }
        return ans;
    }
};