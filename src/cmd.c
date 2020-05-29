#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void running_command(const char *cmd)
{
	FILE *fp = NULL;
	char rdbuff[1024] = "";
	char log[1024] = "";

	if ((fp = popen(cmd,"r")) == NULL){
		perror("Error in popen");
		return;
	}
	/*读取数据*/	
	while((fgets(rdbuff,1024,fp)) != NULL){
	}

	pclose(fp);
}

