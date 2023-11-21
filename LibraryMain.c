#include <stdio.h>
#include <string.h>
#include "LibraryManagement.h"


int main() {

    // Step 1: Initialize the library to its default state
    struct Library myLibrary = initializeLibrary();

    // Step 2: Load physical books from a sample file named "books.txt"
    loadBooks(&myLibrary, "books.txt");
    // Note: You should have a file named "books.txt" with the appropriate structure and content for this to work.

    // Step 3: Load ebooks from a sample file named "ebooks.txt"
    loadEbooks(&myLibrary, "ebooks.txt");
    // Note: You should have a file named "ebooks.txt" with the appropriate structure and content for this to work.

    // Step 4: Load digital media from a sample file named "digitalmedia.txt"
    loadDigitalMedia(&myLibrary, "digitalmedia.txt");
    // Note: You should have a file named "digitalmedia.txt" with the appropriate structure and content for this to work.

    // Step 5: Display details of first 10 physical books loaded into the library
    displayBooks(&myLibrary);

    // Step 6.1 : Display details of first five ebooks loaded into the library
    displayEbooks(&myLibrary, 0);

    // Step 6.2: Display details of last five ebooks loaded into the library
    displayEbooks(&myLibrary, 1);

    // Step 7.1: Display details of first five digital media loaded into the library
    displayDigitalMedia(&myLibrary, 0);
    // Step 7.2: Display details of last five digital media loaded into the library
    displayDigitalMedia(&myLibrary, 1);
    // Step 7.3: Display details of middle five digital media loaded into the library
    displayDigitalMedia(&myLibrary, 2);

    // Setp 8: generate and print a histogram of the number of books published per year between 1800 and 2023
    printBookPublicationHistogram(&myLibrary);


    return 0;
}
