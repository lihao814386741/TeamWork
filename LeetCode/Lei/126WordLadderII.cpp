class Solution {
public:
    void getDiff1s(string s, unordered_set<string>& adjlist, const unordered_set<string>& wordList)
    {
      for(int i=0; i<s.length(); i++)
      {
        string strback=s;
        for(char c='a'; c<='z'; c++)
        {
          strback[i]=c;
          auto it = wordList.find(strback);
          if(it!=wordList.end()&&adjlist.find(*it)==adjlist.end())
            adjlist.insert(strback);
        }
      }
    }
    //backtracking
    void genResult(int level,int targetLen,string end,vector<string>& path,unordered_map<string,unordered_set<string>>& adjList,vector<vector<string>>& result)
    {
      string curStr=path[path.size()-1];
      if(level==targetLen)
      {
        if(curStr==end) //important
          result.push_back(path);
        return;
      }
      for(auto it=adjList[curStr].begin();it!=adjList[curStr].end();it++)
      {
        path.push_back(*it);
        genResult(level+1,targetLen,end,path,adjList,result);
        path.pop_back();
      }
    }
    //idea: first BFS to find all word difference between 1 letter, then DFS to search all results
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &wordList) {
        unordered_map<string, unordered_set<string>> adjList; //construct adjacent map创建一个有向无环图
        if(wordList.find(start)!=wordList.end())
          wordList.erase(start);
        //build adjList
        queue<string> q;
        q.push(start);
        int level = 0;
        while(!q.empty())
        {
          q.push(""); //"" or NULL to split cur level and next level
          bool toEnd=false;
          unordered_set<string> toDelete;
          while(q.front()!="")
          {
            string it = q.front();
            q.pop();
            unordered_set<string> adj;
            getDiff1s(it,adj,wordList);
            adjList[it]=adj; //store it all 1 letter difference words
            for(auto it=adj.begin();it!=adj.end();it++)
            {
              //q.push(*it); //no! may TLE because q would add same words, such as hit->ait and hat then ait->aat,hat->aat
              toDelete.insert(*it);
              if(*it==end)
                toEnd=true;
            }
          }
          if(toDelete.size()==0)
            return vector<vector<string>> ();
          for(auto it=toDelete.begin();it!=toDelete.end();it++)
          {
            q.push(*it);
            wordList.erase(*it);
          }
          q.pop(); //pop ""
          level++;
          if(toEnd) //find the smallest path
            break;
        }
        vector<vector<string>> result;
        vector<string> path(1,start);
        //adjList contains the smallest path, but not all the path is valid
        //valid: path's length is level AND the last one is end
        genResult(0,level,end,path,adjList,result);
        return result;
    }
};
