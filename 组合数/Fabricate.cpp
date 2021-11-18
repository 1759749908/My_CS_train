#include "declare.h"

int Fabricate(int m, int n) {
	return Multi(m, n) / Multi(m - n, 1);
}