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

/**
 * Creates a HaruPDF and prepares it for writing text
*/
HaruPDF::HaruPDF(char filename[256])
{
    strcpy(_filename, filename);
    _pdf = HPDF_New (NULL, NULL);
    
    // add a new page object.
    _page = HPDF_AddPage (_pdf);
    HPDF_Page_SetSize (_page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    
    // Text settings	
    HPDF_Page_BeginText (_page);
    _font = HPDF_GetFont (_pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (_page, 20);
    HPDF_Page_SetGrayStroke (_page, 0);
    HPDF_Page_SetFontAndSize (_page, _font, 30);
}


/**
 * Places a letter on the page at a given x and y position with a given 
 * orientation
*/
void HaruPDF::placeLetter(char letter, double xpos, double ypos, double rot) {

    HPDF_Page_SetTextMatrix(_page,
                            cos(rot),  sin(rot), // defines a rotation matrix 
                            -sin(rot), cos(rot), // to apply to the text
                            xpos, ypos);
    
    // C-style strings are null-terminated. The last character must a 0.
    char toPlace[2] = {letter, 0};
    HPDF_Page_ShowText (_page, toPlace);
    return;
}


/**
 * Places a letter on the page at a given x and y position with a default
 * orientation
*/
void HaruPDF::placeLetter(char letter, double xpos, double ypos) {
    placeLetter(letter, xpos, ypos, 0);
    return;
}


/**
 * Saves PDF with a new filename
*/
void HaruPDF::saveDocument(char filename[256]) {
    HPDF_Page_EndText (_page);
    HPDF_SaveToFile (_pdf, filename);
}


/**
 * Saves PDF using filename given at construction
*/
void HaruPDF::saveDocument() {
    saveDocument(_filename);
}


/**
 * Clean up memory used by HaruPDF
*/
HaruPDF::~HaruPDF()
{
    HPDF_Free (_pdf);
}