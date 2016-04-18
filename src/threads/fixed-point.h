//Zack Foreman
//Created: 03/28/2016 Modified: 03/28/2016
//Fixed-point.h

static const int f = (1 << 14);

int ConvFP(int);
int FPtoIntZ(int);
int FPtoIntN(int);
int AddFP(int, int);
int SubFP(int, int);
int AddFPtoInt(int, int);
int SubFPtoInt(int, int);
int MultFP(int, int);
int MultFPtoInt(int, int);
int DivFP(int, int);
int DivFPtoInt(int, int);

int ConvFP(int n) {

	return n * f;

}

int FPtoIntZ(int x) {

	return x / f;

}

int FPtoIntN(int x) {

	return (x >= 0) ? ((x + (f/2)) / f) : ((x - (f/2)) / f);

}

int AddFP(int x, int y) {

	return x + y;

}

int SubFP(int x, int y) {

	return x - y;

}

int AddFPtoInt(int x, int n) {

	return x + ConvFP(n);

}

int SubFPtoInt(int x, int n) {

	return x - ConvFP(n);

}

int MultFP(int x, int y) {

	return (((int64_t) x) * y) / f;

}

int MultFPtoInt(int x, int n) {

	return (x * n);

}

int DivFP(int x, int y) {

	return (((int64_t) x) * f) / y;

}

int DivFPtoInt(int x, int n) {

	return (x / n);

}
