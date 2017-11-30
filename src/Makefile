CC=clang
CFLAGS= -lstdc++ -std=c++14
TARGET=build

all: $(TARGET)

debug: CFLAGS+= -g -fsanitize=memory
debug: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) *.cpp -o $(TARGET)

clean:
	$(RM) $(TARGET)
