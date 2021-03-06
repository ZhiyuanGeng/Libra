#include <cstdio>
#include "linear_gkr/prime_field.h"
#include "traditional_gkr/verifier_traditional.h"
#include "traditional_gkr/prover_clogc.h"


verifier v;
prover p;

int main(int argc, char** argv)
{
	prime_field::init("16798108731015832284940804142231733909759579603404752749028378864165570215949", 10);
	p.total_time = 0;
	v.get_prover(&p);
	v.read_circuit("test_circuit.txt");
	p.get_circuit(v.C);
	bool result = v.verify();
	printf("%s\n", result ? "Pass" : "Fail");
	return 0;
}
