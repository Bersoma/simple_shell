#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buf[10];
	FILE *file = fopen("/proc/sys/kernel/pid_max", "r");

	fread(buf, 1, 10, file);

	printf("%s", buf);

	fclose(file);
	return (0);
}
