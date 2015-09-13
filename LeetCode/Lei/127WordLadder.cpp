class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        map<string, int> dis; //store distance + delete duplicate elements
        dis[beginWord]=1;
        queue<string> m;
        m.push(beginWord);
        
        while(!m.empty())
        {
          string word = m.front();
          m.pop();
          if(word==endWord)
          {
            break;
          }
          
          for(int i=0; i<int(word.size()); i++)
          {
            string temp = word;
            for(char c='a'; c<='z'; c++)
            {
              temp[i]=c;
              if(wordDict.count(temp)!=0&&dis.count(temp)==0)
              {
                dis[temp]=dis[word]+1;
                m.push(temp);
              }
            }
          }
        }
    return (dis.count(endWord)==0)?0:dis[endWord];
    }
};
