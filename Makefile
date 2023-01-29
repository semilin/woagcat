CC= gcc
RM= rm -vf
CFLAGS= -std=c17 -Wall -Wextra -Wpedantic -Werror -Og -g
CLINKS= -lm
TESTLINKS= -lcheck -lsubunit -lrt -lpthread
SRCMAIN= src/main.c
SRCFILES= src/corpus.c src/layout.c src/metrics.c src/analysis.c
TESTFILES= tests/check_woagcat.c

.PHONY: all check clean

all: $(SRCMAIN) $(SRCFILES)
	cc $(CFLAGS) $(SRCMAIN) $(SRCFILES) -o woagcat $(CLINKS)

check: $(SRCFILES) $(TESTFILES)
	cc $(CFLAGS) $(SRCFILES) $(TESTFILES) -o check $(CLINKS) $(TESTLINKS)
	./check
clean:
	$(RM) -v woagcat check
