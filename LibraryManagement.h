
#pragma once


                                   //A header file in C for a library management system. 
#ifndef LIBRARYMANAGEMENT_H       //It includes definitions for the structure of a library and function prototypes for managing library operations.
#define LIBRARYMANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Book.h"
#include "DigitalMedia.h"

struct Library {                       //The Library structure serves as the central record-keeping entity for managing collections of books, ebooks, and digital media. 
    struct Book books[MAX_BOOK_COUNT]; //It represents the entirety of a library's catalog and provides a top-level view of all assets.
    struct EBook ebooks[MAX_EBOOK_COUNT];
    struct DigitalMedia digitalMedias[MAX_DIGITAL_MEDIA_COUNT];
    int bookCount;
    int ebookCount;
    int digitalMediaCount;
    char libraryName[MAX_NAME_LEN];
    int libraryID;
};


// Function prototypes for fucntions that will be used throughout the system.
struct Library initializeLibrary();
void loadBooks(struct Library* lib, const char* filename);
void loadEbooks(struct Library* lib, const char* filename);
void loadDigitalMedia(struct Library* lib, const char* filename);
void displayBooks(const struct Library* lib);
void displayEbooks(const struct Library* lib);
void displayDigitalMedia(const struct Library* lib);
void printBookPublicationHistogram(const struct Library* lib);

// Function to initialize a book to a default state
void initializeBook(struct Book* book);

