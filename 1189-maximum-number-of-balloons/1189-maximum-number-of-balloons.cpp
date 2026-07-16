class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int visited[26] = {0};
        for(int i=0; i<text.size(); i++)
            visited[text[i]-'a']++;
        int a = min(visited[0], visited[1]);
        int b = min(a, visited[11]/2);
        int c = min(b,visited[13]);
        int d = min(c,visited[14]/2);
        return d;
    }
};