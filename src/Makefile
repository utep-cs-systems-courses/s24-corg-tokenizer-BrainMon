OBJS = history.o tokenizer.o uimain.o

CFLAGS=-g -O3

all: tokens

tokens: $(OBJS)
	cc -o tokens $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h

clean:
	rm -f *.o tokens

run: tokens
	./tokens
