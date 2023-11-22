///////////////////////////////////////////////////////////////////////////
// File Name: Libarary Management System
// Group Number:  4
// Group Members Names : MICHAEL MELLES (111838223),
// Group Members Seneca Email : mmellese@myseneca.ca, ssnijjer@myseneca.ca, zahmed79@myseneca.ca, ayush1@myseneca.ca
// Date : 21/11 2023
// Authenticity Declaration :
// We declare this submission is the result of our group work and has not been
// shared with any other groups/students or 3rd party content provider.This submitted
// piece of work is entirely of my own creation.
//////////////////////////////


#define BOOK_H
#include "LibraryConfig.h"


struct CommonBookAttributes {  //Embedded structure of CommonBookAttributes. 
	                           //Embedding the common attributes ensures we have all the generic book details available within this structure.

	int id;
	char title[MAX_TITLE_LEN];
	char author[MAX_AUTHOR_LEN];
	char genre[MAX_GENRE_LEN];
	int yearOfPublication;
	char publisher[MAX_PUBLISHER_LEN];
	char isbn[MAX_ISBN_LEN];

};




struct Book {  //To represent physical books, which include all common attributes plus specific ones related to their physical nature.

	struct CommonBookAttributes commonAttributes;

	int numberOfPages;
	char condition[MAX_CONDITION_LEN];
	int numberOfCopies;
	char shelfLocation[MAX_SHELF_LOCATION_LEN];


};

struct EBook {  //To represent eBooks, which do not have a physical presence but have digital access details.

	struct CommonBookAttributes commonAttributes;
	char accessLink[MAX_LINK_LEN];
	int downloadCount;

};

void initializeBook(struct Book* book);
