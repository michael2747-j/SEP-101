
#define BOOK_H
#include "LibraryConfig.h"


struct CommonBookAttributes {


	int id;
	char title[MAX_TITLE_LEN];
	char author[MAX_AUTHOR_LEN];
	char genre[MAX_GENRE_LEN];
	int yearOfPublication;
	char publisher[MAX_PUBLISHER_LEN];
	char isbn[MAX_ISBN_LEN];

};




struct Book {

	struct CommonBookAttributes commonAttributes;

	int numberOfPages;
	char condition[MAX_CONDITION_LEN];
	int numberOfCopies;
	char shelfLocation[MAX_SHELF_LOCATION_LEN];


};

struct EBook {

	struct CommonBookAttributes commonAttributes;
	char accessLink[MAX_LINK_LEN];
	int downloadCount;

};

void initializeBook(struct Book* book);





