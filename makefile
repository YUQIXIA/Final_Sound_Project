OBJ=sound.o main.o screen.o
APPNAME=sound.a
TAR = final.tar
$(APPNAME):$(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm
%.O:%.C
	gcc -c -o $@ $<
#main.o:main.c
#	gcc -c main.c
#foo.o:foo.c
#	gcc -c foo.c
clean:
	rm $(OBJ) $(APPNAME)
archive:
	tar cf $(TAR) *
 
	
