#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 32

typedef struct	s_list
{
	int fd;
	char *line_buf;
	size_t len;
	size_t linepos;
	int ret;	
}		t_line;

#endif
