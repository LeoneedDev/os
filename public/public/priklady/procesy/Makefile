SOURCES = $(wildcard [1-9].c)
BINS = $(patsubst %.c, %.exe, $(SOURCES)) 

%.exe : %.c os_base.c os_base.h
	@echo "building $@"
	@gcc os_base.c $< -lpthread -o $@

.PHONY: all
all : $(BINS)
	@

.PHONY: clean
clean:
	@rm *.exe
