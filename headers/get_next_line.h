#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>

# define ENDL '\n'
# define BUFF_SIZE 1

char	*read_tmp();

#endif
