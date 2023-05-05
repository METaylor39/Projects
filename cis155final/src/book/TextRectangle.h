// TextRectangle.h
#ifndef TEXTRECTANGLE_H_INCLUDED_
#define TEXTRECTANGLE_H_INCLUDED_

#include "book/Graph.h"          // get access to our graphics library facilities
#include "book/std_lib_facilities.h"

namespace Graph_lib {
    struct TextRectangle : Graph_lib::Rectangle {
        
            // constructor
            TextRectangle(Point xy, int ww, int hh, const string& str);

            // the drawing function
            void draw_lines() const;

            // update text label
            void set_label(string const& label);

            // get text label
            string label() const;

            // set font
            void set_font(Font f);

            // get font
            Font font() const;

            // set font size
            void set_font_size(int s);

                // get font size
                int font_size() const;

            // hide text label
            void text_hide();

            // show text label
            void text_show(Color col = Color::blue);

        private:
            Text text;

    };//struct TextRectangle

}//namespace Graph_lib

#endif //TEXTRECTANGLE_H_INCLUDED_
