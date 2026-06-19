# Tell the Signaloid Cloud Developer Platform which source file to compile.
SOURCES = \
	cover_letter.c

# Build with debug symbols and no optimization. The platform's
# "Discover Variables" identifies each variable by its declaration's
# file and line number, which only exist in the debug info — and -O0
# keeps the locals from being optimized away before it can find them.
CFLAGS = -g -O0
