#include <iostream>
#include <sstream>

#include<stdlib.h>
#include<stdio.h>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <windows.h>

using namespace std;
string kik_msg;
bool running = true;
string copyToClip(string s);
string tostr (int x);

string getMessage();
    static int sID = 0;
    static string msg = "msg.txt";
    static string id = "id.txt";
    static string msgSEQ = "msgSEQ.txt";
    static string was_me = "was_me.txt";
    static string jidFile = "jid.txt";
    static string stat_msg = "stat.txt";
    static string stat_jid = "statjid.txt";



int main()
{
     system("adb.exe pull /data/data/kik.pikek/databases/kikDatabase.db");
    system("sqlite3.exe kikDatabase.db \"select _id from messagesTable order by _id desc limit 1\">id.txt");
    ifstream firstMessage;
    if(!firstMessage){
        cout << "file not found" << endl;

    } else {
    firstMessage.open(id.c_str());
    firstMessage >> sID;
    }
    //sys reads as chars
    // c.str() to covert to string
string msg;
while(running) {
system ("adb.exe pull /data/data/kik.pikek/databases/kikDatabase.db");
system ("sqlite3.exe kikDatabase.db \"select body from messagesTable order by _id desc limit 1\">msg.txt");
system (("sqlite3.exe kikDatabase.db \"select partner_jid from messagesTable WHERE _id = \""+ tostr(sID)+"\"\">Jid.txt").c_str());
system(("sqlite3.exe kikDatabase.db \"select was_me from messagesTable WHERE _id = \""+ tostr(sID)+"\"\">was_me.txt").c_str());
system(("sqlite3.exe kikDatabase.db \"select stat_msg from messagesTable WHERE _id = \""+ tostr(sID)+"\"\">stat.txt").c_str());
system(("sqlite3.exe kikDatabase.db \"select stat_user_jid from messagesTable WHERE _id = \""+ tostr(sID)+"\"\">statjid.txt").c_str());
          copyToClip("PONG! DADDY BIT");
          system ("adb shell input tap 365.2 478.3");
          system("adb shell input keyevent 66");
//system ("sqlite3.exe kikDatabase.db \"select body from messagesTable WHERE _id = \""+ sID+"\"\">msgSEQ.txt");
    kik_msg = getMessage();
    if(kik_msg.find('.') == 0){
        kik_msg = kik_msg.substr(1,kik_msg.length());
            if( kik_msg == "ping"){
            copyToClip("PONG! DADDY BIT");
            system ("adb shell input tap 365.2 478.3");
            system("adb shell input keyevent 66");
     }
    }
      }
    return 0;
}
string copyToClip(string s){
          const char* output = s.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
    }

string getMessage(){
string messages;

ifstream readMessages;
if(!readMessages){
    cout << "file not found" << endl;
} else {
    readMessages.open(msg.c_str());
    readMessages >> messages;
}
return messages;
}
string tostr (int x)
{
    stringstream str;
    str << x;
    return str.str();
}
