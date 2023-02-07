/**
 * HaruPDF.cpp
 * Facade Class to interface with HaruPDF (libharu)
 * 
 * A2: Classes, Facades, and Makefiles
 * Author: Ari Lacanienta
 * Date: 01/24/2023
 * 
 * FUNCTIONALITY: setting up a document, placing text on a page, and saving the pdf.
 * */
#ifndef HARUPDF_H
#define HARUPDF_H

#include "hpdf.h"

class HaruPDF
{
private:
    /* data */
    HPDF_Doc  _pdf;
    HPDF_Font _font;
    HPDF_Page _page;
    
    char _filename[256];
public:
    /**
     * Creates a HaruPDF and prepares it for writing 
    */
    HaruPDF(char filename[256]);

    /**
    * Clean up memory used by HaruPDF
    */
    ~HaruPDF();
    
    /**
     * Places a letter on the page at a given x and y position with a given 
     * orientation
    */
    void placeLetter(char letter, double xpos, double ypos, double angle);

    /**
     * Places a letter on the page at a given x and y position with a default
     * orientation
    */
    void placeLetter(char letter, double xpos, double ypos);

    /**
     * Saves PDF with a new filename
    */
    void saveDocument(char filename[256]);

    /**
     * Saves PDF using filename given at construction
    */
    void saveDocument();
};

#endif