CC = gcc
SOURCES = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SOURCES))
TARGETS = $(patsubst %.c, %, $(SOURCES))

all: $(OBJS) $(TARGETS) clean
$(OBJS):%.o:%.c
	$(CC) -c $< -o $@

$(TARGETS):%:$(OBJS)
	$(CC) $< -o $@

clean:
	@echo "auto cleaning..."
	rm -rf *.o

.PHONY: cleanO cleanA
cleanO:
	@echo "cleaning..."
	rm -rf *.o
cleanA:
	@echo "cleaning all..."
	rm -rf *.o $(TARGETS)
