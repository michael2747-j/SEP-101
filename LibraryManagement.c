
///////////////////////////////////////////////////////////////////////////
// File Name: Libarary Management System
// Group Number:  4
// Group Members Names : MICHAEL MELLES (111838223), Zunayed Ahmed, SHEHBAJ SINGH NIJJER(153166228)
// Group Members Seneca Email : mmellese@myseneca.ca, ssnijjer@myseneca.ca, zahmed79@myseneca.ca, ayush1@myseneca.ca
// Date : 21/11 2023
// Authenticity Declaration :
// We declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider.This submitted
// piece of work is entirely of my own creation.
//////////////////////////////






#define _CRT_SECURE_NO_WARNINGS
#include "LibraryManagement.h"
#include "LibraryConfig.h"
#define START_YEAR 1800
#define END_YEAR 2023
#define NUM_YEARS (END_YEAR - START_YEAR + 1)

// Function to initialize a library structure with default values
void initializeBook(struct Book* book) {

    book->commonAttributes.id = 0;

}

// Function to initialize an EBook structure to default values
void initializeEBook(struct EBook* ebook) {

    ebook->commonAttributes.id = 0;

}

// Function to initialize a DigitalMedia structure to default values
void initializeDigitalMedia(struct DigitalMedia* digitalMedia) {
    // Example: Set default values for digital media attributes
    digitalMedia->id = 0;
    
}

struct Library initializeLibrary() {
    struct Library newLibrary;

    // Step 1: Set counts to 0
    newLibrary.bookCount = 0;
    newLibrary.ebookCount = 0;
    newLibrary.digitalMediaCount = 0;

    // Step 2: Initialize arrays
    for (int i = 0; i < MAX_BOOK_COUNT; ++i) {
        // Initialize book array to default state or empty
        initializeBook(&newLibrary.books[i]);
    }

    for (int i = 0; i < MAX_EBOOK_COUNT; ++i) {
        // Initialize ebook array to default state or empty
        initializeEBook(&newLibrary.ebooks[i]);
    }

    for (int i = 0; i < MAX_DIGITAL_MEDIA_COUNT; ++i) {
        // Initialize digital media array to default state or empty
        initializeDigitalMedia(&newLibrary.digitalMedias[i]);
    }

    // Step 3: Optionally assign default values
    strncpy(newLibrary.libraryName, "My Library", MAX_NAME_LEN - 1);
    newLibrary.libraryID = 1;

    return newLibrary;
}

void loadBooks(struct Library* lib, const char* filename) {  // Function to load books from text file
    // Step 1: Opening the File
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // File opening failed
        perror("Error opening file");
        return;
    }

    // Step 2: Reading from the File
    char line[2048];
    while (fgets(line, sizeof(line), file) != NULL) {   
        // Step 3: Parsing the Line using appropriate format
        struct Book tempBook;
        int result = sscanf(line, "%d;%50[^;];%50[^;];%50[^;];%d;%50[^;];%50[^;];%d;%50[^;];%d;%10[^;];",
            &tempBook.commonAttributes.id,
            tempBook.commonAttributes.title,
            tempBook.commonAttributes.author,
            tempBook.commonAttributes.genre,
            &tempBook.commonAttributes.yearOfPublication,
            tempBook.commonAttributes.publisher,
            tempBook.commonAttributes.isbn,
            &tempBook.numberOfPages,
            tempBook.condition,
            &tempBook.numberOfCopies,
            tempBook.shelfLocation);

        // Step 4: Ensure all fields are read
        if (result == EOF) {
            // Error in reading
            fprintf(stderr, "Error reading from file\n");
            break;
        }

        // Step 5: Adding to the Library after a line is succesfully read
        if (result == 11) {
            // Successfully parsed all fields
            if (lib->bookCount < MAX_BOOK_COUNT) {
                lib->books[lib->bookCount++] = tempBook;
            }
            else {
                // Warning: Too many books if too many books are encountered
                fprintf(stderr, "Warning: Maximum number of books reached\n");
                break;
            }
        }
        else {
            // Error: Line format incorrect
            fprintf(stderr, "Error: Incorrect line format\n");
        }
    }

    // Step 6: Closing the File
    fclose(file);
}

