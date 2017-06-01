/* A driver program to test the inbox program */

#include "Inbox.H"

using namespace std;

int main()
{
    
    Message message_a("a");
    Message message_b("b");

    Folder folder_1("1");
    Folder folder_2("2");

    message_a.save(folder_1);
    message_a.save(folder_2);

    message_a.debug_message();
    folder_1.debug_folder();

    Folder folder_3(folder_1);
    message_a.debug_message();

    {
        Folder folder_4("4");
        message_a.save(folder_4);
        message_a.debug_message();
    }

    message_a.debug_message();

    return 0;
}
