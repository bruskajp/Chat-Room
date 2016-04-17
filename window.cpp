#include <iostream>
#include <stdlib.h>
#include <unistd.h>

#include "window.h"

using namespace std;

Window::Window (int windowSize){
    this->windowSize = windowSize;
    window = new char*[2*windowSize];
    for(int yPos = 0; yPos < 2*windowSize; ++yPos){
        window[yPos] = new char[windowSize];
    }

    for(int yPos = 0; yPos < windowSize; ++yPos){
        for(int xPos = 0; xPos < 2*windowSize; ++xPos){
            window[yPos][xPos] = '_';
        }
    }
    currentChar.character = window[0][0];
    currentChar.xPos = 0;
    currentChar.yPos = 0;
}

void Window::displayWindow(){
    for(int yPos = 0; yPos < windowSize; ++yPos){
        for(int xPos = 0; xPos < 2*windowSize; ++xPos){
            cout << window[yPos][xPos] << ' ';
        }
        cout << endl;
    }
    cout << "Menu: next(n)  prev(p)  quit(q)    edit(e)" << endl;
    cout << "      up(u)    down(d)  message(m)" << endl;
    cout << "input: " << endl;
}

void Window::blinkingCursor(){
    usleep(1000000);
    currentChar.character = window[currentChar.yPos][currentChar.xPos];
    window[currentChar.yPos][currentChar.xPos] = '\u263A'; //'\u2588';
    displayWindow();
    usleep(1000000);
    window[currentChar.yPos][currentChar.xPos] = currentChar.character;
    displayWindow();
}

void Window::nextChar(){
    if(currentChar.xPos < 2*windowSize-1){
        ++currentChar.xPos;
        currentChar.character = window[currentChar.yPos][currentChar.xPos];
    }
}

void Window::prevChar(){
    if(currentChar.xPos > 0){
        --currentChar.xPos;
        currentChar.character = window[currentChar.yPos][currentChar.xPos];
    }
}

void Window::upChar(){
    if(currentChar.yPos > 0){
        --currentChar.yPos;
        currentChar.character = window[currentChar.yPos][currentChar.xPos];
    }
}

void Window::downChar(){
    if(currentChar.yPos < windowSize-1){
        ++currentChar.yPos;
        currentChar.character = window[currentChar.yPos][currentChar.xPos];
    }
}

void Window::edit(const string & text){
    int textCounter = 0;
    for (int windowCounter = currentChar.xPos; textCounter < text.length() && windowCounter < 2*windowSize; ++windowCounter){
        window[currentChar.yPos][windowCounter] = text[textCounter];
        ++ textCounter;
    }
}

void Window::sendMessage(){
    cout << "Message: ";
    cin >> messenger.message;
    messenger.send();
}
