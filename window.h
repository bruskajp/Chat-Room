#ifndef __window__
#define __window__

#include <string>

using namespace std;

struct CurrentChar{
    int xPos;
    int yPos;
    char character;
};

class Window{
    public:
    int windowSize;
    char** window;
    CurrentChar currentChar;

    public:
    Window (int windowSize);
    void displayWindow();
    void blinkingCursor();
    void nextChar();
    void prevChar();
    void upChar();
    void downChar();
    void edit(const string & text);
};

#endif // __window__
