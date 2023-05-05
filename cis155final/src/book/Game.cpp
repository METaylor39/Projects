//Game.cpp
#include "Game.h"
#include "TextRectangle.h"

Game::Game(Simple_window& win)
	: win{ win }
{
}


// Destructor
Game::~Game()
{
    for (unsigned int idx = 0; idx < trects.size(); ++idx) {
        win.detach(trects[idx]);
    }
}


// Load next sentence from the input stream istr.
// Returns true on success, false otherwise:
bool Game::read_sentence(istream& istr)
{
    string word;
    bool hidden = false;
    while (istr >> word) {
        if (word == ".") {
            return true;
        }
        if (word == "@") {
            hidden_words.push_back(trects.size());
            hidden = true;
            continue;
        }
        add_word(word, hidden);
        hidden = false;
    }
    return false;
}


// Make all words in the sentence visible:
void Game::unhide_words()
{
    for (unsigned int idx = 0; idx < hidden_words.size(); ++idx) {
        trects[hidden_words[idx]].text_show(Color::black);
    }
}

// Add a "word" to display. The "hidden" flag is
// true when the word should be shown as blank:
void Game::add_word(string const& word, bool hidden)
{
    trects.push_back(new TextRectangle(Point(50, 30 * trects.size() + 30), word.length() * 10, 20, word));
    TextRectangle& trect = trects[trects.size() - 1];
    //TextRectangle& trect = trects.back();
    if (hidden) {
        trect.set_fill_color(Color::green);
        trect.text_hide();
    }
    else {
        trect.set_fill_color(Color::blue);
        trect.text_show(Color::red);
    }
    trect.set_color(trect.fill_color());
    win.attach(trects[trects.size() - 1]);
   // win.attach(trects);
}
