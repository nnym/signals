#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <string.h>

int ceildiv(int dividend, int divisor) {
	return (dividend + divisor - 1) / divisor;
}

int main() {
	size_t maxLength = 0;
	int maxSignal = 0;

	for (int signal = 1; signal <= 64; signal++) {
		const char *name = sigabbrev_np(signal);

		if (name) {
			maxSignal = signal;
			size_t l = strlen(name);
			if (l > maxLength) maxLength = l;
		}
	}

	int columns = 4;

	for (int signal = 1; signal <= ceildiv(maxSignal, columns); signal++) {
		for (int column = 0; column < columns; column++) {
			int s = signal + ceildiv(maxSignal * column, columns);
			const char *name = sigabbrev_np(s);

			if (name) {
				printf("%2d %s ", s, name);
				for (int i = strlen(name); i < maxLength; i++) printf(" ");
			}
		}

		puts("");
	}
}
