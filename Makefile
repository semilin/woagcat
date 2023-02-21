CC= gcc
RM= rm -vf
CFLAGS= -std=c17 -Wall -Wextra -Wpedantic -Werror -Og -g -gdwarf-4
CLINKS= -lm -lreadline
TESTLINKS= -lcheck -lrt -lpthread
SRCMAIN= src/cli/main.c src/cli/command.c src/cli/commands.c src/cli/analysis.c src/cli/output.c
SRCFILES= src/corpus.c src/layout.c src/metrics.c src/analysis.c
TESTFILES= tests/check_woagcat.c

.PHONY: all check clean

all: $(SRCMAIN) $(SRCFILES)
	$(CC) $(CFLAGS) $(SRCMAIN) $(SRCFILES) -o woagcat $(CLINKS)

check: $(SRCFILES) $(TESTFILES)
	$(CC) $(CFLAGS) $(TESTFILES) $(SRCFILES) -o check $(CLINKS) $(TESTLINKS)
	./check
clean:
	$(RM) -v woagcat check
