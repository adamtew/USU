using namespace std;

pair<char, int> VALUES[26] = {
	make_pair('a', 1),
	make_pair('b', 3),
	make_pair('c', 3),
	make_pair('d', 2),
	make_pair('e', 1),
	make_pair('f', 4),
	make_pair('g', 2),
	make_pair('h', 4),
	make_pair('i', 1),
	make_pair('j', 8),
	make_pair('k', 5),
	make_pair('l', 1),
	make_pair('m', 3),
	make_pair('n', 1),
	make_pair('o', 1),
	make_pair('p', 3),
	make_pair('q', 10),
	make_pair('r', 1),
	make_pair('s', 1),
	make_pair('t', 1),
	make_pair('u', 1),
	make_pair('v', 4),
	make_pair('w', 4),
	make_pair('x', 8),
	make_pair('y', 4),
	make_pair('z', 20)
};

pair<int, int> LENGTHS[8] = {
	make_pair(1, 0),
	make_pair(2, 0),
	make_pair(3, 1),
	make_pair(4, 2),
	make_pair(5, 3),
	make_pair(6, 4),
	make_pair(7, 5),
	make_pair(8, 6)

};

pair<int, int> BONUS[10] = {
	make_pair(0, 5),
	make_pair(1, 4),
	make_pair(6, 3),
	make_pair(11, 2),
	make_pair(15, 1)
};

