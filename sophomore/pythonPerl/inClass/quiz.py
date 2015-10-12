# Write a recursive Python function concat_chars(char_lst) that takes a list of characters and concatenates them into a string. 
# For example:
# >>> concat_chars(['p', 'a', 'i', 'n', 't', 'e', 'r'])
# 'painter'
# >>> concat_chars(['g', 'e', 'o', 'm', 'e', 't', 'r', 'y'])
# 'geometry'



lst = ['S', 'o', 'm', 'e', 't', 'h', 'i', 'n', 'g']
print lst

def concat_char(char_lst):
	lst = ""
	for ch in char_lst:
		lst += ch
	print lst

concat_char(lst)

def concat_chars(char_lst):
	if char_lst == 0:
		return ''
	else:
		return char_lst[0] + concat_chars(char_lst[1:])


# concat_chars(lst)

# Problem 01
# Let lst be equal to ['a', 'b', 'c']. Use List operations to turn 
# lst into ['a', ['abc', 'efg'], 10, 'b', 'c', 20].

# Problem 02
# Let lst be equal to ['a', ['abc', 'efg'], 10, 'b', 'c', 20]. Use List
# operations to turn lst into ['a', ['abc'], 10, 'b', 20].


lst = ['a', 'b', 'c']
lst[1] = ['abc', 'efg']
lst[2] = 10
# lst[3] = 'b'
# lst[4] = 20

lst[1] = ['abc']


lst = ['a', 'b', 'c']
lst.insert(1, ['abc', 'efg'])
lst.insert(2, 10)
lst.append(20)

lst2 = ['a', ['abc', 'efg'], 10, 'b', 'c', 20]
del lst2[1][-1]
del lst2[-2]
