#include "header.h"

int main(int ac, char *av[])
{
  /* Open the file for reading */
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	unsigned int line_count = 0;
	FILE *fp = fopen(av[1], "r");
	char *tok1;
	char *tok2;

	if (!fp || ac != 2)
	{
		fprintf(stderr, "Error opening file '%s'\n", av[1]);
		return (EXIT_FAILURE);
	}
	stack_t *stack = NULL;
	while (getline(&line_buf, &line_buf_size, fp) != EOF)
	{
		line_count++;
		tok1 = strtok(line_buf, " \t\r\n\a");
		tok2 = strtok(NULL, " \t\r\n\a");
		printf("token1 :%s  token2:%s\n", tok1, tok2);
		check_token(tok1, tok2, &stack);
	}
	printf("\n\n");
  /* Free the allocated line buffer */
	free(line_buf);
	line_buf = NULL;

  /* Close the file now that we are done with it */
	fclose(fp);

  return (EXIT_SUCCESS);
}
