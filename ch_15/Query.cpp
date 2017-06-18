/* Implementation of the Query class */

#include "Query.H"

inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }
