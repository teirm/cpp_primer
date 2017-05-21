/* The TextQuery class */

#include "TextQuery.H"

TextQuery::TextQuery(std::ifstream &ifp)
{
    int lineCounter = 0; 
    std::string line;
    
    while (getline(ifp ,line)) {
        std::string word;
        std::istringstream lineStream(line);
        
        while (lineStream >> word) {
            if (wordMap.find(word) != wordMap.end()) {
                wordMap[word].insert(lineCounter); 
            } else {
                std::set<int> lineSet = {lineCounter};
                wordMap.insert({word, lineSet});
            } 
        }
        lineVec.push_back(line);
        lineCounter++;
    }
}

QueryResult TextQuery::queryWord(const std::string &s)
{
    std::shared_ptr<std::vector<std::string>> v_ptr 
        = std::make_shared<std::vector<std::string>>(lineVec);
    
    std::shared_ptr<std::set<int>> s_ptr
        = std::make_shared<std::set<int>>(wordMap[s]);

    return QueryResult(s, s_ptr, v_ptr);

}
