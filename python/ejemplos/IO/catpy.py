import sys

filenames = sys.argv[1:]

for fn in filenames:
    with open(fn, 'r') as f:
        read_data = f.read()
    print(read_data)
