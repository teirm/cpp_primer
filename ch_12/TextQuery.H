/* TextQuery Header */
#ifndef TEXTQUERY_GUARD
#define TEXTQUERY_GUARD

#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <sstream>

#include <cstdio>

class QueryResult {
public:
    QueryResult(const std::string &s, 
                std::shared_ptr<std::set<int>> sp, 
                std::shared_ptr<std::vector<std::string>> vp);
    void print();
private:
    std::string word;
    std::shared_ptr<std::set<int>> s_ptr;
    std::shared_ptr<std::vector<std::string>> v_ptr;
};

class TextQuery {
friend class QueryResult;
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &ifp);
    QueryResult queryWord(const std::string &s);
private:
    std::map<std::string,std::set<int>> wordMap;
    std::vector<std::string> lineVec;
};

#endif
