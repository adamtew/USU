import django
import sqlite3 as light
print light.version

con = light.connect('/db.sqlite3')

with con:
	cur = con.cursor()
	# cur.execute('SELECT SQLITE_VERSION()')
	# cur.execute('SELECT name FROM sqlite_master WHERE type="table"')
	cur.execute('SELECT name FROM sqlite_master WHERE type=\'table\'');
	# cur.execute('CREATE TABLE Cars(Id INT, Name TEXT, Price INT)');
	# cur.execute('INSERT INTO Cars VALUES(1, \'Audi\', 52642)');
	# cur.execute('SELECT * FROM cars')
	print (cur.fetchall());
	# print cur.fetchone();
	# print cur

con.close();

import sys
sys.path = sys.path[1:]
import django
print (django.__path__)