#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#include "window.h"

using namespace std;

int main(){

    int windowSize;
    cout << "How big is the display? ";
    cin >> windowSize;
    Window window(windowSize);
    Messenger messenger;

    char input;
    string text;

    while(1){
        window.displayWindow();
        window.blinkingCursor();
        cin >> input;
        switch (input){
            case 'n':
                window.nextChar();
                break;
            case 'p':
                window.prevChar();
                break;
            case 'u':
                window.upChar();
                break;
            case 'd':
                window.downChar();
                break;
            case 'm':
                window.sendMessage();
                break;
            case 'e':
                cout << "New Text: ";
                cin >> text;
                window.edit(text);
                break;
            case 'q':
                return 0;
        }
    }
    return 1;
}

