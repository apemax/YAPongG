SRC_DIR = src
ODIR = obj
IDIR = include
BUILD_DIR = build

BIN = yapongg

CC = g++
CXXFLAGS = -I$(IDIR) -Werror -Wall -Wextra
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

_DEPS = main.h aibat.h playerbat.h ball.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o aibat.o load_assets.o playerbat.o ball.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.SECONDEXPANSION:

$(ODIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS) | $$(@D)
	$(CC) -c -o $@ $< $(CXXFLAGS) $(LDFLAGS)

$(BUILD_DIR)/$(BIN): $(OBJ) | $$(@D)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

$(BUILD_DIR):
	mkdir -p $@

$(ODIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BUILD_DIR)/$(BIN)
