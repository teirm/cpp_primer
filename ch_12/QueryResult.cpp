/* Query Result Class */

#include "TextQuery.H"

QueryResult::QueryResult(const std::string &s,
                         std::shared_ptr<std::set<int>> sp,
                         std::shared_ptr<std::vector<std::string>> vp):
                        word(s), s_ptr(sp), v_ptr(vp) {}

void QueryResult::print() 
{
    printf("%s occurs %lu times\n", word.c_str(), s_ptr->size()); 

    for (int lineNo : *s_ptr) {
        printf("\t(line %d) %s\n", lineNo, (*v_ptr)[lineNo].c_str()); 
    }
}
