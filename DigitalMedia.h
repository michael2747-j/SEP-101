
#include "LibraryConfig.h"


struct DigitalMedia {


	int id;
	char title[MAX_TITLE_LEN];
	char creator[MAX_AUTHOR_LEN];
	char genre[MAX_GENRE_LEN];
	int yearOfRelease;
	char format[MAX_FORMAT_LEN];
	float fileSize;
	char accessLink[MAX_LINK_LEN];
	int downloadCount ;


};
