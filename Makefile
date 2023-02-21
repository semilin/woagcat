CC= gcc
RM= rm -vf
CFLAGS= -Wall -Wextra -Wpedantic -Werror -Og -g
CLINKS= -lm -lreadline
TESTLINKS= -lcheck -lrt -lpthread
SRCMAIN= src/cli/main.c src/cli/command.c src/cli/commands.c src/cli/analysis.c src/cli/output.c src/cli/config.c
SRCFILES= src/corpus.c src/layout.c src/metrics.c src/analysis.c
INIH= ./inih/ini.c
TESTFILES= tests/check_woagcat.c

.PHONY: all check clean

all: $(SRCMAIN) $(SRCFILES)
	$(CC) $(CFLAGS) $(SRCMAIN) $(SRCFILES) $(INIH) -o woagcat $(CLINKS)

check: $(SRCFILES) $(TESTFILES)
	$(CC) $(CFLAGS) $(TESTFILES) $(SRCFILES) -o check $(CLINKS) $(TESTLINKS)
	./check
clean:
	$(RM) -v woagcat check
