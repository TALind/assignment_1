
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char(void) {
  char c;
  ssize_t result = read(STDIN_FILENO, &c, 1);

  if (result == 1 ) {
    return (unsigned char)c;
  } else if (result == 0) {
    return EOF; /* End of file */
  } else {
    return EOF;
  }

}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {
  ssize_t result = write(STDOUT_FILENO, &c, 1);

  if (result == 1) {
    return 0;
  } else {
    return EOF;
  }

}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {

  if (s == NULL) {
    return EOF;
  }

  size_t len = 0;
  while (s[len] != '\0') {
    len++;
  }

  ssize_t result = write(STDOUT_FILENO, s, len);

  if (result == (ssize_t)len) {
    return 0;
  } else {
    return EOF;
  }
}

/* Writes n to stdout (without any formatting).
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
	long m = n;
	if (m < 0) {
    	if (write_char('-') == EOF) {
        	return EOF;
    	}
    	m = -m;
	}
	if (m == 0) return write_char('0');


    /* Determine the number of digits in m */
	unsigned long div = 1;
	while ((unsigned long)(m / div) >= 10) {
    	div *= 10;
    }

    /* Write each digit */
	while (div > 0) {
	char ch = (char) ('0' + (m / div) % 10);
    	if (write_char(ch) == EOF) return EOF;
	    m %= div;
		div /= 10;
	}
    return 0;
}
