OBJ = sound.o main.o screen.o comm.o
APPNAME = sound.a
TAR = final.tar
$(APPNAME):$(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm -lcurl
	
%.o:%.c
	gcc -c -o $@ $<

#main.o:main.c
#	gcc -c main.c
clean:
	rm $(OBJ) $(APPNAME)
archive:
	tar cf $(TAR) *
 
	