void loadEbooks(struct Library* lib, const char* filename) { // Function to load Ebooks from text file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // File opening failed
        perror("Error opening file");
        return;
    }

    // Step 2: Reading from the File
    char line[2048];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Step 3: Parsing the Line
        struct EBook tempEBook;
        int result = sscanf(line, "%d;%50[^;];%50[^;];%50[^;];%d;%50[^;];%50[^;];%50[^;];%d;%50[^;];%d",
            &tempEBook.commonAttributes.id,
            tempEBook.commonAttributes.title,
            tempEBook.commonAttributes.author,
            tempEBook.commonAttributes.genre,
            &tempEBook.commonAttributes.yearOfPublication,
            tempEBook.commonAttributes.publisher,
            tempEBook.commonAttributes.isbn,
            tempEBook.accessLink,
            &tempEBook.downloadCount);

        // Step 4: Ensure all fields are read
        if (result == EOF) {
            // Error in reading
            fprintf(stderr, "Error reading from file\n");
            break;
        }

        // Step 5: Adding to the Library
        if (result == 9) {
            // Successfully parsed all fields
            if (lib->ebookCount < MAX_EBOOK_COUNT) {
                lib->ebooks[lib->ebookCount++] = tempEBook;
            }
            else {
                // Error: Too many ebooks
                fprintf(stderr, "Error: Maximum number of ebooks reached\n");
                break;
            }
        }
        else {
            // Error: Line format incorrect
            fprintf(stderr, "Error: Incorrect line format\n");
        }
    }

    // Step 6: Closing the File
    fclose(file);
}


void loadDigitalMedia(struct Library* lib, const char* filename) { // Fucntion to load Digital Media for a text file
    // Step 1: Opening the File
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        // File opening failed
        perror("Error opening file");
        return;
    }

    // Step 2: Reading from the File
    char line[2048];
    while (fgets(line, sizeof(line), file) != NULL) {
        // Step 3: Parsing the Line
        struct DigitalMedia tempDigitalMedia;
        int result = sscanf(line, "%d;%50[^;];%50[^;];%50[^;];%d;%50[^;];%f;%50[^;];%d",
            &tempDigitalMedia.id,
            tempDigitalMedia.title,
            tempDigitalMedia.creator,
            tempDigitalMedia.genre,
            &tempDigitalMedia.yearOfRelease,
            tempDigitalMedia.format,
            &tempDigitalMedia.fileSize,
            tempDigitalMedia.accessLink,
            &tempDigitalMedia.downloadCount);

        // Step 4: Ensure all fields are read
        if (result == EOF) {
            // Error in reading
            fprintf(stderr, "Error reading from file\n");
            break;
        }

        // Step 5: Adding to the Library
        if (result == 9) {
            // Successfully parsed all fields
            if (lib->digitalMediaCount < MAX_DIGITAL_MEDIA_COUNT) {
                lib->digitalMedias[lib->digitalMediaCount++] = tempDigitalMedia;
            }
            else {
                // Error: Too many digital media items
                fprintf(stderr, "Error: Maximum number of digital media items reached\n");
                break;
            }
        }
        else {
            // Error: Line format incorrect
            fprintf(stderr, "Error: Incorrect line format\n");
        }
    }

    // Step 6: Closing the File
    fclose(file);
}

