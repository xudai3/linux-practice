all: cp1 who1 who2

clean:
	rm -f cp1 who1 who2

cp1:cp1.c
	cc -o cp1 cp1.c

who1:who1.c
	cc -o who1 who1.c

who2:who2.c utmplib.c
	cc -o who2 who2.c utmplib.c
