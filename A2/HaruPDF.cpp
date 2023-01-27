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
#include "HaruPDF.h"

// DEBUG
#include <iostream>

HaruPDF::HaruPDF(char filename[256]) : filename{filename[256]}
{
    pdf = HPDF_New (NULL, NULL);
    
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    // print_grid  (pdf, page);
    
    HPDF_Page_BeginText (page);
    // Set the font	
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetFontAndSize (page, font, 30);
}

void HaruPDF::placeLetter(char letter, double xpos, double ypos, double rot) {
// This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
    HPDF_Page_SetTextMatrix(page,
                            cos(rot),  sin(rot), 
                            -sin(rot), cos(rot),
                            xpos, ypos);
    
    // C-style strings are null-terminated. The last character must a 0.
    char toPlace[2] = {letter, 0};
    HPDF_Page_ShowText (page, toPlace);
    return;
}

void HaruPDF::placeLetter(char letter, double xpos, double ypos) {
    placeLetter(letter, xpos, ypos, 0);
    return;
}

void HaruPDF::saveDocument() {
    HPDF_Page_EndText (page);
    if (HPDF_SaveToFile (pdf, filename) == HPDF_OK) {
        std::cout << filename << " saved." << std::endl;
    }

}

HaruPDF::~HaruPDF()
{
    /* clean up */
    HPDF_Free (pdf);
}
