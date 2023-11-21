#pragma once


#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Book.h"
#include "DigitalMedia.h"

struct Library {
    struct Book books[MAX_BOOK_COUNT];
    struct EBook ebooks[MAX_EBOOK_COUNT];
    struct DigitalMedia digitalMedias[MAX_DIGITAL_MEDIA_COUNT];
    int bookCount;
    int ebookCount;
    int digitalMediaCount;
    char libraryName[MAX_NAME_LEN];
    int libraryID;
};


// Function prototypes
struct Library initializeLibrary();
void loadBooks(struct Library* lib, const char* filename);
void loadEbooks(struct Library* lib, const char* filename);
void loadDigitalMedia(struct Library* lib, const char* filename);
void displayBooks(const struct Library* lib);
void displayEbooks(const struct Library* lib);
void displayDigitalMedia(const struct Library* lib);
void printBookPublicationHistogram(const struct Library* lib);

// Function to initialize a book to a default state
void initializzeBook(struct Book* book);




#endif
