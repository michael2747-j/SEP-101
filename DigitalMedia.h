#include "LibraryConfig.h" // Including "LibraryConfing" header file for the constants


struct DigitalMedia {  //To represent digital media items like videos, audio files, etc.,


	int id;
	char title[MAX_TITLE_LEN];
	char creator[MAX_AUTHOR_LEN];
	char genre[MAX_GENRE_LEN];            // Attributes of Digital Media
	int yearOfRelease;
	char format[MAX_FORMAT_LEN];
	float fileSize;
	char accessLink[MAX_LINK_LEN];
	int downloadCount;


};
