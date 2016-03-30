#ifndef __messenger__
#define __messenger__

#include <string>

using namespace std;

class Messenger{
    public:
    string message;

    bool send();
    bool recieve();
    bool encrypt();
    bool decrypt();
};

#endif // __messenger__
