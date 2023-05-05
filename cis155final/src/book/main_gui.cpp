// main_gui.cpp
#include <fstream>

#include "book/Simple_window.h"  // get access to our window library
#include "TextRectangle.h"

#include "Game.h"

int main()
try
{
    using namespace Graph_lib;    // our graphics facilities are in Graph_lib

    Simple_window win(Point(100, 100), 220, 410, "CIS-155 Final Project");

    //replace istr with an input from "program_input.txt"
    /*
    istringstream istr{
        "An @ apple is a fruit that can be red, green, or yellow . "
        "Don't go outside until it @ stops raining . "
        "I am learning to @ drive a car . "
        "Finished, thank you! . "
    };
    */
    ifstream istr("program_input.txt" );
    if (!istr.is_open() ) {
        istringstream istr("program_input.txt does not exist .");
        Game game(win);
        if (!game.read_sentence(istr)) {
            error("!game.read_sentence(istr) failed");
        }
        win.wait_for_button(); //display
        game.unhide_words();
        win.wait_for_button();
        return 1;//display
    }
    for (;; ) {
        Game game(win);
        if (!game.read_sentence(istr)) {
            break;
        }
        win.wait_for_button();   // Display!
        game.unhide_words();
        win.wait_for_button();   // Display!
    }//endless loop
}//main
catch (exception& ex) {
    // some error reporting
    cerr << ex.what() << endl;
    return 1;
}
catch (...) {
    // some more error reporting
    cerr << "epic fail" << endl;
    return 2;
}