#include "shell.h"
/**
 * main - simple shell program
 * Return: 0 always success
 */
int main(void)
{
//	unsigned int pid, ppid;
	ssize_t read = 0;
	char *buff = NULL, *str = NULL, **arr;
	size_t size = 0;
	int /*status, */ex, tok_size = 0/*, result = 0*/;
	pid_t c_pid = 0;

//	pid = get_pid();
//	ppid = get_ppid();
	//printf("pid = %u\nppid = %u\n", pid, ppid);
	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		read = getline(&buff, &size, stdin);
		if (read == -1)
		{
			free(buff);
			return (-1);
		}
	//	printf("read = %li\n", read);
		if (buff && buff[0] != '\n')
		{
			str = stringdup(buff);
	//		printf("str = %s\n", str);
			tok_size = toksize(buff);
	//		printf("tok_size = %d\n", tok_size);
			if (tok_size == -1)
				break;
			arr = malloc(sizeof(char*) * (tok_size + 1));
			if (!arr)
				return (-1);
			arr[tok_size] = NULL;

			arr = tokanize(str, arr);
	//		printf("arr = %s\n", *arr);

			ex = exit_shell(arr, tok_size);

			if (ex == 0)
				exit(0);

			/*result = */
			few(c_pid, arr);
		}
		free(arr);
		free(str);
	}
	return (0);
}
