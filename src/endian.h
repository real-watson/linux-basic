#ifndef _APP_ENDIAN_TYPE_

typedef unsigned int uint32;
/*0x12345678 -> 0x78563412 as well as LE_TO_BE(le)*/
#define BE_TO_LE(be) ( \
					 (((uint32)(be) & 0xff000000) >> 24) |\
					 (((uint32)(be) & 0x00ff0000) >> 8)  |\
					 (((uint32)(be) & 0x0000ff00) << 8)  |\
					 (((uint32)(be) & 0x000000ff) << 24)  \
					 )
/*0x12345678 -> 0x5678 1234 reverse*/
#define BASE_BE_TO_LE(be) ( \
					(((uint32)(be) & 0xffff0000) >> 16) |\
					(((uint32)(be) & 0x0000ffff) << 16) \
					) 

extern int query_endian_mode(int check);

#define _APP_ENDIAN_TYPE_
#endif
