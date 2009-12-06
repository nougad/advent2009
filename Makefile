####### Compile Flags
CC=       gcc
CFLAGS=   -Wall -Os -std=c99
CLIBS=
CINCL=
####### Commands
RM=       rm -r
MKDIR=    mkdir -p
####### Directories
SRCDIR=   src
OUTDIR=   bin
OBJDIR=   $(OUTDIR)/objects
####### Project
OBJEND=   o
SRCEND=   c
NAME=     game

EXE  = $(OUTDIR)/$(NAME)
SRCS = $(shell ls -1 $(SRCDIR)/*.$(SRCEND))
BINS = $(SRCS:$(SRCDIR)%.$(SRCEND)=$(OBJDIR)%.$(OBJEND))

all: compile

compile: $(BINS) $(EXE)

$(EXE): $(BINS)
	$(CC) $(CINCL) -o $(OUTDIR)/$(NAME) -export-dynamic $(BINS) $(CLIBS) $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEND) 
	$(MKDIR) $(OBJDIR)
	$(CC) $(CINCL) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OUTDIR) || true

run: $(OUTDIR)/$(NAME)
	./$(OUTDIR)/$(NAME)

.PHONY: clean
.SILENT: run
