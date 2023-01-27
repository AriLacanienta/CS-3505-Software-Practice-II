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
#include <math.h>
#include <string.h>
#include "HaruPDF.h"

// DEBUG
#include <iostream>

HaruPDF::HaruPDF(char filename[256])
{
    strcpy(_filename, filename);
    _pdf = HPDF_New (NULL, NULL);
    
    /* add a new page object. */
    _page = HPDF_AddPage (_pdf);
    HPDF_Page_SetSize (_page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    // print_grid  (_pdf, _page);
    
    HPDF_Page_BeginText (_page);
    // Set the font	
    _font = HPDF_GetFont (_pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (_page, 20);
    HPDF_Page_SetGrayStroke (_page, 0);
    HPDF_Page_SetFontAndSize (_page, _font, 30);
}

void HaruPDF::placeLetter(char letter, double xpos, double ypos, double rot) {
// This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
    HPDF_Page_SetTextMatrix(_page,
                            cos(rot),  sin(rot), 
                            -sin(rot), cos(rot),
                            xpos, ypos);
    
    // C-style strings are null-terminated. The last character must a 0.
    char toPlace[2] = {letter, 0};
    HPDF_Page_ShowText (_page, toPlace);
    return;
}

void HaruPDF::placeLetter(char letter, double xpos, double ypos) {
    placeLetter(letter, xpos, ypos, 0);
    return;
}

void HaruPDF::saveDocument() {
    HPDF_Page_EndText (_page);
    if (HPDF_SaveToFile (_pdf, _filename) == HPDF_OK) {
        std::cout << _filename << " saved." << std::endl;
    }

}

HaruPDF::~HaruPDF()
{
    /* clean up */
    HPDF_Free (_pdf);
}
