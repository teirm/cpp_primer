/* Folder class from 13.4 */

#include "Inbox.H"

void Folder::addMsg(Message *m)
{
    this->messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    this->messages.erase(m);
}

void Folder::add_to_Messages(const Folder& f)
{
    for (auto m : f.messages) {
        m->save(*this);
    }
}

void Folder::remove_from_Messages()
{
    for (auto m : messages) {
        m->remove(*this);
    }
    messages.clear();
}

Folder::Folder(const Folder &f):
    name(f.name)
{
    add_to_Messages(f);
}

Folder::~Folder()
{
    remove_from_Messages();
}

Folder& Folder::operator=(const Folder& rhs)
{
    remove_from_Messages(); 
    name = rhs.name;
    add_to_Messages(rhs); 
    return *this;
}

void Folder::debug_folder()
{
    std::cerr << "Folder: " << this->name << std::endl
              << "Messages:" << std::endl;

    for (auto m : this->messages) {
        std::cerr << "\tMessage: " << m->contents << std::endl;
    }
}


