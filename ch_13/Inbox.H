/* Message class from 13.4 */

#ifndef INBOX_GUARD
#define INBOX_GUARD

#include <string>
#include <set>
#include <iostream>

class Folder;

class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
public:
    // folders is initialized to the empty set
    explicit Message(const std::string &str = ""):
        contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void debug_message();    

private:
    std::string contents;
    std::set<Folder*> folders;
    // utility functions used by copy constructor, assignment, and 
    // destructor
    void add_to_Folders(const Message&);
    // remove this message from every Folder in folders
    void remove_from_Folders();
};

void swap(Message &lhs, Message &rhs);

class Folder {
    friend class Message;
public:
     explicit Folder(const std::string &str = ""):
         name(str) {}
     Folder(const Folder&);
     Folder& operator=(const Folder&);
     ~Folder();
     void addMsg(Message*);
     void remMsg(Message*);
    
     void debug_folder();

private:
     void add_to_Messages(const Folder&);
     void remove_from_Messages();
     std::string name;
     std::set<Message*> messages;
};

#endif
