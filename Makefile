CC = gcc
LIBS= -lblas -lhdf5 -lm  
CFLAGS = -Wall -Ofast -fopenmp -Wno-unused-function  -march=native -ffast-math -std=gnu99 -DUSE_SSE2
OBJDIR = obj

OBJECTS = read_events.o features.o util.o layers.o decode.o

all: basecall

%.o: %.c
	$(CC) $(INC) -c -o $@ $< $(CFLAGS)

basecall: basecall.o $(OBJECTS) lstm_model.h
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f *.o basecall_gru basecall_lstm
