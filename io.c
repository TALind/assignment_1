
#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int
read_char() {
  char c;
  int bytes =read(STDIN_FILENO,&c,1);
  if(bytes==1) return c;
  return EOF;
}


/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_char(char c) {

  return write(STDOUT_FILENO,&c,1)==1?0: EOF;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int
write_string(char* s) {
  int len =0;
  while (s[len]!='\0') len++;
  return write(STDOUT_FILENO, s,len)==len?0: EOF;
}

/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int
write_int(int n) {
  char buf[12];
  int i=0;
  if(n==0){
    return write_char('0');
  }
  if(n<0){
    write_char('-');
    n=-n;
  }
  // convert int to string
  while(n>0){
    buf[i++]=(n%10)+'0';
    n/=10;
  }
  for(int j=i-1; j>=0; j--){
    write_char(buf[j]);
  }
  return 0;
}

