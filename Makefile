####### Compile Flags
# Compiler
CC=       gcc
# Compiler flags
CFLAGS=   -Wall -Os -std=c99
# Libraries
CLIBS=
# Includes
CINCL=
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
all: compile

# compile depends on object files and executable
compile: $(BINS) $(EXE)

# executable depends  on all object files
$(EXE): $(BINS)
	$(CC) $(CINCL) -o $(OUTDIR)/$(NAME) -export-dynamic $(BINS) $(CLIBS) $(CFLAGS)

# each file in OBJDIR/*.o depends on corresponding source file in SRCDIR
$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEND)
	$(MKDIR) $(OBJDIR) # create object-folder
	# $@ = name of target (*.o)
	# $< = first dependency (*.c)
	$(CC) $(CINCL) -c $< -o $@ $(CFLAGS)

# delete OUTDIR
clean:
	# don't raise an error if directory not exists
	$(RM) $(OUTDIR) || true

# start programm
run: $(OUTDIR)/$(NAME)
	./$(OUTDIR)/$(NAME)

# execute clean every time
.PHONY: clean
# don't show command in run target
.SILENT: run