void displayBooks(const struct Library* lib) {   // Function for displaying books
    // Step 1: Initialization and Error Checking
    if (lib == NULL || lib->books == NULL || lib->bookCount == 0) {
        // Invalid library or no books to display
        printf("No books to display.\n");
        return;
    }

    // Step 2: Header Printing
    printf("------- BOOKS -------\n");
    printf("%-5s  %-25s  %-17s  %-15s  %-4s  %-25s  %-25s  %-15s\n",
        "ID", "Title", "Author", "Genre", "Year", "Publisher", "ISBN", "Shelf");


    // Step 3: Separator Line
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Step 4: Content Display
    int numBooksToDisplay = lib->bookCount < 10 ? lib->bookCount : 10;

    // Step 5: Loop for Printing Book Details
    for (int i = 0; i < numBooksToDisplay; ++i) {
        // Step 5.1: String Truncation and Null-termination
        char truncatedTitle[MAX_TITLE_LEN + 1];
        strncpy(truncatedTitle, lib->books[i].commonAttributes.title, sizeof(truncatedTitle) - 1);
        truncatedTitle[sizeof(truncatedTitle) - 1] = '\0';

        char truncatedAuthor[MAX_AUTHOR_LEN + 1];
        strncpy(truncatedAuthor, lib->books[i].commonAttributes.author, sizeof(truncatedAuthor) - 1);
        truncatedAuthor[sizeof(truncatedAuthor) - 1] = '\0';

        char truncatedPublisher[MAX_PUBLISHER_LEN + 1];
        strncpy(truncatedPublisher, lib->books[i].commonAttributes.publisher, sizeof(truncatedPublisher) - 1);
        truncatedPublisher[sizeof(truncatedPublisher) - 1] = '\0';

        // Step 5.2: Printing Book Details
        printf("%d  %-25s  %-20s  %-15s  %-4d  %-25s  %-26s  %-5s",
            lib->books[i].commonAttributes.id,
            truncatedTitle,
            truncatedAuthor,
            lib->books[i].commonAttributes.genre,
            lib->books[i].commonAttributes.yearOfPublication,
            truncatedPublisher,
            lib->books[i].commonAttributes.isbn,
            lib->books[i].shelfLocation);
    }
}

void displayEbooks(const struct Library* lib, int flag) {  // Fucntion for displaying E books
    // Step 1: Error Checking
    if (lib == NULL || lib->ebooks == NULL || lib->ebookCount == 0) {
        // Invalid library or no ebooks to display
        printf("No ebooks to display.\n");
        return;
    }

    // Step 2: Determining the Range to Display
    int startIdx, endIdx;
    int numEbooksToDisplay = lib->ebookCount < 5 ? lib->ebookCount : 5;
    const char* displayType;
    if (flag == 0) {
        // Display the first five ebooks
        displayType = "First";
        startIdx = 0;
        endIdx = numEbooksToDisplay;
    }
    else {
        // Display the last five ebooks
        displayType = "Last";
        startIdx = lib->ebookCount - numEbooksToDisplay;
        endIdx = lib->ebookCount;
    }
    //Step 3 : Print Header
    printf("\n------- %s 5 EBOOKS -------\n", displayType);
    // Step 4: Printing the Table Header
    printf("%-5s  %-30s  %-20s  %-15s  %-4s  %-25s  %-14s  %-14s %-9s\n",
        "ID", "Title", "Author", "Genre", "Year", "Publisher", "ISBN", "Access Link", "Downloads");


    // Step 5: Separator Line
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Step 6: Looping Through and Printing Ebooks
    for (int i = startIdx; i < endIdx; ++i) {
        // Step 6.1: String Truncation and Null-termination
        char truncatedTitle[MAX_TITLE_LEN + 1];
        strncpy(truncatedTitle, lib->ebooks[i].commonAttributes.title, sizeof(truncatedTitle) - 1);
        truncatedTitle[sizeof(truncatedTitle) - 1] = '\0';

        char truncatedAuthor[MAX_AUTHOR_LEN + 1];
        strncpy(truncatedAuthor, lib->ebooks[i].commonAttributes.author, sizeof(truncatedAuthor) - 1);
        truncatedAuthor[sizeof(truncatedAuthor) - 1] = '\0';

        char truncatedAccessLink[MAX_LINK_LEN + 1];
        strncpy(truncatedAccessLink, lib->ebooks[i].accessLink, sizeof(truncatedAccessLink) - 1);
        truncatedAccessLink[sizeof(truncatedAccessLink) - 1] = '\0';

        // Step 6.2: Printing Ebook Details
        printf("%-5d  %-30s  %-20s  %-15s  %-4d  %-25s  %-14s  %-14.14s  %-9d\n",
            lib->ebooks[i].commonAttributes.id,
            truncatedTitle,
            truncatedAuthor,
            lib->ebooks[i].commonAttributes.genre,
            lib->ebooks[i].commonAttributes.yearOfPublication,
            lib->ebooks[i].commonAttributes.publisher,
            lib->ebooks[i].commonAttributes.isbn,
            truncatedAccessLink,
            lib->ebooks[i].downloadCount);
    }
}

