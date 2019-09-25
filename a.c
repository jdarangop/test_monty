#include "header.h"

int main(int ac, char *av[])
{
  /* Open the file for reading */
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	unsigned int line_count = 0;
	ssize_t line_size;
	FILE *fp = fopen(av[1], "r");
	char *tok1;
	char *tok2;

	if (!fp)
	{
		fprintf(stderr, "Error opening file '%s'\n", av[1]);
		return EXIT_FAILURE;
	}

	while (getline(&line_buf, &line_buf_size, fp) != EOF)
	{
		line_count++;
		printf("contents: %s", line_buf);
		tok1 = strtok(line_buf, " \t\r\n\a");
		tok2 = strtok(NULL, " \t\r\n\a");
		printf("token1 :%s  token2:%s\n", tok1, tok2);
	}
	printf("\n\n");
	check_token(tok1);
  /* Free the allocated line buffer */
	free(line_buf);
	line_buf = NULL;

  /* Close the file now that we are done with it */
	fclose(fp);

  return EXIT_SUCCESS;
}
