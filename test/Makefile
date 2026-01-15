#------------------------------------------------------------
# Makefile for Scheduler Unit Tests
# FCFS, RR and SJF
#------------------------------------------------------------

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -std=c99 -pedantic -DUNIT_TEST
LDFLAGS :=

#------------------------------------------------------------
# Directories
#------------------------------------------------------------

SRC_DIR := ../src/schdl
OUT_DIR := out
BIN_DIR := bin

#------------------------------------------------------------
# Common object
#------------------------------------------------------------

COMMON_OBJS := $(OUT_DIR)/process.o

#------------------------------------------------------------
# Object groups per scheduler
#------------------------------------------------------------

FCFS_OBJS := $(COMMON_OBJS) $(OUT_DIR)/fcfs.o $(OUT_DIR)/test_fcfs.o
RR_OBJS   := $(COMMON_OBJS) $(OUT_DIR)/rr.o   $(OUT_DIR)/test_rr.o
SJF_OBJS  := $(COMMON_OBJS) $(OUT_DIR)/sjf.o  $(OUT_DIR)/test_sjf.o

#------------------------------------------------------------
# Public targets (avoid implicit-rule collisions)
#------------------------------------------------------------

.PHONY: all fcfs rr sjf run run_fcfs run_rr run_sjf clean

all: fcfs rr sjf

fcfs: $(BIN_DIR)/test_fcfs
rr:   $(BIN_DIR)/test_rr
sjf:  $(BIN_DIR)/test_sjf

#------------------------------------------------------------
# Link rules
#------------------------------------------------------------

$(BIN_DIR)/test_fcfs: $(FCFS_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/test_rr: $(RR_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BIN_DIR)/test_sjf: $(SJF_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

#------------------------------------------------------------
# Compile rules
#------------------------------------------------------------

$(OUT_DIR)/process.o: $(SRC_DIR)/process.c $(SRC_DIR)/process.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/fcfs.o: $(SRC_DIR)/fcfs.c $(SRC_DIR)/process.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/rr.o: $(SRC_DIR)/rr.c $(SRC_DIR)/process.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/sjf.o: $(SRC_DIR)/sjf.c $(SRC_DIR)/process.h | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/test_fcfs.o: test_fcfs.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/test_rr.o: test_rr.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/test_sjf.o: test_sjf.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#------------------------------------------------------------
# Directory creation
#------------------------------------------------------------

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

#------------------------------------------------------------
# Run helpers
#------------------------------------------------------------

run: run_fcfs run_rr run_sjf

run_fcfs:
	./$(BIN_DIR)/test_fcfs

run_rr:
	./$(BIN_DIR)/test_rr

run_sjf:
	./$(BIN_DIR)/test_sjf

#------------------------------------------------------------
# Clean
#------------------------------------------------------------

clean:
	rm -rf $(OUT_DIR) $(BIN_DIR)
