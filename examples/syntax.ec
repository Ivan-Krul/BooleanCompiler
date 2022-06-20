vcc -> true; /* power */

button but[vcc]|Q|; /* initialization of button and needly key on keyboard */
switch swc[vcc]|W|; /* initialization of switch */

/*init [name] coment and always new variable will be with false signal */
init a = vcc; /* initialization in var a and ; at the end */
init b = but;

a = a or b; /* assign a and operator "or" */
init c = a and b; /* initialization c and operator "and" */

init d = not (c or swc); /* operator not and round scopes */

led ld[d]|0|; /* initialization of a led diode on the screen and the address */

gnd <- d; /* for making electric circle need ground */