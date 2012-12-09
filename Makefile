CC = g++
CFLAGS = `pkg-config --cflags gtkmm-3.0` `GraphicsMagick++-config --cppflags` `curl-config --libs` -std=c++0x
EXEC_NAME = test
INCLUDES = 
LIBS = `pkg-config --libs gtkmm-3.0` `GraphicsMagick++-config --libs` `curl-config --libs`
OBJ_FILES = main.o fenetreprincipale.o messageslist.o messagetext.o panneau.o panneaubiblio.o panneauimage.o panneauinfo.o panneaurequete.o panneautexte.o preference.o requeteweb.o searchhistory.o workfile.o getnumfromstring.o topmenu.o
INSTALL_DIR = /usr/local/bin

all : $(EXEC_NAME)
	
clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)
