/*
	png 1.2 vs 1.4
	In future we need to upgrade all platforms to use png 1.4.
	// VVD
*/
 
#if defined __FreeBSD__ || defined __APPLE__
#include "png14.h"
#define __Q_PNG14__
#else
#include "png12.h"
#define __Q_PNG12__
#endif
