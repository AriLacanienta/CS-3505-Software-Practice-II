#include "hpdf.h"

#ifndef HARUPDF_H
#define HARUPDF_H

class HaruPDF
{
private:
    /* data */
    HPDF_Doc  _pdf;
    HPDF_Font _font;
    HPDF_Page _page;
    
    char _filename[256];
public:
    HaruPDF(char filename[256]);
    ~HaruPDF();

    void placeLetter(char letter, double xpos, double ypos, double angle);
    void placeLetter(char letter, double xpos, double ypos);
    void saveDocument();
};

#endif