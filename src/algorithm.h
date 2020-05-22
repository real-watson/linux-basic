#ifndef _APP_SELF_ALHM_

/*定义一个宏定义交换数据*/
#define SWAP_NUMBER(x,y) \
		do{ \
			int t; \
			t = *x; \
			*x = *y; \
			*y = t; \
		}while(0);


#define _APP_SELF_ALHM_
#endif
