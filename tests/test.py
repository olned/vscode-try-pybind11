import try_pybind11_olned as m

assert m.__version__ == '0.0.3'
assert m.add(1, 2) == 3
assert m.subtract(1, 2) == -1
