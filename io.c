
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
  char buffer[12];
  int is_negative = 0;
  int i = 0;

  long m = n;
  if (m < 0) {
    is_negative = 1;
    m = -m;
  }


  if (m == 0) {
    buffer[i++] = '0';
  } else {
    while (m > 0) {
      buffer[i++] = (m % 10) + '0';
      m /= 10;
    }
  }

  if (is_negative) {
    buffer[i++] = '-';
  }

  for (int j = 0; j < i / 2; j++) {
    char temp = buffer[j];
    buffer[j] = buffer[i - j - 1];
    buffer[i - j - 1] = temp;
  }

  buffer[i] = '\0';

  ssize_t result = write(STDOUT_FILENO, buffer, i);

  if (result == (ssize_t)i) {
    return 0;
  }
  return EOF;
}
