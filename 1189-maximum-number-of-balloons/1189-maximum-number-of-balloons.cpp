class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int visited[26] = {0};
        for(int i=0; i<text.size(); i++){
            visited[text[i]-'a']++;
        }
        int count = 0;
        while(visited[0] >= 1 && visited[1] >= 1 && visited[11] >= 2 && 
                visited[13] >= 1 && visited[14] >= 2){
            visited[0] -= 1;
            visited[1] -= 1;
            visited[11] -= 2;
            visited[13] -= 1;
            visited[14] -= 2;
            count++;
        }
        return count;
    }
};