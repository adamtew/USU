# Huffman Trees with lists and tuples
# variable-length vs. fixed length
# David huffman: 00001111 = 0414

# Huffman tree:
# def make_leaf(symbol, weight):
# 	return (symbol, weight)

# def is_leaf(x):
# 	return isinstance(x, tuple) and \
# 	len(x) == 2 and\
# 	isinstance(x[0], str) and \
# 	isinstance(x[1], int)

# def get_leaf_symbol():
# 	return leaf[0]

# def get_leaf_freq(leaf):
# 	return leaf[1]

# def get_left_branch(huff_tree):
# 	return huff_tree[0]

# def get_right_branch(huff_tree):
# 	return huff_tree[1]

# def get_symbols(huff_tree):
# 	if is_leaf(huff_tree):
# 		return get_leaf_symbol(huff_tree)
# 	else:
# 		return huff_tree[2]

# def get_freq(huff_tre):
# 	if is_leaf(huff_tree):
# 		return get_leaf_freq(huff_tree)
# 	else:
# 		return huff_tree[3]

# def make_huffman_tree(left_branch, right_branch):
# 	return (left_branch,
# 		right_branch,
# 		get_symbols(left_branch) + get_symbols(right_branch),
# 	get_freq(left_branch) + get_freq(right_branch))

# ht01 = make_huffman_tree(make_leaf('A', 4),
# 	make_huffman_tree(make_leaf('B', 2),
# 		make_huffman_tree(make_leaf('D', 1),
# 			make_leaf('C', 1))))

# print ht01

# Decoding huffman trees

# Set-former notation
# {4 * x | x E N, x^2 < 100}

rslt = []
for x in xrange(201):
	if x ** 2 < 100:
		rslt.append(x)
print rslt

s = [4 * x for x in xrange(201) if x **2 < 100]
print s

for i in[1, 2, 3]:print i
print i + 1

