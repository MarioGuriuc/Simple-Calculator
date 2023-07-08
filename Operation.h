#pragma once
#include "Calculator.h"

class Operation {
public:
	virtual void Compute(double& a, double b) = 0;
};

class Addition : public Operation {
public:
	void Compute(double& a, double b) {
		a += b;
	}
};

class Subtraction : public Operation {
public:
	void Compute(double& a, double b) {
		a -= b;
	}
};

class Multiplication : public Operation {
public:
	void Compute(double& a, double b) {
		a *= b;
	}
};

class Division : public Operation {
public:
	void Compute(double& a, double b) {
		a /= b;
	}
};

class Power : public Operation {
public:
	void Compute(double& a, double b) {
		a = pow(a, b);
	}
};

class Mod : public Operation {
public:
	void Compute(double& a, double b) {
		a = fmod(a, b);
	}
};