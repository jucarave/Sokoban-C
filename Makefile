CC = gcc
CFLAGS = -std=c99

files := $(wildcard src/*.c)
outputDir := "Build/"

warehouse: $(files) makeOutputDir clean
	$(CC) $(CFLAGS) $(files) -o $(outputDir)warehouse

debug: $(files) makeOutputDir clean
	$(CC) $(CFLAGS) -g $(files) -o $(outputDir)warehouse

makeOutputDir:
	mkdir -p $(outputDir)

clean:
	rm -f $(outputDir)warehouse