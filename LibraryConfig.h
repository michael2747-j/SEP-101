
// LibraryConfig.h

#ifndef LIBRARY_CONFIG_H
#define LIBRARY_CONFIG_H


// Assuming a reasonable upper limit for our inventory size
#define MAX_BOOK_COUNT 100
#define MAX_EBOOK_COUNT 100
#define MAX_DIGITAL_MEDIA_COUNT 100

// Max lengths for various string attributes

// Define the maximum length for the name of a library.
#define MAX_NAME_LEN 128

// Define the maximum length for the title of a book or digital media.
#define MAX_TITLE_LEN 128

// Define the maximum length for the author's name of a book.
#define MAX_AUTHOR_LEN 128

// Define the maximum length for the genre of a book or digital media.
#define MAX_GENRE_LEN 128

// Define the maximum length for the publisher's name of a book.
#define MAX_PUBLISHER_LEN 128

// Define the maximum length for the ISBN number of a book.
#define MAX_ISBN_LEN 128

// Define the maximum length for the condition description of a physical book.
#define MAX_CONDITION_LEN 128

// Define the maximum length for the access link of an eBook or digital media.
#define MAX_LINK_LEN 128

// Define the maximum length for the format of digital content (e.g., MP4, MP3).
#define MAX_FORMAT_LEN 128

#define MAX_SHELF_LOCATION_LEN 10



// Additional constants and configurations can be added here as the system grows


#endif // LIBRARY_CONFIG_H