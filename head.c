#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
head(int fd, char *name) {
    int i, n;
    int l, c;

    l = c = 0;

  while ((n = read(fd, buf, sizeof(buf))) > 0 ) {
    for (i=0;i<=n ;i++) {				
      if (buf[i]!='\n') {			
      	printf(1,"%c",buf[i]);
      }	else if (l == 9) {
	      printf(1,"\n");	
	      exit();
      } else {
      	printf(1,"\n");
      	l++;
      } 
    }
  }

  if(n < 0) {
    printf(1, "head: read error\n");
    exit();
  }
}



int 
main(int argc, char *argv[]) {
      int i;
      int fd = 0;
      char *file;
      char a;

      file = "";

      if (argc <= 1) {	
            head(0, "");
            exit();
      } else {
		    file = *argv[1];
		    
			  if ((fd = open(file, 0)) < 0) {
          printf(1, "head: cannot open %s\n", file);
          exit();
        }
		 
        head(fd, file);
        close(fd);
        exit();
      }
}
