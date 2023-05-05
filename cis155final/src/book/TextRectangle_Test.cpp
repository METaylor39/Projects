// TextRectangle.cpp
#include "TextRectangle.h"
using namespace Graph_lib;

TextRectangle::TextRectangle(Point xy, int ww, int hh, const string& str)
    :
    Graph_lib::Rectangle(xy, ww, hh),
    text{ Point(xy.x + 3, xy.y + hh - 6), str }
{
    set_font(Font::Font_type::courier);
}

void TextRectangle::draw_lines() const
{
    Graph_lib::Rectangle::draw_lines();
    if (text.label().empty()) {
        fl_line(point(0).x, point(0).y, point(0).x + width(), point(0).y + height());

    }
    else {
        Fl_Color oldc = fl_color();
        fl_color(text.color().as_int());
        text.draw_lines();
        fl_color(oldc);	// reset color (to pevious) and style (to default)
    }
}


void TextRectangle::text_hide()
{
    text.set_color (Graph_lib::Rectangle::fill_color());
}

void TextRectangle::text_show(Color col )
{
    text.set_color(col);
}

void TextRectangle::set_label(string const& label)
{
    text.set_label(label);
}

string TextRectangle::label() const
{
    return text.label();
}

void TextRectangle::set_font(Font f)
{
    text.set_font(f);
}

Font TextRectangle::font() const
{
    return text.font();
}

void TextRectangle::set_font_size(int s) {
    text.set_font_size(s);
}

int TextRectangle::font_size() const
{
    return text.font_size();
}
