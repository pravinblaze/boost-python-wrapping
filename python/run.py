
from pylib import apply, add_operation, float_vec

param_list = [1.0, 1.0]
param_vec = float_vec()
param_vec.extend(param_list)

op = add_operation(param_vec)
print "OP(1, 1) : " + str(op.add(1, 1))

input_list = [1, 1, 1, 1]
input_vec = float_vec()
input_vec.extend(input_list)

ap = apply(input_vec, op)
print "OP applied on [1, 1, 1, 1] : "
print list(ap.get_result())
