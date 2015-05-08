ALL = pi_serial pi_para1

CC = gcc
CFLAGS = -fopenmp

default: $(ALL)

$(ALL): %: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(ALL)
