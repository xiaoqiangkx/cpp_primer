#include <iostream>
#include <string>
#include <set>
using namespace std;

class Message;

class Folder {
    public:
        void save(Message& mes) {
            messages.insert(&mes);
        }
        void remove(Message& mes) {
            messages.erase(&mes);
        }

        ~Folder();
    private:
        set<Message*> messages;    
        void remove_folder_in_messages();
};

class Message {
    public:
        Message(const string &str = ""): content(str) {}
        Message(const Message& mes): content(mes.content) {
            folders = mes.folders;
            put_msg_in_folders();
        }

        Message& operator=(const Message& mes) {
            Message *message = new Message(mes);
            return *message;
        }

        void save(Folder& folder) {
            folders.insert(&folder);
            folder.save(*this);
        }

        void remove(Folder& folder) {
            folders.erase(&folder);
            folder.remove(*this);
        }

        ~Message() {
            remove_msg_in_folders();
        }
    private:
        string content;
        set<Folder*> folders;
        void remove_msg_in_folders() {
            typedef set<Folder*>::iterator it_type;
            for (it_type it = folders.begin(); it != folders.end(); it++) {
                (*it)->remove(*this);
            }
        }

        void put_msg_in_folders() {
            typedef set<Folder*>::iterator it_type;
            for (it_type it = folders.begin(); it != folders.end(); it++) {
                (*it)->save(*this);
            }
            
        }
};

void Folder::remove_folder_in_messages() {
    typedef set<Message*>::iterator it_type;
    for (it_type it = messages.begin(); it != messages.end(); it++)             {
        (*it)->remove(*this);
    }
    
}

Folder::~Folder() {
   remove_folder_in_messages(); 
}

int main(int argc, char* argv[]) {
    Message s1("hello1");
    Folder f1;
    f1.save(s1);
    s1.save(f1);
    Message s2 = s1;
    Message s3(s1);

    return 0;
}
