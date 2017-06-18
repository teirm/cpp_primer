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

class QueryResult;

class TextQuery {
friend class QueryResult;
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &ifp);
    QueryResult query(const std::string &s) const;
private:
    std::map<std::string,std::set<int>> wordMap;
    std::vector<std::string> lineVec;
};

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(const std::string &s, 
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
    std::set<TextQuery::line_no>::iterator begin() {
        return lines->begin();
    }
    std::set<TextQuery::line_no>::iterator end() {
        return lines->end();
    }
    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }
private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


#endif
