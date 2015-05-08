ALL = pi_serial pi_para1 pi_para2 pi_para3

CC = gcc
CFLAGS = -fopenmp

default: $(ALL)

$(ALL): %: %.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(ALL)
