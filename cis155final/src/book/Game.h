// Game.h
#ifndef GAME_H_INCLUDED_
#define GAME_H_INCLUDED_

#include "TextRectangle.h"
#include "book/Simple_window.h" // get access to our library. 

class Game {
public:
    // Constructor
    Game(Simple_window& win);

    // Destructor
    ~Game();

    // Load next sentence from the input stream istr.
    // Returns true on success, false otherwise:
    bool read_sentence(istream& istr);

    // Make all words in the sentence visible:
    void unhide_words();

private:
    // Add a "word" to display. The "hidden" flag is
    // true when the word should be shown as blank:
    void add_word(string const& word, bool hidden);

    Vector< unsigned int > hidden_words;
    Vector_ref< TextRectangle > trects;
    Simple_window& win;

};//class Game

#endif //GAME_H_INCLUDED_
