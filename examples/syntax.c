
function main() { //main function
//bool [name]; // coment and always new variable will be with false signal
	init a = true; // initialization in var a and ; at the end
	init b;

	init a = a or b; // assign a and operator "or"
	init c = a and b; // initialization c and operator "and"

	init d = not c; // operator not

	// | - or, & - and, ! - not

	in > c; // operator of inject > and input
	out < a < b; // second operator of inject < and output

	end; // finish function
}
