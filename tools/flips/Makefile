FLIPS_VERSION ?= v198
FLIPS_REPO ?= https://github.com/Alcaro/Flips.git
BUILD_DIR ?= build
BIN := flips

.PHONY: all clean

all: $(BIN)

$(BIN):
	git clone --depth 1 --branch $(FLIPS_VERSION) $(FLIPS_REPO) $(BUILD_DIR)
	$(MAKE) -C $(BUILD_DIR) TARGET=cli
	cp $(BUILD_DIR)/flips $@

clean:
	rm -rf $(BUILD_DIR) $(BIN)
