class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        result.reserve(address.size() + 6);
        for(int i = 0; i < address.size(); i++){
            if(address[i] == '.')
                result += "[.]";
            else
                result += address[i];
        }
        return result;
    }
};