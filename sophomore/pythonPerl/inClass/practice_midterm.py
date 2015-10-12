# used to count the frequencies
import collections

def most_freq_chars(txt):
	counter = collections.Counter(txt)
	# print counter
	# print counter.values()
	# print counter.keys()
	# print counter.most_common()[0][0]
	# print max(counter.values())
	return counter.most_common()[0]

myList = [1,2,3,'a','v','a',1,2,3,'a','c']
myString = 'asdklfjaslkdjfalksdjflkasjdlfkj'
myOtherString = 'aaaaaaabbbcccccc'
print most_freq_chars(myOtherString)

# nested list sums

def nested_list_sum(n, sums=0):
	if not isinstance(n[0], list):
		return sums
	else:
		return nested_list_sum(n[1:], sums + n[0])

myList = [1, 2, [1, 2], 3, 4]
print nested_list_sum(myList)

print myList[4]
