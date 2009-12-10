####### Compile Flags
# Compiler
CC=       gcc
# Compiler flags
CFLAGS=   -Wall -std=c99 -ggdb
# Libraries
CLIBS=    `sdl-config --cflags` -lSDL -lGL
####### Commands
RM=       rm -r
MKDIR=    mkdir -p
####### Directories
SRCDIR=   src
OUTDIR=   bin
OBJDIR=   $(OUTDIR)/objects
####### Project
# file extension for object and source files
OBJEND=   o
SRCEND=   c
# name of programm (and executable)
NAME=     game

# path to executable
EXE  = $(OUTDIR)/$(NAME)
# execute shell command "ls -1 src/*.c" for a listing of all source files
SRCS = $(shell ls -1 $(SRCDIR)/*.$(SRCEND))
# substitude /$(SRCDIR)(.*)$(SRCEND)/$(OBJDIR)\1$(OBJEND)/
BINS = $(SRCS:$(SRCDIR)%.$(SRCEND)=$(OBJDIR)%.$(OBJEND))

# default task depends on compile
all: init compile

# create object-folder
init:
	$(MKDIR) $(OBJDIR)

# compile depends on object files and executable
compile: $(BINS) $(EXE)

# executable depends  on all object files
$(EXE): $(BINS)
	$(CC) -o $(OUTDIR)/$(NAME) -export-dynamic $(BINS) $(CLIBS) $(CFLAGS)

# each file in OBJDIR/*.o depends on corresponding source file in SRCDIR
# $@ = name of target (*.o)
# $< = first dependency (*.c)
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEND)
	$(CC) -c $< -o $@ $(CLIBS) $(CFLAGS)

# delete OUTDIR
# don't raise an error if directory not exists
clean:
	$(RM) $(OUTDIR) || true

# start programm
run: $(OUTDIR)/$(NAME)
	./$(OUTDIR)/$(NAME)

# execute clean every time
.PHONY: clean
# don't show command in run target
.SILENT: run