void displayDigitalMedia(const struct Library* lib, int flag) { // Fucntion for dipslaying Digital Media
    // Step 1: Validate Input
    if (lib == NULL || lib->digitalMedias == NULL || lib->digitalMediaCount == 0) {
        // Invalid library or no digital media items to display
        printf("No digital media items to display.\n");
        return;
    }

    // Step 2: Calculate Range
    int startIdx, endIdx;
    int numDigitalMediaToDisplay = lib->digitalMediaCount < 5 ? lib->digitalMediaCount : 5;
    const char* displayType;

    switch (flag) {
    case 0:
        // Display the first five items
        displayType = "First";
        startIdx = 0;
        endIdx = numDigitalMediaToDisplay;
        break;
    case 1:
        // Display the last five items
        displayType = "Last";
        startIdx = lib->digitalMediaCount - numDigitalMediaToDisplay;
        endIdx = lib->digitalMediaCount;
        break;
    case 2:
        // Display five items from the middle
        displayType = "Middle";
        startIdx = (lib->digitalMediaCount - 1) / 2 - 2;
        endIdx = startIdx + numDigitalMediaToDisplay;
        break;
    default:
        // Display all items if less than five
        displayType = "All";
        startIdx = 0;
        endIdx = lib->digitalMediaCount;
        break;
    }

    // Step 3: Print Header
    printf("\n\n------- %s 5 DIGITAL MEDIA ITEMS -------\n", displayType);

    printf("%-4s %-36s %-20s %-15s %-8s %-10s %-14s %-20s %-9s\n",
        "ID", "Title", "Creator", "Genre", "Year", "Format", "FileSize", " Access Link", "Downloads");

    // Step 4: Print Separator Line
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // Step 5: Iterate and Print Items
    for (int i = startIdx; i < endIdx; ++i) {
        // Step 5.1: String Truncation and Null-termination
        char truncatedTitle[MAX_TITLE_LEN + 1];
        strncpy(truncatedTitle, lib->digitalMedias[i].title, sizeof(truncatedTitle) - 1);
        truncatedTitle[sizeof(truncatedTitle) - 1] = '\0';

        char truncatedCreator[MAX_AUTHOR_LEN + 1];
        strncpy(truncatedCreator, lib->digitalMedias[i].creator, sizeof(truncatedCreator) - 1);
        truncatedCreator[sizeof(truncatedCreator) - 1] = '\0';

        char truncatedAccessLink[MAX_LINK_LEN + 1];
        strncpy(truncatedAccessLink, lib->digitalMedias[i].accessLink, sizeof(truncatedAccessLink) - 1);
        truncatedAccessLink[sizeof(truncatedAccessLink) - 1] = '\0';

        // Step 5.2: Printing Digital Media Details
        printf("%-4d  %-36s  %-17s  %-14s  %-7d  %-9s  %-10.2f  %-26.14s  %-9d\n",
            lib->digitalMedias[i].id,
            truncatedTitle,
            truncatedCreator,
            lib->digitalMedias[i].genre,
            lib->digitalMedias[i].yearOfRelease,
            lib->digitalMedias[i].format,
            lib->digitalMedias[i].fileSize,
            truncatedAccessLink,
            lib->digitalMedias[i].downloadCount);
       
    }
}




void printBookPublicationHistogram(const struct Library* lib) {  //Function to display the Historgram
    // Error checking
    if (lib == NULL || lib->books == NULL) {
        printf("Invalid library or no books available.\n");
        return;
    }

    // Initialize an array to store counts for each year
    int bookYearCounts[NUM_YEARS] = { 0 };

    // Count publications for each year
    for (int i = 0; i < lib->bookCount; ++i) {
        int year = lib->books[i].commonAttributes.yearOfPublication;

        // Check if the year is within the specified range
        if (year >= START_YEAR && year <= END_YEAR) {
            bookYearCounts[year - START_YEAR]++;
        }
    }

    // Print the histogram
    printf("\n\n\n Book Publication Histogram:\n");
    for (int i = 0; i < NUM_YEARS; ++i) {
        if (bookYearCounts[i] > 0) {
            // Print the year
            printf("%d: ", i + START_YEAR);

            // Print asterisks for each book published in that year
            for (int j = 0; j < bookYearCounts[i]; ++j) {
                printf("*");
            }

            // Print the count in parentheses
            printf(" (%d)\n", bookYearCounts[i]);
        }
    }
}
