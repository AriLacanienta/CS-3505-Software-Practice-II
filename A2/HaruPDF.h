#include "hpdf.h"

#ifndef HARUPDF_H
#define HARUPDF_H

class HaruPDF
{
private:
    /* data */
    HPDF_Doc  pdf;
    HPDF_Font font;
    HPDF_Page page;
    
    char filename[256];
public:
    HaruPDF(char filename[256]);
    ~HaruPDF();

    void placeLetter(char letter, double xpos, double ypos, double angle);
    void placeLetter(char letter, double xpos, double ypos);
    void saveDocument();
};

#endif