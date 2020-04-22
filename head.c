#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];

void
head(int fd, char *name) {
    int i, n;
    int l, c;

    l = c = 0;

  while ((n = read(fd, buf, sizeof(buf))) > 0) {
    for (i=0; i<=n; i++) {				
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
    printf(1, "Error with reading in head.c\n");
    exit();
  }
}



int 
main(int argc, char *argv[]) {
      int i;
      int fd = 0;
      char *file = "";
      char a;

      if (argc <= 1) {	
            head(0, "");
            exit();
      } else {
      for (i = 1; i < argc; i++) {
		    a = *argv[i];
		    
		    if (a == '-') {
		      argv[i]++;
		    } else {
		    
			  if ((fd = open(argv[i], 0)) < 0) {
          printf(1, "Cannot open %s\n", argv[i]);
          exit();
        }
		 }
		 }
        head(fd, file);
        close(fd);
        exit();
      }
}
